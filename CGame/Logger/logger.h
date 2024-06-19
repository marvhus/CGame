#ifndef __H_LOGGING__
#define __H_LOGGING__

// NOTE(mvh): The availiable log levels. (the ones marked with Don't print are there to help you set a minimum level, and not to actually print something.)
typedef enum {
    CG_LOG_ALL = 0, // Don't print.
    CG_LOG_DEBUG,
    CG_LOG_INFO,
    CG_LOG_WARNING,
    CG_LOG_ERROR,
    CG_LOG_NONE // Don't print.
} CG_Log_Level;

// Log a message at the given level.
void cg_log_log(CG_Log_Level log_level, const char *msg);

// Set the minimum log level for the message to be printed.
void cg_log_minimum(CG_Log_Level log_level);

#endif
