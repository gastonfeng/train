package com.kaikong.update;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.widget.Toast;


public class thenrun extends BroadcastReceiver {
    private static thenrun mReceiver = new thenrun();
    private static IntentFilter mIntentFilter;

    public void registerReceiver(Activity activity) {
        System.out.println("thenrun registerReceiver");
        Context context = activity.getApplicationContext();
        mIntentFilter = new IntentFilter();
        mIntentFilter.addDataScheme("package");
        mIntentFilter.addAction(Intent.ACTION_PACKAGE_ADDED);
        mIntentFilter.addAction(Intent.ACTION_PACKAGE_REMOVED);
        mIntentFilter.addAction(Intent.ACTION_PACKAGE_REPLACED);
        context.registerReceiver(mReceiver, mIntentFilter);
        //thenrun.registerReceiver(getApplicationContext());//注册广播，用于监听应用是否安装完成
        System.out.println("thenrun registerReceiver Completed.");
    }

    public void unregisterReceiver(Context context) {
        context.unregisterReceiver(mReceiver);
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        System.out.println("java: thenrun Receiver");
        String action = intent.getAction();
        String packageName = intent.getData().getSchemeSpecificPart();
        if (Intent.ACTION_PACKAGE_ADDED.equals(action)) {
            Toast.makeText(context, "添加了新的应用", Toast.LENGTH_LONG).show();
            PackageManager pm = context.getPackageManager();
            Intent intent1 = new Intent();
            //try {
            intent1 = pm.getLaunchIntentForPackage(packageName);
            //  }
            //catch (NameNotFoundException e) {
            // TODO Auto-generated catch block
            //e.printStackTrace();
            // }
            intent1.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            context.startActivity(intent1);
        } //else if (Intent.ACTION_PACKAGE_REMOVED.equals(action)) {
        //// Toast.makeText(context, "有应用被删除", Toast.LENGTH_LONG).show();
        // } else if (Intent.ACTION_PACKAGE_REPLACED.equals(action)) {
        //// Toast.makeText(context, "有应用被替换", Toast.LENGTH_LONG).show();
        // }
    }


}


