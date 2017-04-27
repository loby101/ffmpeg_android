package com.loby.ffmpeg_android;

/**
 * Created by LOBY on 17/3/18.
 */

public class FFmpegMedia {

    static {
        System.loadLibrary("ffmpeg-android");
    }

    /**
     * 运行FFmpeg命令
     */
    public native static int run(String[] commands, int argc);

    /**
     * 取消FFmpeg命令行任务
     * @return
     */
    public native static void cancel();

    /**
     * 获取FFmpeg的配置信息
     */
    public static native String configurationinfo();

    /**
     * format信息
     */
    public static native String avformatinfo();

    /**
     * 解码 (封装格式 to YUV)
     */
    public static native int decode(String inputurl, String outputurl);
}
