LOCAL_PATH := $(call my-dir)

# ==============
# plugin  module
# ==============
include $(CLEAR_VARS)
LOCAL_MODULE := plugin
LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_SRC_FILES := sample_plugin.c
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)