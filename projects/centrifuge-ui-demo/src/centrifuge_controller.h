#pragma once
#include <QObject>
#include "sm_types.h"

class HalInterface;

class CentrifugeController : public QObject {
    Q_OBJECT
public:
    explicit CentrifugeController(HalInterface* hal, QObject* parent = nullptr);

    CentrifugeState state() const { return _state; }
    int targetRpm() const { return _targetRpm; }

public slots:
    void start(int rpm);
    void stop();
    void clearFault();

signals:
    void stateChanged(CentrifugeState s);
    void targetRpmChanged(int rpm);
    void currentRpmUpdated(int rpm);
    void faultActive(bool active);

private slots:
    void onHalRpm(int rpm);
    void onHalFault(bool on);

private:
    bool validateTarget(int rpm) const;
    void transitionTo(CentrifugeState s);

private:
    HalInterface* _hal{nullptr};
    CentrifugeState _state{CentrifugeState::Idle};
    int _targetRpm{0};
    bool _fault{false};
};
