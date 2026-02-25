#include "hal_sim.h"
#include <QtGlobal>

HalSim::HalSim(QObject* parent)
    : HalInterface(parent) {
    _tick.setInterval(20);
    connect(&_tick, &QTimer::timeout, this, &HalSim::onTick);
}

void HalSim::start() { if (!_tick.isActive()) _tick.start(); }
void HalSim::stop()  { if (_tick.isActive()) _tick.stop();  }

void HalSim::setMotorEnabled(bool on) {
    _enabled = on;
    if (!on) _targetRpm = 0;
}

void HalSim::setTargetRpm(int rpm) {
    _targetRpm = rpm;
}

void HalSim::clearFault() {
    if (_fault) {
        _fault = false;
        emit faultChanged(false);
    }
}

void HalSim::onTick() {
    if (_fault) {
        if (_currentRpm > 0) _currentRpm -= qMax(50, _currentRpm / 10);
        else _currentRpm = 0;
        emit currentRpmChanged(_currentRpm);
        return;
    }

    if (_targetRpm > _maxSafeRpm) {
        _fault = true;
        emit faultChanged(true);
        return;
    }

    const int target = _enabled ? _targetRpm : 0;
    const int delta = target - _currentRpm;
    const int step = qBound(-500, delta / 4, 500);

    _currentRpm += step;
    if (_currentRpm < 0) _currentRpm = 0;

    emit currentRpmChanged(_currentRpm);
}
