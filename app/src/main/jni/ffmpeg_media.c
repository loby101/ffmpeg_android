//
// Created by LOBY on 17/3/18.
//
#include <string.h>
#include <stdio.h>
#include <ffmpeg.h>

#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libavutil/avutil.h"
#include "libavfilter/avfilter.h"

#ifdef ANDROID
#include <jni.h>
#include <android/log.h>
#define LOGE(format, ...)  __android_log_print(ANDROID_LOG_ERROR, "(>_<)", format, ##__VA_ARGS__)
#else
#define LOGE(format, ...)  printf("(>_<) " format "\n", ##__VA_ARGS__)
#endif

jstring Java_com_loby_ffmpeg_1android_FFmpegMedia_configurationinfo( JNIEnv* env, jobject thiz )
{
    char info[10000] = { 0 };
    sprintf(info, "%s\n", avcodec_configuration());
    return (*env)->NewStringUTF(env, info);
}

jstring Java_com_loby_ffmpeg_1android_FFmpegMedia_avformatinfo( JNIEnv* env, jobject thiz )
{
    char info[40000] = { 0 };
    av_register_all();
    AVInputFormat *if_temp = av_iformat_next(NULL);
    AVOutputFormat *of_temp = av_oformat_next(NULL);
    //Input
    while(if_temp!=NULL){
        sprintf(info, "%s[In ][%10s]\n", info, if_temp->name);
        if_temp=if_temp->next;
    }
    //Output
    while (of_temp != NULL){
        sprintf(info, "%s[Out][%10s]\n", info, of_temp->name);
        of_temp = of_temp->next;
    }
    //LOGE("%s", info);
    return (*env)->NewStringUTF(env, info);
}

void custom_log(void *ptr, int level, const char* fmt, va_list vl)
{
    FILE *fp=fopen("/sdcard/rollcap/av_log.txt","a+");
    if(fp){
        vfprintf(fp,fmt,vl);
        fflush(fp);
        fclose(fp);
    }
}

jint Java_com_loby_ffmpeg_1android_FFmpegMedia_run( JNIEnv* env, jobject thiz, jobjectArray args )
{
    av_log_set_callback(custom_log);

    int i = 0;
    int argc = 0;
    char **argv = NULL;
    jstring *strr = NULL;

    if (args != NULL) {
    	argc = (*env)->GetArrayLength(env, args);
    	argv = (char **) malloc(sizeof(char *) * argc);
    	strr = (jstring *) malloc(sizeof(jstring) * argc);

    	for (i = 0; i < argc; ++i) {
    		strr[i] = (jstring)(*env)->GetObjectArrayElement(env, args, i);
    		argv[i] = (char *)(*env)->GetStringUTFChars(env, strr[i], 0);
    	}
    }
    int result = run(argc, argv);

    for (i = 0; i < argc; ++i) {
    	(*env)->ReleaseStringUTFChars(env, strr[i], argv[i]);
    }
    free(argv);
    free(strr);

    return result == 0;
}
