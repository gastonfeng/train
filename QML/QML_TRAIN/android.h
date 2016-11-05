#ifndef ANDROID_H
#define ANDROID_H

#include <QObject>
#include <QtAndroid>
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#include <QDebug>

using namespace QtAndroid;

class Android : public QObject
{
    Q_OBJECT
public:
    explicit Android(QObject *parent = 0);
    Q_PROPERTY(QString getandroidSdkVersion READ getandroidSdkVersion )
    Q_PROPERTY(QString networkStatus READ networkStatus)

    QString externalStorageDir(){
        QAndroidJniObject externalStorageDir = QAndroidJniObject::callStaticObjectMethod(
                        "android/os/Environment",
                        "getExternalStorageDirectory",
                        "()Ljava/io/File;"
                        );
            CHECK_EXCEPTION()
            return (QString("外部存储目录:%1").arg(externalStorageDir.toString()));
    }

    QString dataDir(){
        QAndroidJniObject dataDir = QAndroidJniObject::callStaticObjectMethod(
                        "android/os/Environment",
                        "getDataDirectory",
                        "()Ljava/io/File;"
                        );
            CHECK_EXCEPTION()
            m_list->addItem(QString("数据目录:%1").arg(dataDir.toString()));
    }

    QString dcimDir(){
        QAndroidJniObject dcim = QAndroidJniObject::getStaticObjectField(
                       "android/os/Environment",
                       "DIRECTORY_DCIM",
                       "Ljava/lang/String;"
                       );
           CHECK_EXCEPTION()
           QAndroidJniObject dcimDir = QAndroidJniObject::callStaticObjectMethod(
                       "android/os/Environment",
                       "getExternalStoragePublicDirectory",
                       "(Ljava/lang/String;)Ljava/io/File;",
                       dcim.object<jstring>()
                       );
           CHECK_EXCEPTION()
           m_list->addItem(QString("照片目录:%1").arg(dcimDir.toString()));
    }

    QString musicDir(){
        QAndroidJniObject music = QAndroidJniObject::getStaticObjectField(
                        "android/os/Environment",
                        "DIRECTORY_MUSIC",
                        "Ljava/lang/String;"
                        );
            CHECK_EXCEPTION()
            QAndroidJniObject musicDir = QAndroidJniObject::callStaticObjectMethod(
                        "android/os/Environment",
                        "getExternalStoragePublicDirectory",
                        "(Ljava/lang/String;)Ljava/io/File;",
                        music.object<jstring>()
                        );
            CHECK_EXCEPTION()
            m_list->addItem(QString("音乐目录:%1").arg(musicDir.toString()));
    }

    QString movieDir(){
        QAndroidJniObject movie = QAndroidJniObject::getStaticObjectField(
                        "android/os/Environment",
                        "DIRECTORY_MOVIES",
                        "Ljava/lang/String;"
                        );
            CHECK_EXCEPTION()
            QAndroidJniObject movieDir = QAndroidJniObject::callStaticObjectMethod(
                        "android/os/Environment",
                        "getExternalStoragePublicDirectory",
                        "(Ljava/lang/String;)Ljava/io/File;",
                        movie.object<jstring>()
                        );
            CHECK_EXCEPTION()
            m_list->addItem(QString("视频目录:%1").arg(movieDir.toString()));
    }
QString ringtonesDir(){
    QAndroidJniObject ringtones = QAndroidJniObject::getStaticObjectField(
                    "android/os/Environment",
                    "DIRECTORY_RINGTONES",
                    "Ljava/lang/String;"
                    );
        CHECK_EXCEPTION()
        QAndroidJniObject ringtonesDir = QAndroidJniObject::callStaticObjectMethod(
                    "android/os/Environment",
                    "getExternalStoragePublicDirectory",
                    "(Ljava/lang/String;)Ljava/io/File;",
                    ringtones.object<jstring>()
                    );
        CHECK_EXCEPTION()
        m_list->addItem(QString("铃声目录:%1").arg(ringtonesDir.toString()));
}

QString filesDir(){
    QAndroidJniObject filesDir = activity.callObjectMethod(
                    "getFilesDir",
                    "()Ljava/io/File;");
        CHECK_EXCEPTION()
        m_list->addItem(QString("应用文件目录:%1").arg(filesDir.toString()));
}

QString packageName(){
    QAndroidJniObject packageName = activity.callObjectMethod<jstring>("getPackageName");
        CHECK_EXCEPTION()
        m_list->addItem(QString("应用包名:%1").arg(packageName.toString()));
}

QString appCacheDir(){
    QAndroidJniObject appCacheDir = activity.callObjectMethod(
                    "getCacheDir",
                    "()Ljava/io/File;");
        CHECK_EXCEPTION()
        m_list->addItem(QString("应用缓存目录:%1").arg(appCacheDir.toString()));
}

QString appClassName(){
    QAndroidJniObject appInfo = activity.callObjectMethod(
                    "getApplicationInfo",
                    "()Landroid/content/pm/ApplicationInfo;");
        CHECK_EXCEPTION()

        QAndroidJniObject appClassName = appInfo.getObjectField<jstring>("className");
        CHECK_EXCEPTION()
        m_list->addItem(QString("应用类名:%1").arg(appClassName.toString()));
}

QString appLocation(){
    QAndroidJniObject appLocation = appInfo.getObjectField(
                    "sourceDir", "Ljava/lang/String;");
        CHECK_EXCEPTION()
        m_list->addItem(QString("APK位置:%1").arg(appLocation.toString()));
}

signals:

public slots:
private:

    //获取安卓SDK版本
    QString getandroidSdkVersion()
    {
        return QtAndroid::androidSdkVersion();
    }

    //获取网络状态
    QString networkStatus()
    {
        QAndroidJniObject activity = androidActivity();
            //get network state
        QAndroidJniObject connectivity = QAndroidJniObject::getStaticObjectField(
                        "android/content/Context",
                        "CONNECTIVITY_SERVICE",
                        "Ljava/lang/String;");
        if(connectivity.isValid()){
                qDebug() << "connectivity id - " << connectivity.toString();
                CHECK_EXCEPTION()
                QAndroidJniObject connectivityService = activity.callObjectMethod(
                            "getSystemService",
                            "(Ljava/lang/String;)Ljava/lang/Object;",
                            connectivity.object<jstring>());
                CHECK_EXCEPTION()
                qDebug() << "got connectivity service - " << connectivityService.isValid();
                if(connectivityService.isValid())
                {
                    QAndroidJniObject networkInfo = connectivityService.callObjectMethod(
                                "getActiveNetworkInfo",
                                "()Landroid/net/NetworkInfo;");
                    CHECK_EXCEPTION()
                            qDebug() << "got NetworkInfo - " << networkInfo.isValid();
                    if(networkInfo.isValid())
                    {
                        return QString("网络状态：已连接(%1)").arg(networkInfo.toString());
                    }
                    else
                    {
                        return ("网络状态:未连接");
                    }
                }
    }
};

#endif // ANDROID_H
