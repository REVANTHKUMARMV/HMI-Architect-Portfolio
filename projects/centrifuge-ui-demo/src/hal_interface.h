#pragma once
#include <QObject>

class HalInterface : public QObject {
    Q_OBJECT
public:
    using QObject::QObject;
    virtual ~HalInterface() = default;

public slots:
    virtual void setMotorEnabled(bool on) = 0;
    virtual void setTargetRpm(int rpm) = 0;
    virtual void clearFault() {} // default no-op

signals:
    void currentRpmChanged(int rpm);
    void faultChanged(bool faultActive);
};
