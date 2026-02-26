---
SRC description of each file and why we need those files and how its connected in the Program ?

src/
    sm_types.h
    hal_interface.h
    hal_sim.h
    hal_sim.cpp
    hal_factory.h
    hal_factory.cpp
    centrifuge_controller.h
    centrifuge_controller.cpp
    rpm_viewmodel.h
    rpm_viewmodel.cpp
    main.cpp
---    
---> src/sm_types.h — State Machine Types

What it defines:
An enum CentrifugeState { Idle, Running, Alarm } and a helper toString() to convert states to readable strings.
Who uses it:
CentrifugeController (state logic), RpmViewModel (exposes readable state to QML), and QML displays the state.
Why it matters:
This is the single source of truth for the centrifuge’s high-level state.

---
---> src/hal_interface.h — Abstract Hardware Interface

What it defines:
A pure-virtual QObject class with:

slots: setMotorEnabled(bool), setTargetRpm(int), clearFault()
signals: currentRpmChanged(int), faultChanged(bool)


Who implements it:
HalSim (the simulated hardware).
Who consumes it:
CentrifugeController talks to HalInterface, not HalSim → makes it easy to swap with real hardware later.
Why it matters:
Decouples business logic from hardware specifics.

---
---> src/hal_sim.h/.cpp — Simulated Hardware (HAL)

What it does:

Runs a 50 Hz timer (20 ms interval).
Smoothly ramps _currentRpm toward _targetRpm.
Emits currentRpmChanged(rpm) each tick.
If a target > _maxSafeRpm (15000), raises faultChanged(true) and locks out until clearFault().
If faulted, it coasts down the RPM.


Who talks to it:
CentrifugeController calls setTargetRpm, setMotorEnabled.
UI indirectly receives updates via ViewModel.
Why it runs in its own thread:
So the UI stays buttery smooth and never blocks.

---
--->  src/hal_factory.h/.cpp — HAL Singleton + Worker Thread

What it does:

Creates one HAL instance (HalSim for now).
Moves it to a QThread named "HalWorker".
Controls lifecycle via start() / stop() (also tied to app quit).


Who uses it:
main.cpp asks the factory to start the HAL and returns a HalInterface*.
Why it matters:
This ensures the hardware layer runs off the UI thread and is cleanly started/stopped.

---
--->  src/centrifuge_controller.h/.cpp — The Brain (State Machine + Safety)

What it does:

Validates target RPM (0–15000).
Provides commands: start(rpm), stop(), clearFault().
Listens to HAL signals and reacts to faults by stopping and entering Alarm state.
Emits stateChanged, targetRpmChanged, currentRpmUpdated, faultActive.


Who uses it:
The ViewModel subscribes to these signals and forwards data to QML.
Why it matters:
It encapsulates safe transitions:
Idle → Running → Alarm (lockout), and enforces safety rules.

---
---> src/rpm_viewmodel.h/.cpp — MVVM: ViewModel for QML

What it exposes to QML (properties):

currentRpm (int)
targetRpm (int)
state (QString: “Idle”, “Running”, “Alarm”)
fault (bool)


Commands QML can call (invokables):

cmdStart(int rpm)
cmdStop()
cmdClearFault()


What it listens to:
Controller signals → updates internal fields → emits QML property change signals.
Why it matters:
Keeps QML declarative and clean; all logic stays in C++.

---
---> src/main.cpp — App Bootstrap

What it does:
Start Qt app

Start HAL factory → get HalInterface*
Create Controller + ViewModel
Expose ViewModel to QML context (rpmVM)
Load qrc:/Centrifuge/qml/Main.qml (provided by qt_add_qml_module)
Run event loop
Stop HAL on exit


Why it matters:
Wires the backend and frontend together in a clean, minimal way.  

---
