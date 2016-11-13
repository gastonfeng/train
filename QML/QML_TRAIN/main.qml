//http://blog.csdn.net/foruok/article/details/46839569
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1


//import AndroidInfoInfo 1.0
Window {
    title: "StackViewDemo"
    visible: true
    //    AndroidInfoInfo{
    //        id:AndroidInfo
    //    }
    onBeforeRendering: {
        console.info('onBeforeRendering in')
        AndroidInfo.setRunAfterInstall()
        console.info('onBeforeRendering out')
    }
    Rectangle {
        anchors.fill: parent
        ColumnLayout {
            anchors.fill: parent
            Text {
                text: "亮度:" + AndroidInfo.Brightness()
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
            Text {
                text: "自动亮度:" + AndroidInfo.isAutoBrightness()
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
            Text {
                text: "serialNumber:" + AndroidInfo.serialNumber()
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                text: 'SDK版本:' + AndroidInfo.getandroidSdkVersion()
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '网络状态:' + AndroidInfo.networkStatus()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '应用目录:' + AndroidInfo.filesDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '铃声目录:' + AndroidInfo.ringtonesDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '视频目录' + AndroidInfo.movieDir
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "音乐目录" + AndroidInfo.musicDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '照片目录' + AndroidInfo.dcimDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '数据目录' + AndroidInfo.dataDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "外部存储目录" + AndroidInfo.externalStorageDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '应用缓存目录:' + AndroidInfo.appCacheDir()
            }

            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '应用名' + AndroidInfo.appClassName()
            }

            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: 'APK位置' + AndroidInfo.appLocation()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '包名' + AndroidInfo.packageName()
            }
        }
    }
}
