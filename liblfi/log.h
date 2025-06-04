#pragma once

#ifdef __ANDROID__
#include <android/log.h>
#endif

#ifdef __ANDROID__
#define LOG_TAG "liblfi"
#define LOG(...) \
((void)__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__))
#else  //  __ANDROID__
#define LOG(...) \
do {            \
} while (0)
#endif  //  __ANDROID__
