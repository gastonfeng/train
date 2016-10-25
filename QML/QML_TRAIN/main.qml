//http://blog.csdn.net/foruok/article/details/46839569
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Window 2.2

Window {
    title: "StackViewDemo"
    width: 4096
    height: 2304
    visible: true

    StackView {
        id: stack
        anchors.fill: parent
        //width: 600;
        //height: 300;
        property var home: null

        pushEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: 100
            }
        }
        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to: 0
                duration: 100
            }
        }
        popEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: 100
            }
        }
        popExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to: 0
                duration: 100
            }
        }
        Text {
            text: "Click to create first page"
            font.pointSize: 14
            font.bold: true
            color: "blue"
            anchors.centerIn: parent
            MouseArea {
                anchors.fill: parent
                onClicked: if (stack.depth == 0)
                               stack.push(page)
            }
        }
    }

    Component {
        id: page

        Rectangle {
            color: Qt.rgba(stack.depth * 0.1, stack.depth * 0.2,
                           stack.depth * 0.3)
            Image {
                anchors.fill: parent
            }

            Text {
                anchors.centerIn: parent
                text: "depth - " + stack.depth
                font.pointSize: 24
                font.bold: true
                color: stack.depth <= 4 ? Qt.lighter(parent.color) : Qt.darker(
                                              parent.color)
            }

            Button {
                id: next
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.margins: 8
                text: "Next"
                width: 70
                height: 30
                onClicked: {
                    if (stack.depth < 8) {
                        if (stack.depth == 1) {
                            stack.initialItem = stack.push(page)
                        } else if (stack.depth == 2) {
                            stack.home = stack.push(page)
                        }
                        else
                        stack.push(page)
                    }
                }
            }

            Button {
                id: back
                anchors.right: next.left
                anchors.top: next.top
                anchors.rightMargin: 8
                text: "Back"
                width: 70
                height: 30
                onClicked: {
                    if (stack.depth > 0)
                        stack.pop()
                }
            }

            Button {
                id: home
                anchors.right: back.left
                anchors.top: next.top
                anchors.rightMargin: 8
                text: "Home"
                width: 70
                height: 30
                onClicked: {
                    if (stack.depth > 0)
                        stack.pop(stack.initialItem)
                }
            }

            Button {
                id: clear
                anchors.right: home.left
                anchors.top: next.top
                anchors.rightMargin: 8
                text: "Clear"
                width: 70
                height: 30
                onClicked: {
                    if (stack.depth > 0)
                        stack.clear()
                }
            }
            Button {
                id: to
                anchors.right: clear.left
                anchors.top: next.top
                anchors.rightMargin: 10
                text: "TWO"
                width: 70
                height: 30
                onClicked: {
                    if (stack.depth > 0)
                        stack.pop(stack.home)
                }
            }
        }
    }
}
