package stas.quasilin.alkosecurityapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ListView;
import android.widget.Toast;

import stas.quasilin.alkosecurityapp.constants.Constants;
import stas.quasilin.alkosecurityapp.services.DeviceConnector;
import stas.quasilin.alkosecurityapp.services.ForegroundService;
import stas.quasilin.alkosecurityapp.utils.DataContainer;
import stas.quasilin.alkosecurityapp.utils.ForegroundServiceRunner;
import stas.quasilin.alkosecurityapp.view.SensorViewAdapter;

public class MainActivity extends AppCompatActivity {

    DeviceConnector connector;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ListView listView = findViewById(R.id.list);
        listView.setAdapter(new SensorViewAdapter(getApplicationContext(), R.id.sensorView, DataContainer.getInstance().getList()));
    }

    @Override
    protected void onResume() {
        super.onResume();
        Intent intent = getIntent();
        connector = (DeviceConnector) intent.getSerializableExtra(Constants.CONNECTOR);
        System.out.println(connector);
        stopService(new Intent(getApplicationContext(), ForegroundService.class));

        Toast.makeText(getApplicationContext(), "RESUME", Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onPause() {
        super.onPause();
        System.out.println("PAUSE");
    }

    @Override
    protected void onStop() {
        super.onStop();
//        Toast.makeText(getApplicationContext(), "STOP", Toast.LENGTH_SHORT).show();
        ForegroundServiceRunner.runService(getApplicationContext(), connector);
    }
}
