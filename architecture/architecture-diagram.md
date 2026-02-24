# Architecture Diagram (ASCII)
```
+-----------------------------+
|       QML UI Layer         |
|  Screens, Components, UX   |
+-------------+---------------+
|
v
+-----------------------------+
|      ViewModel Layer       |
|   Q_PROPERTY, Signals, API |
+-------------+---------------+
|
v
+-----------------------------+
|      Backend Logic (C++)   |
| State Machine, Validation  |
+-------------+---------------+
|
v
+-----------------------------+
|   Hardware / Device Layer  |
| Sensors, Motors, Safety    |
+-----------------------------+
```
