package stas.quasilin.alkosecurityapp.utils;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.os.Build;

import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;

import java.util.ArrayList;

import stas.quasilin.alkosecurityapp.MainActivity;
import stas.quasilin.alkosecurityapp.R;
import stas.quasilin.alkosecurityapp.entity.Sensor;

public class Notificator {

    private static final String channelId = "channel";

    public static Notification build(Context context, int id, ArrayList<Sensor> sensors){
        NotificationManagerCompat manager = NotificationManagerCompat.from(context);
        Intent resultIntent = new Intent(context, MainActivity.class);
        PendingIntent resultPendingIntent = PendingIntent.getActivity(context, 0, resultIntent,
                PendingIntent.FLAG_CANCEL_CURRENT);

        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
            CharSequence name = "Main Channel";
            NotificationChannel notificationChannel = new NotificationChannel(channelId, name, NotificationManager.IMPORTANCE_DEFAULT);
            manager.createNotificationChannel(notificationChannel);
        }
        NotificationCompat.InboxStyle inboxStyle = new NotificationCompat.InboxStyle();
        for (Sensor sensor : sensors){
            inboxStyle.addLine(sensor.getString());
        }

        NotificationCompat.Builder builder =
                new NotificationCompat.Builder(context, channelId)
                        .setSmallIcon(android.R.drawable.ic_dialog_info)
                        .setOngoing(true)
                        .setContentText(context.getResources().getString(R.string.notify_in_background))
                        .setStyle(inboxStyle)
                        .setPriority(NotificationCompat.PRIORITY_HIGH)
                        .setContentIntent(resultPendingIntent)
                        .setAutoCancel(true)
                        .setVisibility(NotificationCompat.VISIBILITY_PUBLIC)
                ;

        return builder.build();
    }

    public static void updateNotification(Context context, int id, ArrayList<Sensor> sensors){
        NotificationManagerCompat manager = NotificationManagerCompat.from(context);
        Notification build = build(context, id, sensors);
        manager.notify(id, build);
    }
}
