package stas.quasilin.alkosecurityapp.utils;

import android.content.Context;
import android.content.Intent;

import stas.quasilin.alkosecurityapp.constants.Constants;
import stas.quasilin.alkosecurityapp.services.DeviceConnector;
import stas.quasilin.alkosecurityapp.services.ForegroundService;

public class ForegroundServiceRunner {

    public static void runService(Context applicationContext, DeviceConnector connector) {
        Intent intent = new Intent(applicationContext, ForegroundService.class);
        intent.putExtra(Constants.CONNECTOR, connector);
        applicationContext.startService(intent);
    }
}
