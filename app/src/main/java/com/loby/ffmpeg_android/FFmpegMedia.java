package com.loby.ffmpeg_android;

/**
 * Created by LOBY on 17/3/18.
 */

public class FFmpegMedia {

    static {
        System.loadLibrary("avutil");
        System.loadLibrary("swresample");
        System.loadLibrary("avcodec");
        System.loadLibrary("avformat");
        System.loadLibrary("swscale");
        System.loadLibrary("avfilter");
        System.loadLibrary("ffmpeg-android");
    }

    /**
     * 获取FFmpeg的配置信息
     */
    public static native String configurationinfo();

    /**
     * format信息
     */
    public static native String avformatinfo();

}
