
# Centrifuge UI Demo  
### A Qt/QML + C++ MVVM Embedded HMI Architecture Example

This project demonstrates a clean **HMI architecture** for an embedded centrifuge device.  
It uses:

- Qt/QML for UI  
- C++ for backend logic  
- A threaded HAL (Hardware Abstraction Layer)  
- MVVM pattern  
- Safety-aware design (Alarm → Lockout → Manual reset)  
- Reusable architecture for medical/industrial devices  

This project is part of my **HMI Architect Portfolio**, showing how I design **modular**, **safe**, and **scalable** UIs for embedded systems.

---
---> CMakeLists.txt — Build Configuration

What it sets up:

C++17
Requires Qt 6.5 with Quick and Qml
Builds C++ sources into an executable
Registers a QML module Centrifuge 1.0 with the QML files
Links against Qt6::Quick and Qt6::Qml


Why qt_add_qml_module matters:
It registers your QML under the URI Centrifuge, allowing Main.qml to be loaded via qrc:/Centrifuge/qml/Main.qml.

---
---> ## Prerequisites

Qt 6.5+ (components: Qt Quick, Qt Qml)
CMake 3.16+
A C++17 compiler:

Windows: MSVC (via Visual Studio or Build Tools), or MinGW
--->  Qt Creator (easiest)

Open Qt Creator.
File → Open File or Project… → select CMakeLists.txt.
Choose a Qt 6.5 kit.
Click Configure Project.
Click Build, then Run.
