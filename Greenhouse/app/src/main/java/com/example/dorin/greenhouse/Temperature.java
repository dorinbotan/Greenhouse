package com.example.dorin.greenhouse;

import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.SeekBar;
import android.widget.TextView;

import java.io.IOException;

public class Temperature {
    private Greenhouse greenhouse;
    private final ImageView imageView;
    private final RelativeLayout button;
    private final TextView valueView;
    private final TextView modeView;
    private final SeekBar seekBarView;

    private boolean mode;

    public Temperature(AppCompatActivity parent) {
        greenhouse = Greenhouse.getInstance();
        imageView = (ImageView)parent.findViewById(R.id.temperatureImage);
        button = (RelativeLayout)parent.findViewById(R.id.temperatureButton);
        valueView = (TextView)parent.findViewById(R.id.temperatureValue);
        modeView = (TextView)parent.findViewById(R.id.temperatureMode);
        seekBarView = (SeekBar)parent.findViewById(R.id.temperatureSeekBar);

//        mode = greenhouse.getHumidityMode();

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mode = !mode;

                if(mode)
                    modeView.setText("auto (" + Integer.toString(seekBarView.getProgress()) + "°C)");
                else
                    modeView.setText("manual (" + Integer.toString(seekBarView.getProgress()) + ")");
            }
        });

        seekBarView.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                System.out.println(seekBar.getProgress());
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {}

            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if(mode)
                    modeView.setText("auto (" + Integer.toString(progress) + "°C)");
                else
                    modeView.setText("manual (" + Integer.toString(progress) + ")");
            }
        });

        final Handler handler = new Handler();
        handler.postDelayed(new Runnable(){
            public void run(){
                try {
                    valueView.setText(greenhouse.getTemperature() + " °C");
                } catch (IOException e) {
                    valueView.setText("N/A");
                }

//                handler.postDelayed(this, 3000);
            }
        }, 0);
    }
}
