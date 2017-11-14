package com.example.dorin.greenhouse;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Greenhouse greenhouse;

        Context context = getApplicationContext();
        CharSequence text = "Hello toast!";
        int duration = Toast.LENGTH_SHORT;

        Toast toast = Toast.makeText(context, text, duration);
        toast.show();

        System.out.println("--------------------------");

//        findViewById(android.R.id.content).findViewById(R.id.temperatureButton).setBackgroundColor(getResources().getColor(R.color.colorAccentRed));
    }
}
