#include "rpm_viewmodel.h"
#include "centrifuge_controller.h"

RpmViewModel::RpmViewModel(CentrifugeController* controller, QObject* parent)
    : QObject(parent), _controller(controller)
{
    connect(_controller, &CentrifugeController::currentRpmUpdated,
            this, &RpmViewModel::onBackendRpm);

    connect(_controller, &CentrifugeController::targetRpmChanged,
            this, &RpmViewModel::onBackendTarget);

    connect(_controller, &CentrifugeController::stateChanged,
            this, &RpmViewModel::onBackendState);

    connect(_controller, &CentrifugeController::faultActive,
            this, &RpmViewModel::onBackendFault);
}

void RpmViewModel::cmdStart(int rpm) {
    _controller->start(rpm);
}

void RpmViewModel::cmdStop() {
    _controller->stop();
}

void RpmViewModel::cmdClearFault() {
    _controller->clearFault();
}

void RpmViewModel::onBackendRpm(int rpm) {
    if (_currentRpm == rpm) return;
    _currentRpm = rpm;
    emit currentRpmChanged();
}

void RpmViewModel::onBackendTarget(int rpm) {
    if (_targetRpm == rpm) return;
    _targetRpm = rpm;
    emit targetRpmChanged();
}

void RpmViewModel::onBackendState(CentrifugeState s) {
    if (_state == s) return;
    _state = s;
    emit stateChanged();
}

void RpmViewModel::onBackendFault(bool on) {
    if (_fault == on) return;
    _fault = on;
    emit faultChanged();
}
