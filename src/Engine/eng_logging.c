#include "logging.h"
#include "eng_logging_internal.h"

#include <stdio.h>

Log_Level minimum_log_level = LL_INFO;

void eng_log(Log_Level log_level, const char *msg)
{
    if (log_level < minimum_log_level) return;

    switch (log_level)
    {
        case LL_DEBUG: {
            printf("[DEBUG] %s\n", msg);
        } break;
        case LL_INFO: {
            printf("[INFO] %s\n", msg);
        } break;
        case LL_WARNING: {
            printf("[WARN] %s\n", msg);
        } break;
        case LL_ERROR: {
            printf("[ERROR] %s\n", msg);
        } break;
        default: {
            printf("[LOGGING] Unsupported log level %d.\n", log_level);
        }
    }
}

void eng_log_minimum(Log_Level log_level)
{
    minimum_log_level = log_level;
}
