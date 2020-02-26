import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    visible: true
    width: 640
    height: 480

    Rectangle{
        width: 100
        height: 100
        color: "red"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("@@@@@@@@@")
                MyQuickItemStub.testValue = MyQuickItemStub.testValue + 1
                MyQuickItemStub.testFunction(MyQuickItemStub.testValue)
                console.log("MyQuickItemStub.testValue :" , MyQuickItemStub.testValue)
            }
        }
    }

}
