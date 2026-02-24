Sensor @ 1000 Hz
        |
        v
+---------------+
|  Filtering    |  ~200 Hz
+---------------+
        |
        v
+-----------------------+
|  Aggregation          |  ~30 Hz (UI-friendly)
+-----------------------+
        |
        v
ViewModel  ->  QML UI
