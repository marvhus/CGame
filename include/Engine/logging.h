#ifndef __H_LOGGING__
#define __H_LOGGING__

typedef enum {
    LL_DEBUG   = 0,
    LL_INFO    = 1,
    LL_WARNING = 2,
    LL_ERROR   = 3,
} Log_Level;

void eng_log(Log_Level log_level, const char *msg);
void eng_log_minimum(Log_Level log_level);

#endif
