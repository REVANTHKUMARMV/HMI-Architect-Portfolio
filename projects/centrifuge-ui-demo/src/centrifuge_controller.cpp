#include "centrifuge_controller.h"
#include "hal_interface.h"
#include <QtGlobal>

CentrifugeController::CentrifugeController(HalInterface* hal, QObject* parent)
    : QObject(parent), _hal(hal)
{
    connect(_hal, &HalInterface::currentRpmChanged,
            this, &CentrifugeController::onHalRpm, Qt::QueuedConnection);

    connect(_hal, &HalInterface::faultChanged,
            this, &CentrifugeController::onHalFault, Qt::QueuedConnection);
}

bool CentrifugeController::validateTarget(int rpm) const {
    return rpm >= 0 && rpm <= 15000;
}

void CentrifugeController::start(int rpm) {
    if (_fault) return;
    if (!validateTarget(rpm)) return;

    _targetRpm = rpm;
    emit targetRpmChanged(_targetRpm);

    _hal->setTargetRpm(_targetRpm);
    _hal->setMotorEnabled(true);

    transitionTo(CentrifugeState::Running);
}

void CentrifugeController::stop() {
    _hal->setMotorEnabled(false);
    _hal->setTargetRpm(0);

    _targetRpm = 0;
    emit targetRpmChanged(0);

    transitionTo(CentrifugeState::Idle);
}

void CentrifugeController::clearFault() {
    if (!_fault) return;

    _hal->clearFault();
    _fault = false;

    emit faultActive(false);
    transitionTo(CentrifugeState::Idle);
}

void CentrifugeController::onHalRpm(int rpm) {
    emit currentRpmUpdated(rpm);
}

void CentrifugeController::onHalFault(bool on) {
    if (on) {
        _fault = true;
        emit faultActive(true);

        _hal->setMotorEnabled(false);
        _hal->setTargetRpm(0);

        transitionTo(CentrifugeState::Alarm);
    }
}

void CentrifugeController::transitionTo(CentrifugeState s) {
    if (_state == s) return;

    _state = s;
    emit stateChanged(_state);
}
