#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "nvp_gemm.h"
#include "cblas.h"
#include <stdlib.h>

JNIEnv *env;
jmethodID methodid;
jclass cls;

void callback(char *str) {
    jstring jstr = env->NewStringUTF(str);
    env->CallStaticVoidMethod(cls, methodid, jstr);
    env->DeleteLocalRef(jstr);
}

extern "C"
void JNICALL
Java_nextvpu_com_nvpopenblas_MainActivity_stringFromJNI(
        JNIEnv *jenv,
        jobject,
        jint to,
        jint num) {
    env = jenv;
    cls = jenv->FindClass("nextvpu/com/nvpopenblas/MainActivity");
    methodid = jenv->GetStaticMethodID(cls, "callback", "(Ljava/lang/String;)V");

    openblas_set_num_threads(num);
    callback(openblas_get_config());
    callback("\n");

    callback(openblas_get_corename());
    callback("\n");

    int numthread = openblas_get_num_threads();
    int numProc = openblas_get_num_procs();
    int parallel = openblas_get_parallel();
    char * ss = (char *)malloc(1024);
    sprintf(ss, "numthread: %d numProc: %d parallel: %d", numthread, numProc, parallel);
    callback(ss);
    callback("\n");
    free(ss);

    nvp_openblas_gemm_test(to, callback);
}

#ifdef __cplusplus
}
#endif