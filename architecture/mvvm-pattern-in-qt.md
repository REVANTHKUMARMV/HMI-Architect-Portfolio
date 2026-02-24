---

## 2) **MVVM Data Flow (Signals/Slots, Properties, Commands)**  
**File:** `architecture/mvvm-pattern-in-qt.md`

```markdown
# MVVM Pattern in Qt/QML

```mermaid
sequenceDiagram
  autonumber
  participant U as User
  participant Q as QML View (UI Thread)
  participant VM as ViewModel (C++)
  participant BL as Backend / Model (C++)
  participant H as HAL / Device

  U->>Q: Interact (tap slider, press button)
  Q->>VM: call Q_INVOKABLE setTargetRpm(int)
  VM->>BL: requestSetpoint(targetRpm)
  BL->>H: writeCommand(setpoint)
  H-->>BL: ack / currentRpm
  BL-->>VM: signal currentRpmChanged(int)
  VM-->>Q: Q_PROPERTY currentRpm emits notify
  Q-->>U: UI updates (needle, label)

  Note over Q,VM: UI reads Q_PROPERTYs, never calls hardware directly
  Note over VM,BL: Queued connections isolate threads when needed
  Note over BL,H: Validation + safety checks occur here
