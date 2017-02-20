#include <jni.h>
#include <string>
#include <sqlite3.h>

extern "C"
jstring
Java_com_example_jomof_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello Android CDep.";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
jstring
Java_com_example_jomof_myapplication_ExampleInstrumentedTest_checkSqlite(
        JNIEnv* env,
        jobject /* this */) {
    if (SQLITE_OK == sqlite3_initialize()) {
        std::string result = "SQLITE_OK";
        return env->NewStringUTF(result.c_str());
    }
    std::string result = "not SQLITE_OK";
    return env->NewStringUTF(result.c_str());
}
