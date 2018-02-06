import QtQuick 2.7
import QtCharts 2.2
import QtTest 1.1
import "../../qtbase/lib_qml"
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

TestCase {

    Rectangle {
        ChartView {
        }

        id: test_rect
        function test_fail() {
            compare(2 + 2, 5, "2 + 2 = 5")
        }
    }
}
