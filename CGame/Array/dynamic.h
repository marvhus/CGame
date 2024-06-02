#ifndef __H_CG_ARRAY_DYNAMIC__
#define __H_CG_ARRAY_DYNAMIC__

#include <assert.h>
#include <stdio.h>

// Inspired by how Tsoding does his dynamic arrays.

// Reallocate the array to have the size of the given capacity.
#define CG_DA_RESIZE(arr, new_capacity)                                         \
    do {                                                                        \
        (arr).capacity = new_capacity;                                          \
        (arr).data = realloc((arr).data, sizeof(*(arr).data) * new_capacity);   \
        assert((arr).data != NULL && "Buy more ram!");                          \
    } while (false)

// Add a new item to the array, and if not enough space, allocate more space.
#define CG_DA_APPEND(arr, item)                             \
    do {                                                    \
        if ((arr).count + 1 >= (arr).capacity) {            \
            CG_DA_RESIZE(arr, ((arr).capacity + 1) * 2);    \
        }                                                   \
        (arr).data[(arr).count] = item;                     \
        (arr).count += 1;                                   \
    } while (false)

#endif
