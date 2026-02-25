import QtQuick

Item {
    id: root
    property int current: 0
    property int max: 15000
    width: 220
    height: 220

    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {
            const ctx = getContext("2d");
            const w = width, h = height;
            const cx = w/2, cy = h/2;
            const r = Math.min(w,h)/2 - 12;

            ctx.clearRect(0, 0, w, h);
            const pct = Math.max(0, Math.min(1, root.current / root.max));

            const start = Math.PI * 0.75;
            const end   = Math.PI * 0.25;

            ctx.lineWidth = 14;

            ctx.strokeStyle = "#333";
            ctx.beginPath();
            ctx.arc(cx, cy, r, start, end, false);
            ctx.stroke();

            ctx.strokeStyle = "#00c853";
            ctx.beginPath();
            ctx.arc(cx, cy, r, start, start + pct * (end - start), false);
            ctx.stroke();

            ctx.fillStyle = "#e0e0e0";
            ctx.font = "bold 18px Sans-Serif";

            const rpmText = root.current + " rpm";
            const tw = ctx.measureText(rpmText).width;
            ctx.fillText(rpmText, cx - tw/2, cy + 8);
        }

        Connections {
            target: root
            function onCurrentChanged() { canvas.requestPaint(); }
            function onMaxChanged()     { canvas.requestPaint(); }
        }
    }
}
