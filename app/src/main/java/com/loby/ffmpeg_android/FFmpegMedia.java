package com.loby.ffmpeg_android;

/**
 * Created by LOBY on 17/3/18.
 */

public class FFmpegMedia {

    static {
        System.loadLibrary("avutil-55");
        System.loadLibrary("swresample-2");
        System.loadLibrary("avcodec-57");
        System.loadLibrary("avformat-57");
        System.loadLibrary("swscale-4");
        System.loadLibrary("avfilter-6");
        System.loadLibrary("avdevice-57");
        System.loadLibrary("ffmpeg-android");
    }

    /**
     * 获取FFmpeg的配置信息
     */
    public static native String getFFmpegConfiguration();

    /**
     * Filter   添加水印
     */
    public static native void watermarking(String videoPath,String pngPath);

}
