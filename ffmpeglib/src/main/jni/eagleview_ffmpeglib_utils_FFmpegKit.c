//
// Created by Administrator on 2018/1/17 0017.
//

#include <stdio.h>
#include"eagleview_ffmpeglib_utils_FFmpegKit.h"
#include "ffmpeg.h"
#include "logjam.h"

JNIEXPORT jint JNICALL Java_eagleview_ffmpeglib_utils_FFmpegKit_run
(JNIEnv *env, jclass obj, jobjectArray commands){
    //FFmpeg av_log() callback
    int argc = (*env)->GetArrayLength(env, commands);
    char *argv[argc];

    LOGD("Kit argc %d\n", argc);
    int i;
    for (i = 0; i < argc; i++) {
        jstring js = (jstring) (*env)->GetObjectArrayElement(env, commands, i);
        argv[i] = (char*) (*env)->GetStringUTFChars(env, js, 0);
        LOGD("Kit argv %s\n", argv[i]);
    }
    return run(argc, argv);
}