//
// Created by liubei on 2017/6/1.
//

#ifndef ANGLE_EYE_NVP_GEMM_H
#define ANGLE_EYE_NVP_GEMM_H

#include "jni.h"

typedef void(nvp_callback)(char *str);

void nvp_openblas_gemm_test(int to, nvp_callback *cb);

#endif //ANGLE_EYE_NVP_GEMM_H
