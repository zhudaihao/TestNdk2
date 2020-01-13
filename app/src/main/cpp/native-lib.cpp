#include <jni.h>
#include <string>
#include <android/log.h>

//我们库的函数是.c 在c++中调用需要配置混合编译

//错误配置
//extern int get();

//正确配置
extern "C" {
int get();
}


extern "C" JNIEXPORT jstring JNICALL
Java_cn_zdh_testndk2_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    //调用添加库的函数
    __android_log_print(ANDROID_LOG_DEBUG, "*ZDH", "get() %d", get());

    return env->NewStringUTF(hello.c_str());
}
