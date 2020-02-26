import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    visible: true
    width: 640
    height: 480
    property int getValue: -1

    Rectangle {
        width: 400
        height: 100
        color: "yellow"
        Text {
            id: testTxt
            text: "Proxy : " + getValue
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("value check :" , MyQuickItemProxy.testValue)
            }
        }

    }

    Connections {
        target: MyQuickItemProxy
        onTestValueChanged: {
            console.log("[onTestValueChanged] value : " , value)
            getValue = value;
        }
    }


}
