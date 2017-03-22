package com.loby.ffmpeg_android;

/**
 * Created by LOBY on 17/3/18.
 */

public class FFmpegMedia {

    static {
        System.loadLibrary("avutil-54");
        System.loadLibrary("swresample-1");
        System.loadLibrary("avcodec-56");
        System.loadLibrary("avformat-56");
        System.loadLibrary("swscale-3");
        System.loadLibrary("avfilter-5");
        System.loadLibrary("ffmpeg-android");
    }

    /**
     * 获取FFmpeg的配置信息
     */
    public static native String configurationinfo();

    public static native String avformatinfo();

}
