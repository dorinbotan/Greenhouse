package com.example.dorin.greenhouse;

import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.SeekBar;
import android.widget.TextView;

import java.io.IOException;

public class Humidity {
    private Greenhouse greenhouse;
    private final ImageView imageView;
    private final RelativeLayout button;
    private final TextView valueView;
    private final TextView modeView;
    private final SeekBar seekBarView;

    private boolean mode;

    public Humidity(AppCompatActivity parent) {
        greenhouse = Greenhouse.getInstance();
        imageView = (ImageView)parent.findViewById(R.id.humidityImage);
        button = (RelativeLayout)parent.findViewById(R.id.humidityButton);
        valueView = (TextView)parent.findViewById(R.id.humidityValue);
        modeView = (TextView)parent.findViewById(R.id.humidityMode);
        seekBarView = (SeekBar)parent.findViewById(R.id.humiditySeekBar);

        try {
            mode = greenhouse.getHumidityMode();
            setMode();
        } catch (IOException e) {
            e.printStackTrace();
        }

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mode = !mode;
                setMode();

                try {
                    if(mode) {
                        greenhouse.setHumidity(seekBarView.getProgress());
                    }
                    else {
                        greenhouse.setLid(seekBarView.getProgress());
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        seekBarView.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                try {
                    if(mode) {
                        greenhouse.setHumidity(seekBarView.getProgress());
                    }
                    else {
                        greenhouse.setLid(seekBarView.getProgress());
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {}

            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if(mode)
                    modeView.setText("auto (" + Integer.toString(progress) + "%)");
                else
                    modeView.setText("manual (" + Integer.toString(progress) + "%)");
            }
        });

        final Handler handler = new Handler();
        handler.postDelayed(new Runnable(){
            public void run(){
                try {
                    valueView.setText(greenhouse.getHumidity() + " %");
                } catch (IOException e) {
                    valueView.setText("N/A");
                }

//                handler.postDelayed(this, 3000);
            }
        }, 0);
    }

    private void setMode() {
        if(mode) {
            int tmp = seekBarView.getProgress();
            seekBarView.setMax(100);
            seekBarView.setProgress(tmp * 100 / 45);
            modeView.setText("auto (" + Integer.toString(seekBarView.getProgress()) + "%)");
        }
        else {
            int tmp = seekBarView.getProgress();
            seekBarView.setMax(45);
            seekBarView.setProgress(tmp * 45 / 100);
            modeView.setText("manual (" + Integer.toString(seekBarView.getProgress()) + "°)");
        }
    }
}
