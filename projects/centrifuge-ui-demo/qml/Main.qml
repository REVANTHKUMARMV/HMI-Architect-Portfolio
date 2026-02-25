import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Centrifuge 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: "Centrifuge UI Demo"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 12
        spacing: 12

        Loader {
            id: bannerLoader
            source: "components/AlarmBanner.qml"
            Layout.fillWidth: true

            onLoaded: {
                item.visible = rpmVM.fault || rpmVM.state === "Alarm"
            }
        }

        Loader {
            id: gaugeLoader
            source: "components/RpmGauge.qml"
            Layout.alignment: Qt.AlignHCenter

            onLoaded: {
                item.current = rpmVM.currentRpm
                item.max = 15000
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 20

            Text { text: "State: " + rpmVM.state; font.pixelSize: 18 }
            Text { text: "Fault: " + (rpmVM.fault ? "YES" : "no"); font.pixelSize: 18 }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 8

            Slider {
                id: rpmSlider
                from: 0; to: 15000; stepSize: 100
                width: 360
            }

            Text { text: Math.round(rpmSlider.value) + " rpm"; font.pixelSize: 16 }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 10

            Button {
                text: "Start"
                enabled: !rpmVM.fault && rpmVM.state !== "Alarm"
                onClicked: rpmVM.cmdStart(Math.round(rpmSlider.value))
            }

            Button {
                text: "Stop"
                onClicked: rpmVM.cmdStop()
            }

            Button {
                text: "Clear Fault"
                enabled: rpmVM.fault || rpmVM.state === "Alarm"
                onClicked: rpmVM.cmdClearFault()
            }
        }

        Rectangle {
            anchors.fill: parent
            color: "#80000000"
            visible: rpmVM.fault || rpmVM.state === "Alarm"
            z: 100

            MouseArea { anchors.fill: parent }

            Text {
                anchors.centerIn: parent
                color: "white"
                font.pixelSize: 18
                text: "LOCKOUT: Clear fault to continue"
            }
        }
    }

    Connections {
        target: rpmVM

        function onCurrentRpmChanged() {
            if (gaugeLoader.item)
                gaugeLoader.item.current = rpmVM.currentRpm
        }

        function onFaultChanged() {
            if (bannerLoader.item)
                bannerLoader.item.visible = rpmVM.fault
        }

        function onStateChanged() {
            if (bannerLoader.item)
                bannerLoader.item.visible =
                    rpmVM.fault || rpmVM.state === "Alarm"
        }
    }
}

