#pragma once
enum class CentrifugeState {
    Idle,
    Running,
    Alarm
};
static inline const char* toString(CentrifugeState s) {
    switch (s) {
        case CentrifugeState::Idle:    return "Idle";
        case CentrifugeState::Running: return "Running";
        case CentrifugeState::Alarm:   return "Alarm";
    }
    return "Unknown";
}
