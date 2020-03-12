package stas.quasilin.alkosecurityapp.services;

import android.app.Notification;
import android.app.Service;
import android.content.Intent;
import android.os.CountDownTimer;
import android.os.IBinder;
import android.widget.Toast;

import androidx.annotation.Nullable;

import java.util.ArrayList;

import stas.quasilin.alkosecurityapp.entity.Sensor;
import stas.quasilin.alkosecurityapp.utils.Notificator;

public class ForegroundService extends Service {

    CountDownTimer tick;
    DeviceConnector connector;

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    ArrayList<Sensor> sensors = new ArrayList<>();

    @Override
    public void onCreate() {
        super.onCreate();

        Toast.makeText(getApplicationContext(), "Start Service", Toast.LENGTH_SHORT).show();

        sensors.add(new Sensor(0, 10));
        sensors.add(new Sensor(1, 12));
        Notification notification = Notificator.build(getApplicationContext(), 1, sensors);
        super.startForeground(1, notification);

        sensors.add(new Sensor(2, 8));

        tick = new CountDownTimer(30000, 1200) {
            @Override
            public void onTick(long millisUntilFinished) {
                System.out.println("Tick");
                for (Sensor sensor : sensors) {
                    sensor.setData(sensor.getData() + 1);
                    System.out.println(sensor.getString());
                }
                Notificator.updateNotification(getApplicationContext(), 1, sensors);

            }

            @Override
            public void onFinish() {

            }
        }.start();
    }

    @Override
    public void onDestroy() {
        if (tick != null){
            tick.cancel();
        }
        Toast.makeText(getApplicationContext(), "Destroy service", Toast.LENGTH_SHORT).show();
    }
}
