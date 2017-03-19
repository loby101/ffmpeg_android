package com.loby.ffmpeg_android;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity {

    private Button configuration;
    private TextView message;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
    }

    private void initView(){
        configuration = (Button) findViewById(R.id.btn_configuration);
        message = (TextView) findViewById(R.id.tv_message);
        configuration.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String config = FFmpegMedia.GetFFmpegConfiguration();
                message.setText(config);
            }
        });
    }
}
