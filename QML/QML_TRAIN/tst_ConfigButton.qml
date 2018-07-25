import QtQuick 2.0
import QtTest 1.0
import "../../mywork/qtbase/lib_qml"

ConfigButton {
    id: btn
    TestCase {
        function tst_on() {
            btn.checked = true
        }
        function tst_off() {
            btn.checked = false
        }
    }
}
