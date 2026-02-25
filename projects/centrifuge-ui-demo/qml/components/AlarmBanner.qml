import QtQuick

Rectangle {
    id: banner
    visible: false
    height: visible ? 36 : 0
    width: parent ? parent.width : 400
    color: "#b00020"

    Text {
        anchors.centerIn: parent
        text: "ALARM: Safety lockout active"
        color: "white"
        font.bold: true
        font.pixelSize: 14
    }
}
