//
// Created by LOBY on 17/3/18.
//
#include <string.h>
#include <jni.h>
#include "libavcodec/avcodec.h"
#include "watermarking.h"

jstring Java_com_loby_ffmpeg_1android_FFmpegMedia_getFFmpegConfiguration( JNIEnv* env, jobject thiz )
{
    char info[10000] = { 0 };
    sprintf(info, "%s\n", avcodec_configuration());
    return (*env)->NewStringUTF(env, info);
}

void Java_com_loby_ffmpeg_1android_FFmpegMedia_watermarking( JNIEnv* env, jobject thiz , jstring video_path, jstring png_path, jstring out_path)
{
    char* _infile = (char*)(*env)->GetStringUTFChars(env,video_path,JNI_FALSE);
    char* _inpngfile = (char*)(*env)->GetStringUTFChars(env,png_path,JNI_FALSE);
    char* _outfile = (char*)(*env)->GetStringUTFChars(env,out_path,JNI_FALSE);
    int ret = watermarking(env,thiz,_infile,_inpngfile,_outfile);
}

