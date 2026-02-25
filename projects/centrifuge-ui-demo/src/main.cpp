#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "rpm_viewmodel.h"
#include "centrifuge_controller.h"
#include "hal_factory.h"
#include "hal_interface.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    HalFactory::instance().start();
    HalInterface* hal = HalFactory::instance().hal();

    CentrifugeController controller(hal);
    RpmViewModel vm(&controller);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("rpmVM", &vm);

    const QUrl url(u"qrc:/Centrifuge/qml/Main.qml"_qs);
    engine.load(url);

    const int rc = app.exec();
    HalFactory::instance().stop();
    return rc;
}
