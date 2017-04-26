package com.loby.ffmpeg_android;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

    private Button configuration,format,common;
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
                String config = FFmpegMedia.configurationinfo();
                message.setText(config);
            }
        });
        format = (Button) findViewById(R.id.btn_format);
        format.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                message.setText(FFmpegMedia.avformatinfo());
            }
        });
        common = (Button) findViewById(R.id.btn_common);
        common.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(MainActivity.this,"start",Toast.LENGTH_SHORT).show();
                FFmpegMedia.decode("/sdcard/crop0426.mp4","/sdcard/test0426.yuv");
//                String[] commands = new String[5];
//                commands[0] = "ffmpeg";
//                commands[1] = "-i";
//                commands[2] = "/sdcard/rollcap/rollcap_video/ROLLCAP_20161108170201810_1080p.mp4";
//                commands[3] = "-y";
//                commands[4] = "/sdcard/output.avi";
//                int result = FFmpegMedia.run(commands,5);
                Toast.makeText(MainActivity.this,"end",Toast.LENGTH_SHORT).show();
            }
        });
    }
}
