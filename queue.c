#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void queue_init(struct queue* queue, size_t element_size, size_t max_elements)
{
    queue->element_size = element_size;
    queue->max_elements = max_elements;
    queue->data = malloc(element_size * max_elements);
    queue->start = queue->data;
    queue->end = queue->start;
}

void queue_add(struct queue* queue, void* value)
{
    size_t in_use = (size_t)(queue->end - queue->start) / queue->element_size;
    assert(in_use < queue->max_elements);

    memcpy(queue->end, value, queue->element_size);
    queue->end += queue->element_size;
}

char* queue_retrieve(struct queue* queue)
{
    assert(queue->start < queue->end);

    queue->start += queue->element_size;
    return queue->start - queue->element_size;
}

void queue_destroy(struct queue* queue)
{
    free(queue->data);
}

bool queue_full(struct queue* queue)
{
    size_t in_use = (size_t)(queue->end - queue->start) / queue->element_size;
    return in_use == queue->max_elements;
}

bool queue_empty(struct queue* queue)
{
    return queue->start == queue->end;
}
