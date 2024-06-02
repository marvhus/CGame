#include <CGame/Logger/logger.h>
#include "eng_logger_internal.h"

#include <stdio.h>

CG_Log_Level minimum_log_level = CG_LOG_INFO;

void cg_log_log(CG_Log_Level log_level, const char *msg)
{
    if (log_level < minimum_log_level) return;

    switch (log_level)
    {
        case CG_LOG_DEBUG: {
            printf("[DEBUG] %s\n", msg);
        } break;
        case CG_LOG_INFO: {
            printf("[INFO] %s\n", msg);
        } break;
        case CG_LOG_WARNING: {
            printf("[WARN] %s\n", msg);
        } break;
        case CG_LOG_ERROR: {
            printf("[ERROR] %s\n", msg);
        } break;
        default: {
            printf("[LOGGING] Unsupported log level %d.\n", log_level);
        }
    }
}

void cg_log_minimum(CG_Log_Level log_level)
{
    minimum_log_level = log_level;
}
