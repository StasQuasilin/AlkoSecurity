package stas.quasilin.alkosecurityapp.view;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;
import java.util.List;

import stas.quasilin.alkosecurityapp.R;
import stas.quasilin.alkosecurityapp.entity.Sensor;

public class SensorViewAdapter extends ArrayAdapter<Sensor> {

    private Context context;
    private int resource;
    private ArrayList<Sensor> sensors;

    public SensorViewAdapter(@NonNull Context context, int resource, @NonNull ArrayList<Sensor> sensors) {
        super(context, resource, sensors);
        this.context = context;
        this.resource = resource;
        this.sensors = sensors;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        Sensor sensor = sensors.get(position);

        if(convertView == null){
            LayoutInflater layoutInflater = LayoutInflater.from(context);
            convertView=layoutInflater.inflate(R.layout.sensor_view, null);
        }
        return convertView;
    }
}
