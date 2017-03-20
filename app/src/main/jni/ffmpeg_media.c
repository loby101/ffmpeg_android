//
// Created by LOBY on 17/3/18.
//
#include <string.h>
#include <jni.h>
#include "libavcodec/avcodec.h"

jstring Java_com_loby_ffmpeg_1android_FFmpegMedia_getFFmpegConfiguration( JNIEnv* env, jobject thiz )

{
    char info[10000] = { 0 };
    sprintf(info, "%s\n", avcodec_configuration());
    return (*env)->NewStringUTF(env, info);
}

void Java_com_loby_ffmpeg_1android_FFmpegMedia_watermarking( JNIEnv* env, jobject thiz , jstring video_path, jstring png_path)
{
    char info[1000] = {0};
}

