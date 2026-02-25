#include "hal_factory.h"
#include "hal_interface.h"
#include "hal_sim.h"
#include <QCoreApplication>
#include <QMetaObject>

HalFactory& HalFactory::instance() {
    static HalFactory f;
    return f;
}

HalFactory::HalFactory(QObject* parent)
    : QObject(parent)
{
    connect(qApp, &QCoreApplication::aboutToQuit, this, &HalFactory::stop);
}

HalFactory::~HalFactory() {
    stop();
}

void HalFactory::start() {
    if (_running) return;

    _hal = new HalSim();
    _hal->moveToThread(&_thread);
    connect(&_thread, &QThread::finished, _hal, &QObject::deleteLater);

    _thread.setObjectName("HalWorker");
    _thread.start();

    QMetaObject::invokeMethod(_hal, "start", Qt::QueuedConnection);
    _running = true;
}

void HalFactory::stop() {
    if (!_running) return;

    if (_hal) {
        QMetaObject::invokeMethod(_hal, "stop", Qt::QueuedConnection);
    }

    _thread.quit();
    _thread.wait();
    _hal = nullptr;
    _running = false;
}
