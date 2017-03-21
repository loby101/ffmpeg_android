//
// Created by LOBY on 17/3/21.
//

#ifndef FFMPEG_ANDROID_WATERMARKING_H
#define FFMPEG_ANDROID_WATERMARKING_H
#include "jni.h"

int watermarking( JNIEnv* env, jobject thiz , const char* video_path, const char* png_path, const char* out_path);

#endif //FFMPEG_ANDROID_WATERMARKING_H
