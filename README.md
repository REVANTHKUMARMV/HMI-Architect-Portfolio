# HMI-Architect-Portfolio
“Reusable Qt/QML components, MVVM patterns, and embedded HMI architecture examples.”
A curated portfolio showcasing my work, thinking, and architectural approach to building embedded HMI/GUI systems using Qt/QML, C++, and Embedded Linux.
This repository reflects my journey toward becoming a full HMI Architect for medical‑grade devices.

About This Portfolio
This repository contains:

Real Qt/QML + C++ projects
Architecture patterns (MVVM, component libraries, state machines)
Real‑time data handling examples
Performance optimization techniques
Safety‑critical UI design principles
Interview preparation materials
My personal architecture story & pitch
It is designed to demonstrate not just what I build, but how I think as an HMI architect.


HMI-Architect-Portfolio/
│
├── projects/
│   ├── centrifuge-ui-demo/
│   ├── incubator-ui-demo/
│   ├── qml-component-library/
│   └── threaded-backend-example/
│
├── architecture/
│   ├── hmi-architecture-overview.md
│   ├── mvvm-pattern-in-qt.md
│   ├── real-time-data-handling.md
│   ├── performance-optimization.md
│   └── safety-critical-ui-design.md
│
│
├── portfolio/
│   ├── portfolio-story.md
│   ├── final-pitch.md
│   └── bullet-points.md
│
└── README.md

I design HMIs that are:
  Modular
  Testable
  Safe
  Reusable across product lines
  Maintainable for 10+ years


My core rule:
Safety‑critical logic never lives in QML.
The UI is a visual layer only — all validation and state transitions happen in C++.

 Key Topics Covered
✔ Qt/QML Architecture
   MVVM
   Component libraries
   Navigation patterns
   State machines

✔ Embedded Systems
  Threaded backends
  Real‑time data
  Hardware abstraction
  Safety boundaries

✔ Performance
  Scene graph optimization
  Lazy loading
  Reducing overdraw

Profiling with Qt Quick Profiler

 Badges
![Qt](https://img.shields.io/badge/Qt-6.0+-green)
![C++](https://img.shields.io/badge/C++-17-blue)
![QML](https://img.shields.io/badge/QML-Expert-orange)
![Architecture](https://img.shields.io/badge/Architecture-HMI%20Design-purple)
![Platform](https://img.shields.io/badge/Platform-Embedded%20Linux-lightgrey)


Architecture Diagram(Planned)


+-----------------------------+
|        QML UI Layer         |
|  Screens, Components, UX    |
+-------------+---------------+
              |
              v
+-----------------------------+
|      ViewModel Layer        |
|  Q_PROPERTY, Signals, API   |
+-------------+---------------+
              |
              v
+-----------------------------+
|     Backend Logic (C++)     |
|  State Machine, Validation  |
+-------------+---------------+
              |
              v
+-----------------------------+
|   Hardware / Device Layer   |
| Sensors, Motors, Safety     |
+-----------------------------+

 Projects
1. Centrifuge UI Demo
A Qt/QML interface demonstrating real‑time RPM updates, MVVM architecture, and safety‑aware UI flows.

2. Incubator UI Demo
A multi‑screen embedded UI with temperature control, alarms, and threaded backend communication.

3. QML Component Library
Reusable buttons, sliders, indicators, dialogs, and layout primitives for embedded HMIs.

4. Threaded Backend Example
A demonstration of worker threads, queued connections, and real‑time data pipelines.


 ##Contact
If you want to collaborate or discuss HMI architecture, feel free to reach out via Linkedin or email - revanthkumar.skht@gmail.com
