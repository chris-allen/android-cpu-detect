#include <jni.h>
#include <cpu-features.h>
#include "vv-log.h"


JNIEXPORT void JNICALL Java_com_cpudetect_android_CPU_getCpuInfo__
(
	JNIEnv* env, jclass thiz
) {
    AndroidCpuFamily family;
    family = android_getCpuFamily();

    if (family == ANDROID_CPU_FAMILY_ARM) {
        LOG_I("jni_player_init CPU family is ANDROID_CPU_FAMILY_ARM");
    } else if (family == ANDROID_CPU_FAMILY_ARM64) {
        LOG_I("jni_player_init CPU family is ANDROID_CPU_FAMILY_ARM64");
    } else if (family == ANDROID_CPU_FAMILY_X86) {
        LOG_I("jni_player_init CPU family is ANDROID_CPU_FAMILY_X86");
    } else if (family == ANDROID_CPU_FAMILY_X86_64) {
        LOG_I("jni_player_init CPU family is ANDROID_CPU_FAMILY_X86_64");
    } else {
        LOG_I("jni_player_init CPU family is %d", family);
    }
}
