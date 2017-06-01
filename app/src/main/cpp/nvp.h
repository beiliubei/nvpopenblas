//
// Created by liubei on 2017/6/1.
//

#ifndef NVPOPENBLAS_NVP_H_H
#define NVPOPENBLAS_NVP_H_H

#include <android/log.h>

#define NVP_LOG_TAG "NVPJNI"
#define NVPLOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, NVP_LOG_TAG, __VA_ARGS__))
#define NVPLOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, NVP_LOG_TAG, __VA_ARGS__))
#define NVPLOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, NVP_LOG_TAG, __VA_ARGS__))

#endif //NVPOPENBLAS_NVP_H_H
