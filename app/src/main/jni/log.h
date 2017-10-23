#ifndef AUDIOAGNOSTICHOST_LOG_H
#define AUDIOAGNOSTICHOST_LOG_H

#include <android/log.h>

#define DEFAULT_LOG_TAG "swisshear"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, DEFAULT_LOG_TAG, __VA_ARGS__)
#define LOGD_T(LOG_TAG, ...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, DEFAULT_LOG_TAG, __VA_ARGS__)
#define LOGW_T(LOG_TAG, ...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, DEFAULT_LOG_TAG, __VA_ARGS__)
#define LOGE_T(LOG_TAG, ...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#endif //AUDIOAGNOSTICHOST_LOG_H