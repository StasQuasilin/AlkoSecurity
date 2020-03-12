package stas.quasilin.alkosecurityapp.services;

import java.io.Serializable;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import stas.quasilin.alkosecurityapp.websocket.SocketListener;

public class DeviceConnector implements Serializable {

    private OkHttpClient client = new OkHttpClient();

    void connect(String url){
        Request request = new Request.Builder().url(url).build();
        SocketListener listener = new SocketListener();
        client.newWebSocket(request, listener);
        client.dispatcher().executorService().shutdown();
    }

    void disconnect(){

    }
}
