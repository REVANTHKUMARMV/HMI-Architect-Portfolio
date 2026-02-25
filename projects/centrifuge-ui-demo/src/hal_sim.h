#pragma once
#include "hal_interface.h"
#include <QTimer>

class HalSim : public HalInterface {
    Q_OBJECT
public:
    explicit HalSim(QObject* parent = nullptr);

public slots:
    void start();
    void stop();
    void setMotorEnabled(bool on) override;
    void setTargetRpm(int rpm) override;
    void clearFault() override;

private slots:
    void onTick();

private:
    QTimer _tick;
    bool _enabled{false};
    int  _targetRpm{0};
    int  _currentRpm{0};
    bool _fault{false};
    const int _maxSafeRpm{15000};
};
