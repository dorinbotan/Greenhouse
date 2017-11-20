package com.example.dorin.greenhouse;

import java.io.IOException;

import okhttp3.MediaType;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;

public class Greenhouse {
    private static Greenhouse instance;
    private static OkHttpClient client;

    private static String host = "http://192.168.87.110:8091";

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
                .url(host + "/humidity")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String getTemperature() throws IOException {
        Request request = new Request.Builder()
                .url(host + "/temperature")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String getLight() throws IOException {
        Request request = new Request.Builder()
                .url(host + "/light")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public boolean getHumidityMode() throws IOException {
        Request request = new Request.Builder()
                .url(host + "/humidity/mode")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string().equals("1");
    }

    public boolean getTemperatureMode() throws IOException {
        Request request = new Request.Builder()
                .url(host + "/humidity/mode")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string().equals("1");
    }

    public boolean getLightMode() throws IOException {
        Request request = new Request.Builder()
                .url(host + "/humidity/mode")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string().equals("1");
    }

    public String setHumidity(int value) throws IOException {
        Request request = new Request.Builder()
                .url(host + "/humidity")
                .post(RequestBody.create(MediaType.parse("text/plain; charset=utf-8"),
                        Integer.toString(value)))
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String setTemperature(int value) throws IOException {
        Request request = new Request.Builder()
                .url(host + "/temperature")
                .post(RequestBody.create(MediaType.parse("text/plain; charset=utf-8"),
                        Integer.toString(value)))
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String setLight(int value) throws IOException {
        Request request = new Request.Builder()
                .url(host + "/light")
                .post(RequestBody.create(MediaType.parse("text/plain; charset=utf-8"),
                        Integer.toString(value)))
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String getLid() throws IOException {
        Request request = new Request.Builder()
                .url(host + "/lid")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String getHeater() throws IOException {
        Request request = new Request.Builder()
                .url(host + "/heater")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String getLamp() throws IOException {
        Request request = new Request.Builder()
                .url(host + "/lamp")
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String setLid(int value) throws IOException {
        Request request = new Request.Builder()
                .url(host + "/lid")
                .post(RequestBody.create(MediaType.parse("text/plain; charset=utf-8"),
                        Integer.toString(value)))
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String setHeater(int value) throws IOException {
        Request request = new Request.Builder()
                .url(host + "/lid")
                .post(RequestBody.create(MediaType.parse("text/plain; charset=utf-8"),
                        Integer.toString(value)))
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }

    public String setLamp(int value) throws IOException {
        Request request = new Request.Builder()
                .url(host + "/lid")
                .post(RequestBody.create(MediaType.parse("text/plain; charset=utf-8"),
                        Integer.toString(value)))
                .build();

        Response response = client.newCall(request).execute();
        return response.body().string();
    }
}
