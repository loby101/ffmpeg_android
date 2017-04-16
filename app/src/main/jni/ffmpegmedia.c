//
// Created by LOBY on 17/3/18.
//
#include <stdio.h>
#include <jni.h>
#include "ffmpeg.h"

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>


#include "ffmpegcustom.h"

//Output FFmpeg's av_log()
void custom_log(void *ptr, int level, const char *fmt, va_list vl) {
    FILE *fp = fopen("/storage/emulated/0/av_log.txt", "a+");
    if (fp) {
        vfprintf(fp, fmt, vl);
        fflush(fp);
        fclose(fp);
    }
}

jint Java_com_loby_ffmpeg_1android_FFmpegMedia_run(JNIEnv *env, jobject thiz, jobjectArray commands, jint cmdnum) {
    int argc=cmdnum;
    char** argv=(char**)malloc(sizeof(char*)*cmdnum);
    int i=0;
    for(i=0;i<cmdnum;i++)
    {
      jstring string=(*env)->GetObjectArrayElement(env,commands,i);
      const char* tmp=(*env)->GetStringUTFChars(env,string,0);
      argv[i]=(char*)malloc(sizeof(char)*1024);
      strcpy(argv[i],tmp);
    }
    return run(cmdnum,argv);
    for(i=0;i<cmdnum;i++){
      free(argv[i]);
    }
    free(argv);
}

jstring Java_com_loby_ffmpeg_1android_FFmpegMedia_configurationinfo(JNIEnv *env, jobject thiz) {
    char info[10000] = {0};
    sprintf(info, "%s\n", avcodec_configuration());
    return (*env)->NewStringUTF(env, info);
}

jstring Java_com_loby_ffmpeg_1android_FFmpegMedia_avformatinfo(JNIEnv *env, jobject thiz) {
    char info[40000] = {0};
    av_register_all();
    AVInputFormat *if_temp = av_iformat_next(NULL);
    AVOutputFormat *of_temp = av_oformat_next(NULL);
    //Input
    while (if_temp != NULL) {
        sprintf(info, "%s[In ][%10s]\n", info, if_temp->name);
        if_temp = if_temp->next;
    }
    //Output
    while (of_temp != NULL) {
        sprintf(info, "%s[Out][%10s]\n", info, of_temp->name);
        of_temp = of_temp->next;
    }
    //LOGE("%s", info);
    return (*env)->NewStringUTF(env, info);
}

jint Java_com_loby_ffmpeg_1android_FFmpegMedia_decode(JNIEnv *env, jobject thiz, jstring input_jstr,
                                                      jstring output_jstr) {
    char input_str[500] = {0};
    char output_str[500] = {0};

    sprintf(input_str, "%s", (*env)->GetStringUTFChars(env, input_jstr, NULL));
    sprintf(output_str, "%s", (*env)->GetStringUTFChars(env, output_jstr, NULL));

    //FFmpeg av_log() callback
    av_log_set_callback(custom_log);

    decode(input_str,output_str);

    return 0;
}

jint Java_com_loby_ffmpeg_1android_FFmpegMedia_filter(JNIEnv *env, jobject thiz, jstring input_jstr,
                                                      jstring output_jstr) {
    char input_str[500] = {0};
    char output_str[500] = {0};

    sprintf(input_str, "%s", (*env)->GetStringUTFChars(env, input_jstr, NULL));
    sprintf(output_str, "%s", (*env)->GetStringUTFChars(env, output_jstr, NULL));

    //FFmpeg av_log() callback
    av_log_set_callback(custom_log);

    int ret = filter(input_str,output_str);

    return ret;
}