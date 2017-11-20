package com.example.dorin.greenhouse;

import java.io.IOException;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class Greenhouse {
    private static Greenhouse instance;
    private static OkHttpClient client;

    public static synchronized Greenhouse getInstance() {
        if (instance == null) {
            instance = new Greenhouse();
            client = new OkHttpClient();
        }
        return instance;
    }

    private Greenhouse() {}

    public String getHumidity() throws IOException {
        Request request = new Request.Builder()
                .url("http://192.168.87.110:8091/humidity")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String getTemperature() throws IOException {
        Request request = new Request.Builder()
                .url("http://192.168.87.110:8091/temperature")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String getLight() throws IOException {
        Request request = new Request.Builder()
                .url("http://192.168.87.110:8091/light")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String getLid() throws IOException {
        Request request = new Request.Builder()
                .url("http://192.168.87.110:8091/lid")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String getHeater() throws IOException {
        Request request = new Request.Builder()
                .url("http://192.168.87.110:8091/heater")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }
    
    public String getLapm() throws IOException {
        Request request = new Request.Builder()
                .url("http://192.168.87.110:8091/lamp")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }
}
