package com.example.dorin.greenhouse;

import java.io.IOException;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class Greenhouse {
    private OkHttpClient client;

    public Greenhouse() {
        client = new OkHttpClient();
    }

    public String getHumidity() throws IOException {
        Request request = new Request.Builder()
                .url("http://192.168.87.116/humidity")
                .build();

//        Response response = client.newCall(request).execute();
//        return response.body().string();

        return "50 %";
    }

    public int getTemperature() {
        return 0;
    }

    public int getLight() {
        return 0;
    }
}
