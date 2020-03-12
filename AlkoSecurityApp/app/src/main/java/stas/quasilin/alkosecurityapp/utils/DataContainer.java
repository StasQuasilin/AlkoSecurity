package stas.quasilin.alkosecurityapp.utils;

import java.util.ArrayList;

import stas.quasilin.alkosecurityapp.entity.Sensor;

public class DataContainer {
    private static final DataContainer instance = new DataContainer();

    public static DataContainer getInstance() {
        return instance;
    }

    private final ArrayList<Sensor> sensors = new ArrayList<>();


    private DataContainer() {
        for (int i = 0; i < 3; i++){
            sensors.add(new Sensor(i, 0));
        }
    }

    public void update(Sensor sensor){


    }

    public void clear(){
        sensors.clear();
    }

    public ArrayList<Sensor> getList() {
        return sensors;
    }
}
