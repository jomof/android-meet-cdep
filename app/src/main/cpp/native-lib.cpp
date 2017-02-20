#include <jni.h>
#include <string>
#include <sqlite3.h>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <vectorial/simd4f.h>

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

extern "C"
jstring
Java_com_example_jomof_myapplication_ExampleInstrumentedTest_checkBoost(
        JNIEnv* env,
        jobject /* this */) {
    using namespace boost::numeric::ublas;
    matrix<double> m (3, 3);

    for (unsigned i = 0; i < m.size1 (); ++ i) {
        for (unsigned j = 0; j < m.size2 (); ++ j){
            m (i, j) = 3 * i + j;
        }
    }
    std::string result = "Boost OK";
    return env->NewStringUTF(result.c_str());
}

extern "C"
jstring
Java_com_example_jomof_myapplication_ExampleInstrumentedTest_checkVectorial(
        JNIEnv* env,
        jobject /* this */) {
    auto v = simd4f_add( simd4f_create(1,2,3,4), simd4f_create(1,2,3,4));
    float z = simd4f_get_z(v);
    std::string result = "Vectorial OK";
    return env->NewStringUTF(result.c_str());
}