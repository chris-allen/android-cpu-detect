#include <jni.h>
#include <cpu-features.h>
#include "vv-log.h"


/**
 * Returns a string conveying the architecture of the host device.
 * Possible return values are:
 *     armeabi-v6
 *     armeabi-v6vfp
 *     armeabi-v7a
 *     armeabi-v7a-neon
 *     armeabi-v7a-neon_64
 *     armeabi-v8
 *     armeabi-v8_64
 *     x86
 *     x86_64
 *     unknown
 */
JNIEXPORT jstring JNICALL Java_com_cpudetect_android_CPU_getArchString__
(
	JNIEnv* env, jclass thiz
) {
    AndroidCpuFamily family;
    family = android_getCpuFamily();

    uint64_t features;  
    features = android_getCpuFeatures();

    char *arch_str;

    if (family == ANDROID_CPU_FAMILY_ARM) {
        LOG_I("getCpuInfo CPU family is ANDROID_CPU_FAMILY_ARM");
        if (features & ANDROID_CPU_ARM_FEATURE_NEON) {
            if (
                features & ANDROID_CPU_ARM_FEATURE_AES ||
                features & ANDROID_CPU_ARM_FEATURE_PMULL ||
                features & ANDROID_CPU_ARM_FEATURE_SHA1 ||
                features & ANDROID_CPU_ARM_FEATURE_SHA2 ||
                features & ANDROID_CPU_ARM_FEATURE_CRC32
            ) {
                arch_str = "armeabi-v8";
            } else {
                arch_str = "armeabi-v7a-neon";
            }
        } else if (
            features & ANDROID_CPU_ARM_FEATURE_ARMv7
        ) {
            arch_str = "armeabi-v7a";
        } else if (
            features & ANDROID_CPU_ARM_FEATURE_VFPv2
        ) {
            arch_str = "armeabi-v6vfp";
        } else {
            arch_str = "armeabi-v6";
        }
    } else if (family == ANDROID_CPU_FAMILY_ARM64) {
        LOG_I("getCpuInfo CPU family is ANDROID_CPU_FAMILY_ARM64");
            if (
                features & ANDROID_CPU_ARM64_FEATURE_AES ||
                features & ANDROID_CPU_ARM64_FEATURE_PMULL ||
                features & ANDROID_CPU_ARM64_FEATURE_SHA1 ||
                features & ANDROID_CPU_ARM64_FEATURE_SHA2 ||
                features & ANDROID_CPU_ARM64_FEATURE_CRC32
            ) {
                arch_str = "armeabi-v8_64";
            } else {
                arch_str = "armeabi-v7a-neon_64";
            }
    } else if (family == ANDROID_CPU_FAMILY_X86) {
        LOG_I("getCpuInfo CPU family is ANDROID_CPU_FAMILY_X86");
            arch_str = "x86";
    } else if (family == ANDROID_CPU_FAMILY_X86_64) {
        LOG_I("getCpuInfo CPU family is ANDROID_CPU_FAMILY_X86_64");
            arch_str = "x86_64";
    } else {
        LOG_I("getCpuInfo CPU family is %d", family);
        arch_str = "unknown";
    }

    LOG_I("getCpuInfo CPU arch_str is '%s'", arch_str);
    return (*env)->NewStringUTF(env, arch_str);
}
