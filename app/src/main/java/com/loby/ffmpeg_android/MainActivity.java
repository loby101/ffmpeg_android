package com.loby.ffmpeg_android;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.os.StrictMode;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MainActivity extends Activity {

    private Button configuration;
    private Button format;
    private Button run;
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
        run = (Button) findViewById(R.id.btn_run);
        run.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                video();
            }
        });
    }

    private void video(){
        //ffmpeg -i input_file -vcodec copy -an output_file_video
        ExecutorService thread = Executors.newCachedThreadPool();
        thread.execute(new Runnable() {
            @Override
            public void run() {
                String[] commands = new String[5];
                commands[0] = "ffmpeg";
                commands[1] = "-i";
                commands[2] = "/sdcard/rollcap/rollcap_video/ROLLCAP_20170220111138961_1080p.mp4";
                commands[3] = "-y";
                commands[4] = "/sdcard/rollcap/rollcap_video/output.mp4";
                int result = FFmpegMedia.run(commands);
            }
        });

    }
}
