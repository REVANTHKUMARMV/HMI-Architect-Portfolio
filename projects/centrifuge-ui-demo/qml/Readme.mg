---
---> qml/components/RpmGauge.qml — Canvas RPM Dial

What it does:
Draws a semicircular arc with a green progress segment proportional to current / max. Paints text like “4350 rpm”.
How it updates:
Listens to current / max changes and calls canvas.requestPaint().


---> qml/components/AlarmBanner.qml — Red Safety Banner

What it does:
Draws a red bar with the text: “ALARM: Safety lockout active”.
visible is controlled from Main.qml.
Why it matters:
Immediately signals to the operator that the machine is in a lockout state.


---> qml/Main.qml — Main UI

What it contains:

Loads the AlarmBanner + RpmGauge components.
Slider to choose target RPM.
Buttons: Start, Stop, Clear Fault.
Overlay that blocks interaction during lockout.


How it reacts:
Uses Connections to rpmVM to update gauge, banner, and overlay based on fault and state.
Who it talks to:
Calls rpmVM.cmdStart(...), .cmdStop(), .cmdClearFault().
---
