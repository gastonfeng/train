#ifndef ANDROID_H
#define ANDROID_H

#include <QObject>
#include <QtAndroid>
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#include <QDebug>

using namespace QtAndroid;

class androidInfo : public QObject
{
    Q_OBJECT
public:
    explicit androidInfo(QObject *parent = 0):QObject(parent) {};


    Q_INVOKABLE QString externalStorageDir()
    {
        QAndroidJniObject externalStorageDir = QAndroidJniObject::callStaticObjectMethod(
                "android/os/Environment",
                "getExternalStorageDirectory",
                "()Ljava/io/File;"
                                               );
        //CHECK_EXCEPTION()
        return (QString("外部存储目录:%1").arg(externalStorageDir.toString()));
    }

    Q_INVOKABLE QString dataDir()
    {
        QAndroidJniObject dataDir = QAndroidJniObject::callStaticObjectMethod(
                                        "android/os/Environment",
                                        "getDataDirectory",
                                        "()Ljava/io/File;"
                                    );
        //CHECK_EXCEPTION()
        return(QString("数据目录:%1").arg(dataDir.toString()));
    }

    Q_INVOKABLE QString dcimDir()
    {
        QAndroidJniObject dcim = QAndroidJniObject::getStaticObjectField(
                                     "android/os/Environment",
                                     "DIRECTORY_DCIM",
                                     "Ljava/lang/String;"
                                 );
        //CHECK_EXCEPTION()
        QAndroidJniObject dcimDir = QAndroidJniObject::callStaticObjectMethod(
                                        "android/os/Environment",
                                        "getExternalStoragePublicDirectory",
                                        "(Ljava/lang/String;)Ljava/io/File;",
                                        dcim.object<jstring>()
                                    );
        //CHECK_EXCEPTION()
        return(QString("照片目录:%1").arg(dcimDir.toString()));
    }

    Q_INVOKABLE QString musicDir()
    {
        QAndroidJniObject music = QAndroidJniObject::getStaticObjectField(
                                      "android/os/Environment",
                                      "DIRECTORY_MUSIC",
                                      "Ljava/lang/String;"
                                  );
        //CHECK_EXCEPTION()
        QAndroidJniObject musicDir = QAndroidJniObject::callStaticObjectMethod(
                                         "android/os/Environment",
                                         "getExternalStoragePublicDirectory",
                                         "(Ljava/lang/String;)Ljava/io/File;",
                                         music.object<jstring>()
                                     );
        //CHECK_EXCEPTION()
        return(QString("音乐目录:%1").arg(musicDir.toString()));
    }

    Q_INVOKABLE QString movieDir()
    {
        QAndroidJniObject movie = QAndroidJniObject::getStaticObjectField(
                                      "android/os/Environment",
                                      "DIRECTORY_MOVIES",
                                      "Ljava/lang/String;"
                                  );
        //CHECK_EXCEPTION()
        QAndroidJniObject movieDir = QAndroidJniObject::callStaticObjectMethod(
                                         "android/os/Environment",
                                         "getExternalStoragePublicDirectory",
                                         "(Ljava/lang/String;)Ljava/io/File;",
                                         movie.object<jstring>()
                                     );
        //CHECK_EXCEPTION()
        return(QString("视频目录:%1").arg(movieDir.toString()));
    }
    Q_INVOKABLE QString ringtonesDir()
    {
        QAndroidJniObject ringtones = QAndroidJniObject::getStaticObjectField(
                                          "android/os/Environment",
                                          "DIRECTORY_RINGTONES",
                                          "Ljava/lang/String;"
                                      );
        //CHECK_EXCEPTION()
        QAndroidJniObject ringtonesDir = QAndroidJniObject::callStaticObjectMethod(
                                             "android/os/Environment",
                                             "getExternalStoragePublicDirectory",
                                             "(Ljava/lang/String;)Ljava/io/File;",
                                             ringtones.object<jstring>()
                                         );
        //CHECK_EXCEPTION()
        return(QString("铃声目录:%1").arg(ringtonesDir.toString()));
    }

    Q_INVOKABLE QString filesDir()
    {
        QAndroidJniObject activity = androidActivity();
        QAndroidJniObject filesDir = activity.callObjectMethod(
                                         "getFilesDir",
                                         "()Ljava/io/File;");
        //CHECK_EXCEPTION()
        return(QString("应用文件目录:%1").arg(filesDir.toString()));
    }

    Q_INVOKABLE QString packageName()
    {
        QAndroidJniObject activity = androidActivity();
        QAndroidJniObject packageName = activity.callObjectMethod<jstring>("getPackageName");
        //CHECK_EXCEPTION()
        return(QString("应用包名:%1").arg(packageName.toString()));
    }

    Q_INVOKABLE QString appCacheDir()
    {
        QAndroidJniObject activity = androidActivity();
        QAndroidJniObject appCacheDir = activity.callObjectMethod(
                                            "getCacheDir",
                                            "()Ljava/io/File;");
        //CHECK_EXCEPTION()
        return(QString("应用缓存目录:%1").arg(appCacheDir.toString()));
    }

    Q_INVOKABLE QString appClassName()
    {
        QAndroidJniObject activity = androidActivity();
        QAndroidJniObject appInfo = activity.callObjectMethod(
                                        "getApplicationInfo",
                                        "()Landroid/content/pm/ApplicationInfo;");
        //CHECK_EXCEPTION()

        QAndroidJniObject appClassName = appInfo.getObjectField<jstring>("className");
        //CHECK_EXCEPTION()
        return(QString("应用类名:%1").arg(appClassName.toString()));
    }

    Q_INVOKABLE QString appLocation()
    {
        QAndroidJniObject activity = androidActivity();
        QAndroidJniObject appInfo = activity.callObjectMethod(
                                        "getApplicationInfo",
                                        "()Landroid/content/pm/ApplicationInfo;");
        QAndroidJniObject appLocation = appInfo.getObjectField(
                                            "sourceDir", "Ljava/lang/String;");
        //CHECK_EXCEPTION()
        return(QString("APK位置:%1").arg(appLocation.toString()));
    }
    Q_INVOKABLE QString imei()
    {
        QAndroidJniEnvironment env;
        jclass contextClass = env->FindClass("android/content/Context");
        jfieldID fieldId = env->GetStaticFieldID(contextClass, "TELEPHONY_SERVICE", "Ljava/lang/String;");
        jstring telephonyManagerType = (jstring) env->GetStaticObjectField(contextClass, fieldId);
        jclass telephonyManagerClass = env->FindClass("android/telephony/TelephonyManager");
        jmethodID methodId = env->GetMethodID(contextClass, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");
        QAndroidJniObject qtActivityObj =   QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");
        jobject telephonyManager = env->CallObjectMethod(qtActivityObj.object<jobject>(), methodId, telephonyManagerType);
        methodId = env->GetMethodID(telephonyManagerClass, "getDeviceId", "()Ljava/lang/String;");
        jstring jstr = (jstring) env->CallObjectMethod(telephonyManager, methodId);
        jsize len = env->GetStringUTFLength(jstr);
        char* buf_devid = new char[32];
        env->GetStringUTFRegion(jstr, 0, len, buf_devid);
        QString imei(buf_devid);
        delete buf_devid;
        return imei;
    }
    Q_INVOKABLE QString serialNumber()
    {
        QAndroidJniObject serial = QAndroidJniObject::getStaticObjectField(
                                        "android/os/Build",
                                        "SERIAL",
                                        "Ljava/lang/String;"
                                    );
        //CHECK_EXCEPTION()
        return(QString("%1").arg(serial.toString()));
    }

    //获取安卓SDK版本
    Q_INVOKABLE QString getandroidSdkVersion()
    {
        return QString("%1").arg(QtAndroid::androidSdkVersion());
    }

    //获取网络状态
    Q_INVOKABLE QString networkStatus()
    {
        QAndroidJniObject activity = androidActivity();
        //get network state
        QAndroidJniObject connectivity = QAndroidJniObject::getStaticObjectField(
                                             "android/content/Context",
                                             "CONNECTIVITY_SERVICE",
                                             "Ljava/lang/String;");
        if(connectivity.isValid())
        {
            qDebug() << "connectivity id - " << connectivity.toString();
            //CHECK_EXCEPTION()
            QAndroidJniObject connectivityService = activity.callObjectMethod(
                    "getSystemService",
                    "(Ljava/lang/String;)Ljava/lang/Object;",
                    connectivity.object<jstring>());
            //CHECK_EXCEPTION()
            qDebug() << "got connectivity service - " << connectivityService.isValid();
            if(connectivityService.isValid())
            {
                QAndroidJniObject networkInfo = connectivityService.callObjectMethod(
                                                    "getActiveNetworkInfo",
                                                    "()Landroid/net/NetworkInfo;");
                //CHECK_EXCEPTION()
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
        return "未知";
    }
    Q_INVOKABLE QString isAutoBrightness()
    {
        QAndroidJniObject activity = androidActivity();
        QAndroidJniObject contentResolver = activity.callObjectMethod(
                       "getContentResolver",
                       "()Landroid/content/ContentResolver;"
                       );
        QAndroidJniObject brightnessModeTag = QAndroidJniObject::fromString("screen_brightness_mode");
        QAndroidJniObject result = QAndroidJniObject::callStaticObjectMethod(
                                             "android/provider/Settings$System",
                                             "getString",
                                             "(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;",contentResolver.object<jobject>(),brightnessModeTag.object<jstring>());
        qDebug() << "got AutoBrightness - " << result.isValid();
        if(result.isValid())
        return QString("%1").arg(result.toString());
        return "未知";
    }
    Q_INVOKABLE QString Brightness()
    {
        QAndroidJniObject activity = androidActivity();
        QAndroidJniObject contentResolver = activity.callObjectMethod(
                       "getContentResolver",
                       "()Landroid/content/ContentResolver;"
                       );
        QAndroidJniObject brightnessModeTag = QAndroidJniObject::fromString("screen_brightness");
        QAndroidJniObject result = QAndroidJniObject::callStaticObjectMethod(
                                             "android/provider/Settings$System",
                                             "getString",
                                             "(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;",contentResolver.object<jobject>(),brightnessModeTag.object<jstring>());
        qDebug() << "got Brightness - " << result.isValid();
        if(result.isValid())
        return QString("%1").arg(result.toString());
        return "未知";
    }

    Q_INVOKABLE bool Brightness(int bri)
    {
        QAndroidJniObject activity = androidActivity();
        QAndroidJniObject contentResolver = activity.callObjectMethod(
                       "getContentResolver",
                       "()Landroid/content/ContentResolver;"
                       );
        QAndroidJniObject brightnessModeTag = QAndroidJniObject::fromString("screen_brightness");
        QAndroidJniObject result = QAndroidJniObject::callStaticObjectMethod(
                                             "android/provider/Settings$System",
                                             "putInt",
                                             "(Landroid/content/ContentResolver;Ljava/lang/String;I)Z;",contentResolver.object<jobject>(),brightnessModeTag.object<jstring>(),bri);
        qDebug() << "got Brightness - " << result.isValid();
        if(result.isValid())
        return result.toString()=="1";
        return 0;
    }

    //振动
    Q_INVOKABLE void Vibrate(int duration)
    {
        QAndroidJniEnvironment env;
        QAndroidJniObject activity = androidActivity();
        QAndroidJniObject name = QAndroidJniObject::getStaticObjectField(
                    "android/content/Context",
                    "VIBRATOR_SERVICE",
                    "Ljava/lang/String;"
                    );
        //CHECK_EXCEPTION();
        QAndroidJniObject vibrateService = activity.callObjectMethod(
                    "getSystemService",
                    "(Ljava/lang/String;)Ljava/lang/Object;",
                    name.object<jstring>());
        //CHECK_EXCEPTION();
        jlong jduration = duration;
        vibrateService.callMethod<void>("vibrate", "(J)V", jduration);
        //CHECK_EXCEPTION();
    }

    //显示方向
    Q_INVOKABLE void ScreenOrientation()
    {
        QAndroidJniEnvironment env;
        QAndroidJniObject activity = androidActivity();
        jint orient = activity.callMethod<jint>(
                    "getRequestedOrientation"
                    );
       // CHECK_EXCEPTION();
        if(orient == 1)
        {
            orient = 0;
        }
        else
        {
            orient = 1;
        }
        activity.callMethod<void>(
                    "setRequestedOrientation",
                    "(I)V", orient);
       // CHECK_EXCEPTION();
    }
signals:

public slots:
private:

};

#endif // ANDROID_H
