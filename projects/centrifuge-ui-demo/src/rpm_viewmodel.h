#pragma once
#include <QObject>
#include "sm_types.h"

class CentrifugeController;

class RpmViewModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(int currentRpm READ currentRpm NOTIFY currentRpmChanged)
    Q_PROPERTY(int targetRpm  READ targetRpm  NOTIFY targetRpmChanged)
    Q_PROPERTY(QString state  READ state      NOTIFY stateChanged)
    Q_PROPERTY(bool fault     READ fault      NOTIFY faultChanged)

public:
    explicit RpmViewModel(CentrifugeController* controller, QObject* parent = nullptr);

    int currentRpm() const { return _currentRpm; }
    int targetRpm()  const { return _targetRpm; }
    QString state()  const { return QString::fromUtf8(toString(_state)); }
    bool fault()     const { return _fault; }

    Q_INVOKABLE void cmdStart(int rpm);
    Q_INVOKABLE void cmdStop();
    Q_INVOKABLE void cmdClearFault();

signals:
    void currentRpmChanged();
    void targetRpmChanged();
    void stateChanged();
    void faultChanged();

private slots:
    void onBackendRpm(int rpm);
    void onBackendTarget(int rpm);
    void onBackendState(CentrifugeState s);
    void onBackendFault(bool on);

private:
    CentrifugeController* _controller{nullptr};
    int _currentRpm{0};
    int _targetRpm{0};
    CentrifugeState _state{CentrifugeState::Idle};
    bool _fault{false};
};
