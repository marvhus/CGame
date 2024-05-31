#ifndef __H_EVENT__
#define __H_EVENT__

typedef enum {
    EVN_NONE,
} Event_Kind;

typedef struct {
    Event_Kind kind;
} Event;

#endif
