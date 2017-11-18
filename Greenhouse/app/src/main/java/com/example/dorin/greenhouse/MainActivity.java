package com.example.dorin.greenhouse;

import android.os.Handler;
import android.os.StrictMode;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import android.webkit.WebView;
import android.widget.SeekBar;
import android.widget.TextView;

import java.io.IOException;

public class MainActivity extends AppCompatActivity {
    private Greenhouse greenhouse;
    private WebView webView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);

        greenhouse = new Greenhouse();

        webView = (WebView)findViewById(R.id.webView);
        webView.getSettings().setJavaScriptEnabled(true);
        webView.loadUrl("file:///android_asset/index.html");

        final Handler handler = new Handler();
        handler.postDelayed(new Runnable(){
            public void run(){
                updateValues();
                handler.postDelayed(this, 3000);
            }
        }, 0);

        final SeekBar humiditySeekBar = (SeekBar)findViewById(R.id.humiditySeekBar);
        humiditySeekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                System.out.println(seekBar.getProgress());
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {}

            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {}
        });
    }

    private void updateValues() {
        final TextView humidityValue = (TextView)findViewById(R.id.humidityValue);
        final TextView temperatureValue = (TextView)findViewById(R.id.temperatureValue);
        final TextView lightValue = (TextView)findViewById(R.id.lightValue);

        try {
            humidityValue.setText(greenhouse.getHumidity() + " %");
        } catch (IOException e) {
            humidityValue.setText("N/A");
        }

        try {
            temperatureValue.setText(greenhouse.getTemperature() + " °C");
        } catch (IOException e) {
            temperatureValue.setText("N/A");
        }

        try {
            lightValue.setText(greenhouse.getLight() + " %");
        } catch (IOException e) {
            lightValue.setText("N/A");
        }
    }
}
