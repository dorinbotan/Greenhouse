package com.example.dorin.greenhouse;

import android.support.v7.app.AppCompatActivity;
import android.os.StrictMode;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);

        new Humidity(this);
        new Temperature(this);
        new Light(this);
        new Chart(this);
    }
}
