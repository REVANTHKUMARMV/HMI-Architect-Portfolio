User
 │
 ▼
┌──────────────┐     invoke()      ┌──────────────┐     request     ┌─────────────┐
│   QML View   │ ───────────────▶  │ ViewModel    │ ─────────────▶  │  Backend    │
│ (UI Thread)  │                   │ (C++)        │                 │   (C++)     │
└──────▲───────┘                   └─────▲────────┘                 └──────▲─────┘
       │   notify property              │ signals                          │ data update
       └────────────────────────────────┴──────────────────────────────────┘

User → QML UI → ViewModel → Backend → Device
        ↑          ↑           |
        |          |           v
       updates <--- props <--- signals
