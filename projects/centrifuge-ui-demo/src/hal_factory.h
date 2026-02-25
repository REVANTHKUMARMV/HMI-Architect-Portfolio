#pragma once
#include <QObject>
#include <QThread>

class HalInterface;

class HalFactory : public QObject {
    Q_OBJECT
public:
    static HalFactory& instance();
    HalInterface* hal() const { return _hal; }

    void start();
    void stop();

private:
    explicit HalFactory(QObject* parent = nullptr);
    ~HalFactory();

    QThread _thread;
    HalInterface* _hal{nullptr};
    bool _running{false};
};
