#ifndef __H_EVENT__
#define __H_EVENT__

// The different kinds of events.
typedef enum {
    CG_EVENT_NONE = 0,
} CG_Event_Kind;

// Information about the given event.
typedef struct {
    CG_Event_Kind kind;
} CG_Event;

#endif
