#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>
#include <stddef.h>

struct queue
{
    char* data;
    char* start;
    char* end;
    size_t max_elements;
    size_t element_size;
};

void queue_init(
    struct queue* queue,
    size_t element_size,
    size_t max_elements
);

void queue_add(
    struct queue* queue,
    void* data
);

char* queue_retrieve(
    struct queue* queue
);

void queue_destroy(
    struct queue* queue
);

bool queue_full(
    struct queue* queue
);

bool queue_empty(
    struct queue* queue
);

#endif