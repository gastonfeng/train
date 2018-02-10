import QtQuick 2.7
import QtCharts 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import Testable 1.0
import QtTest 1.0

Item {

    //import "../../qtbase/lib_qml"
    TestCase {
        name: "tst"
        id: test_rect
        function test_fail() {
            compare(2 + 2, 5, "2 + 2 = 5")
        }
        function test_timestring() {
            var timsstring = '2018-01-29 15:09:03'
            var dtn = Date.fromLocaleString(Qt.locale(), timsstring,
                                            "yyyy-MM-dd hh:mm:ss")
            var msec = dtn.getTime()
            console.info(timsstring, ' = ', msec)
            var v = "80"
            v = parseFloat(v)
            compare(v, 80.0, "float")
        }
    }
}
