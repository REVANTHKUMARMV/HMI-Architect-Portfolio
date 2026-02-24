
 MVVM Data Flow

This diagram explains how data moves from UI → ViewModel → Backend → Hardware and back.  
QML never holds safety-critical logic; it only visualizes state.

## Technical Style (C)

```text
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
