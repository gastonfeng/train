//from :http://www.cnblogs.com/L-Arikes/p/4380382.html
import QtQuick 2.0
import QtQuick.Window 2.0

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

        WorkerScript {
            id: myWorker
            source: "script.js"

            onMessage: myText.text = messageObject.reply
        }

        Timer {
            interval: 1000
            running: true
            repeat: true
            property int index: 0
            onTriggered: {
                index = index + 1
                myWorker.sendMessage({
                                         tmr: index,
                                         x:0,
                                         y:0
                                     })
            }
        }

        MouseArea {
            id: mou
            anchors.fill: parent
            onClicked: myWorker.sendMessage({
                                                tmr:'没有',
                                                x: mouse.x,
                                                y: mouse.y
                                            })
        }
    }
}
