/**
 * Common android logging macros for volar jni code
 */

#ifndef VV_LOG_H__GUARD
#define VV_LOG_H__GUARD

#include <android/log.h>
#include <stdio.h>

#define VVLOG_VERBOSE 1
#define VVLOG_DEBUG 2
#define VVLOG_INFO 3
#define VVLOG_WARNING 4
#define VVLOG_ERROR 5
#define VVLOG_LEVEL VVLOG_ERROR

#define LOG_V(...) if(VVLOG_LEVEL <= VVLOG_VERBOSE) __android_log_print(ANDROID_LOG_VERBOSE, __FILE__ , __VA_ARGS__)
#define LOG_D(...) if(VVLOG_LEVEL <= VVLOG_DEBUG)                                                     \
    do {                                                                \
        char buf[1024];                                                 \
        snprintf(buf, 1024, __VA_ARGS__);                               \
        __android_log_print(ANDROID_LOG_DEBUG  , __FILE__, "[line:%d] %s", __LINE__, buf); \
    } while (0)

#define LOG_I(...) if(VVLOG_LEVEL <= VVLOG_INFO) __android_log_print(ANDROID_LOG_INFO   , __FILE__, __VA_ARGS__)
#define LOG_W(...) if(VVLOG_LEVEL <= VVLOG_WARNING) __android_log_print(ANDROID_LOG_WARN   , __FILE__, __VA_ARGS__)
#define LOG_E(...) if(VVLOG_LEVEL <= VVLOG_ERROR) __android_log_print(ANDROID_LOG_ERROR   , __FILE__, __VA_ARGS__)

#endif // VV_LOG_H__GUARD
