package com.example.dorin.greenhouse;

import android.content.Context;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    private Greenhouse greenhouse;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        greenhouse = new Greenhouse();

        final TextView humidityValue = (TextView)findViewById(R.id.humidityValueText);
        final TextView temperatureValue = (TextView)findViewById(R.id.temperatureValueText);
        final TextView lightValue = (TextView)findViewById(R.id.lightValueText);

        final Handler handler = new Handler();
        final int delay = 1000; //milliseconds

        handler.postDelayed(new Runnable(){
            public void run(){
                Random generator = new Random();

                humidityValue.setText(Integer.toString(generator.nextInt(100) + 1) + " %");
                temperatureValue.setText(Integer.toString(generator.nextInt(100) + 1) + " °C");
                lightValue.setText(Integer.toString(generator.nextInt(100) + 1) + " %");

                handler.postDelayed(this, delay);
            }
        }, delay);
    }

    public void humidityButtonClick(View view) {
        Context context = getApplicationContext();
        CharSequence text = "Hello toast!";
        int duration = Toast.LENGTH_SHORT;

        Toast toast = Toast.makeText(context, text, duration);
        toast.show();

        LinearLayout humidityDropdown = (LinearLayout) findViewById(R.id.humidityDropdown);
        RelativeLayout temperatureButton = (RelativeLayout) findViewById(R.id.temperatureButton);

        if(humidityDropdown.getVisibility() == View.GONE) {
            humidityDropdown.setVisibility(View.VISIBLE);
            humidityDropdown.animate().alpha(1.0f);
            temperatureButton.animate().translationY(temperatureButton.getHeight());
        }
        else {
            humidityDropdown.setVisibility(View.GONE);
            humidityDropdown.animate().alpha(0.0f);
            temperatureButton.animate().translationY(0);
        }
    }
}
