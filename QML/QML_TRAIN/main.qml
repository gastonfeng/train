//http://blog.csdn.net/foruok/article/details/46839569
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtSystemInfo 5.0
DeviceInfo {
    id: device
}
Rectangle{
    anchors.fill: parent
    Text {
        id: name
        text: device.imei(0)
    }
}
