package stas.quasilin.alkosecurityapp.entity;

import androidx.annotation.Nullable;

public class Sensor {
    private static final String EMPTY_STRING = "";
    private int id;
    private String name;
    private float data;

    public Sensor(int id, int data) {
        this.id = id;
        this.data = data;
    }

    public Sensor(int id, String name, int data) {
        this(id, data);
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public float getData() {
        return data;
    }

    public void setData(float data) {
        this.data = data;
    }

    private static final String STRING_FORMAT = "Датчик #%1s %2s %3s C";
    private static final String NAME_FORMAT = "[ %s ]";
    public String getString() {
        return String.format(STRING_FORMAT, id, (name != null && !name.isEmpty() ? String.format(NAME_FORMAT, name) : EMPTY_STRING),  data);
    }

    @Override
    public int hashCode() {
        return id;
    }

    @Override
    public boolean equals(@Nullable Object obj) {
        if (obj != null) {
            return getClass() == obj.getClass() && hashCode() == obj.hashCode();
        }
        return false;
    }
}
