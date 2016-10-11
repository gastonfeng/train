//from :http://www.cnblogs.com/L-Arikes/p/4380382.html
import QtQuick 2.0
import QtQuick.Window 2.0
import QtQml 2.0
import "./Datetime.js" as Datetime

Window {
    width: 800
    height: 600
    visible: true
    Rectangle {
        width: 300
        height: 300

        Text {
            id: myText


            text: Datetime.currentDatetime()

        }


    }

}
