#define LOGGING_ENABLED
#define COLORED_LOGGING_ENABLED 

/**
 *  0 - no log output
 *  1 - only errors
 *  2 - errors and warnings
 *  3 - all above + information
 *  4 - all above + debug logs
 *  5 - logging is fully enabled
 */
#define LOGGING_VERBOSITY 5

#define LOGGING_CLASS Serial

#ifdef LOGGING_ENABLED
    #ifdef COLORED_LOGGING_ENABLED
        #define COLOR_RED "\033[31m"
        #define COLOR_YELLOW "\033[33m"
        #define COLOR_GREEN "\033[32m"
        #define COLOR_MAGENTA "\033[35m"
        #define COLOR_RESET "\033[0m"

        #if LOGGING_VERBOSITY == 5
        #define LOGV(fmt, ...) LOGGING_CLASS.printf(COLOR_YELLOW "[VERBOSE] " fmt COLOR_RESET "\n", ##__VA_ARGS__)
        #else
        #define LOGV(fmt, ...)
        #endif

        #if LOGGING_VERBOSITY >= 4
        #define LOGD(fmt, ...) LOGGING_CLASS.printf(COLOR_MAGENTA "[DEBUG] " fmt COLOR_RESET "\n", ##__VA_ARGS__)
        #else
        #define LOGD(fmt, ...)
        #endif

        #if LOGGING_VERBOSITY >= 3
        #define LOGI(fmt, ...) LOGGING_CLASS.printf(COLOR_GREEN "[INFO] " fmt COLOR_RESET "\n", ##__VA_ARGS__)
        #else
        #define LOGI(fmt, ...)
        #endif

        #if LOGGING_VERBOSITY >= 2
        #define LOGW(fmt, ...) LOGGING_CLASS.printf(COLOR_YELLOW "[WARNING] " fmt COLOR_RESET "\n", ##__VA_ARGS__)
        #else
        #define LOGW(fmt, ...)
        #endif

        #if LOGGING_VERBOSITY >= 1
        #define LOGE(fmt, ...) LOGGING_CLASS.printf(COLOR_RED "[ERROR] " fmt COLOR_RESET "\n", ##__VA_ARGS__)
        #else
        #define LOGE(fmt, ...)
        #endif

    #else
        #if LOGGING_VERBOSITY >= 5
        #define LOGV(fmt, ...) LOGGING_CLASS.printf("[VERBOSE] " fmt "\n", ##__VA_ARGS__)
        #else
        #define LOGV(fmt, ...)
        #endif

        #if LOGGING_VERBOSITY >= 4
        #define LOGD(fmt, ...) LOGGING_CLASS.printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
        #else
        #define LOGD(fmt, ...)
        #endif

        #if LOGGING_VERBOSITY >= 3
        #define LOGI(fmt, ...) LOGGING_CLASS.printf("[INFO] " fmt "\n", ##__VA_ARGS__)
        #else
        #define LOGI(fmt, ...)
        #endif

        #if LOGGING_VERBOSITY >= 2
        #define LOGW(fmt, ...) LOGGING_CLASS.printf("[WARNING] " fmt "\n", ##__VA_ARGS__)
        #else
        #define LOGW(fmt, ...)
        #endif

        #if LOGGING_VERBOSITY >= 1
        #define LOGE(fmt, ...) LOGGING_CLASS.printf("[ERROR] " fmt "\n", ##__VA_ARGS__)
        #else
        #define LOGE(fmt, ...)
        #endif
    #endif
#else
    #define LOGV(fmt, ...)
    #define LOGD(fmt, ...)
    #define LOGI(fmt, ...)
    #define LOGW(fmt, ...)
    #define LOGE(fmt, ...)
#endif