//http://blog.csdn.net/foruok/article/details/46839569
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import AndroidInfo 1.0

Window {
    title: "StackViewDemo"
    visible: true
    AndroidInfo{
        id:android
    }

    Rectangle {
        anchors.fill: parent
        ColumnLayout {
            anchors.fill: parent
            Text{
                text:"亮度:"+android.Brightness()
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
            Text{
                text:"自动亮度:"+android.isAutoBrightness()
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
            Text{
                text:"serialNumber:"+android.serialNumber()
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                text: 'SDK版本:' + android.getandroidSdkVersion()
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '网络状态:' + android.networkStatus()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '应用目录:' + android.filesDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '铃声目录:' + android.ringtonesDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '视频目录' + android.movieDir
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "音乐目录" + android.musicDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '照片目录' + android.dcimDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '数据目录' + android.dataDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "外部存储目录" + android.externalStorageDir()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '应用缓存目录:' + android.appCacheDir()
            }

            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '应用名' + android.appClassName()
            }

            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: 'APK位置' + android.appLocation()
            }
            Text {
                font.pointSize: 16
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: '包名' + android.packageName()
            }
        }
    }
}
