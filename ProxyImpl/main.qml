//import QtQuick 2.12
//import QtQuick.Window 2.12

//Item {
//    visible: true
//    width: 640
//    height: 480
//    property int getValue: -1

//    Rectangle {
//        width: 400
//        height: 100
//        color: "yellow"
//        Text {
//            id: testTxt
//            text: "Proxy : " + getValue
//        }

//        MouseArea{
//            anchors.fill: parent
//            onClicked: {
//                console.log("value check :" , MyQuickItemProxy.testValue)
//            }
//        }

//    }

//    Connections {
//        target: MyQuickItemProxy
//        onTestValueChanged: {
//            console.log("[onTestValueChanged] value : " , value)
//            getValue = value;
//        }
//    }




//}

import QtQuick 2.0
import OpenGLUnderQML 1.0

Item {
    width: 1000
    height: 1000

    Squircle {
        x : 0
        y : 0
        width: 512
        height: 512
       // rotation: 30
        ///scale : 1.2
        texture : ":/wall.jpg"

//        SequentialAnimation on t {
//            NumberAnimation { to: 1; duration: 2500; easing.type: Easing.InQuad }
//            NumberAnimation { to: 0; duration: 2500; easing.type: Easing.OutQuad }
//            loops: Animation.Infinite
//            running: true
//        }
    }

    property  int getValue: -1
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
