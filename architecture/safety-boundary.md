
+-------------------+
|       QML         |   <- UI ONLY (no safety logic)
+---------+---------+
          |  properties / invokables
          v
+-------------------+
|     C++ Core      |   <- safety logic, validation, state machine
+---------+---------+
          |  validated commands
          v
+-------------------+
|   HAL / Drivers   |   <- real hardware
+-------------------+
