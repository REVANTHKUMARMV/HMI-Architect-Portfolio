# HMI Architecture Overview

```mermaid
flowchart TB
  %% LAYERS
  subgraph UI["QML UI Layer"]
    Screens["Screens / Pages"]
    Components["Reusable Components"]
    UX["UX Behaviors / Animations"]
  end

  subgraph VM["ViewModel Layer (C++)"]
    API["Q_PROPERTY / Q_INVOKABLE API"]
    Signals["Signals / Slots (Qt)"]
    Rules["UI-Oriented Rules (Non-Safety)"]
  end

  subgraph BL["Backend Logic (C++)"]
    SM["State Machine (QScxml / custom)"]
    Validation["Validation & Business Logic"]
    Repo["Data Repository / Cache"]
  end

  subgraph HAL["Hardware / Device Layer"]
    Drivers["Drivers / IO"]
    Sensors["Sensors"]
    Actuators["Motors / Actuators"]
    Safety["Safety Interlocks & Watchdogs"]
  end

  %% FLOW
  UI --> VM
  VM --> BL
  BL --> HAL

  %% RETURN PATHS
  HAL --> BL
  BL --> VM
  VM --> UI

  %% SAFETY NOTE
  classDef danger fill:#ffefef,stroke:#e33,stroke-width:1px,color:#a00;
  Note1{{"⚠️ Safety-critical logic lives **only** in C++ (Backend/HAL).<br/>QML is strictly visual."}}
  Note1:::danger
  Note1 -. anchored .- BL
  Note1 -. anchored .- HAL
  Note1 -. anchored .- HAL
