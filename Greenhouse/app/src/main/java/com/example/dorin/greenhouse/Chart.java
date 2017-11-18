package com.example.dorin.greenhouse;

import android.support.v7.app.AppCompatActivity;
import android.webkit.WebView;

public class Chart {
    private final WebView webView;

    public Chart(AppCompatActivity parent) {
        webView = (WebView)parent.findViewById(R.id.webView);
        webView.getSettings().setJavaScriptEnabled(true);
        webView.loadUrl("file:///android_asset/index.html");
    }
}
