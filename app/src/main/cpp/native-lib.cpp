#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "nvp_gemm.h"

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
        jint to) {
    env = jenv;
    cls = jenv->FindClass("nextvpu/com/nvpopenblas/MainActivity");
    methodid = jenv->GetStaticMethodID(cls, "callback", "(Ljava/lang/String;)V");

    nvp_openblas_gemm_test(to, callback);
}

#ifdef __cplusplus
}
#endif