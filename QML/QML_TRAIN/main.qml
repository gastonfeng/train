//http://blog.csdn.net/foruok/article/details/46839569
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import "../QuickPromise/promise.js" as Qp

Window {
    title: "StackViewDemo"
    width: 480
    height: 320
    visible: true

    StackView {
        id: stack
        anchors.centerIn: parent
        width: 600
        height: 300
        property var home: null

        Text {
            id: text
            text: "promise:"
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
        Text {
            id: textAll
            text: 'all'
            font.pointSize: 14
            font.bold: true
            color: "red"
            anchors.centerIn: parent
            anchors.verticalCenterOffset: 50
        }
    }
    Component.onCompleted: {
        test()
        testall()
    }

    function f1() {
        var promise = new Qp.Promise()
        text.text += '(f1)'
        promise.resolve('-f1')
        promise.reject('-f1x')
        return promise
    }

    function f2(str) {
        var promise = new Qp.Promise()
        text.text += str + 'f2'
        promise.resolve('-f2')
        promise.reject('-f2x')
        return promise
    }
    function f3(str) {
        var promise = new Qp.Promise()
        text.text += str + 'f3'
        promise.resolve('-f3')
        promise.reject('-f3x')
        return promise
    }
    function f4(str) {
        var promise = new Qp.Promise()
        text.text += str + 'f4'
        promise.resolve('-f4')
        promise.reject('-f4x')
        return promise
    }
    function f5(str) {
        var promise = new Qp.Promise()
        text.text += str + "-f5"
        return promise
    }

    function errorf(reason) {
        text.text += 'error' + reason
    }

    function test() {
        f1().then(f2).then(f3).then(f4).then(f5).catch(function errorf(reason) {
            text.text += 'error' + reason
        })
    }
    function testall() {
        var promises = Qp.Promise.all([f1, f2, f3, f4, f5])
        Qp.Promise.all(promises).then(function (str) {
            textAll.text += str + 'ok'
        }, function (str) {
            textAll.text += str + ' error'
        })
    }
}
