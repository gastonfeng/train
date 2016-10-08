//from :http://www.cnblogs.com/L-Arikes/p/4380382.html
import QtQuick 2.0
import QtQuick.Window 2.0
import Controller 1.0

Window {
    width: 800
    height: 600
    visible: true
    Rectangle {
        width: 300
        height: 300

        Text {
            id: myText
            text: 'Click anywhere'
        }

        Controller {
            id: myWorker

            onResult: myText.text = result
        }

        Timer {
            interval: 1000
            running: true
            repeat: true
            property int index: 0
            onTriggered: {
                index = index + 1
                myWorker.operate('{ operate }')
            }
        }

        MouseArea {
            id: mou
            anchors.fill: parent
            onClicked: myWorker.operate('{ onClicked }')
        }
    }
}
