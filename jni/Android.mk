LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := cpu-detect
LOCAL_SRC_FILES := cpu-detect.cpp

LOCAL_STATIC_LIBRARIES := cpufeatures
include $(BUILD_SHARED_LIBRARY)


$(call import-module,android/cpufeatures)