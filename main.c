#include "queue.h"

#include <stdio.h>

int main()
{
    printf("Queue test\n\n");

    struct queue int_queue;
    queue_init(&int_queue, sizeof(int), 16);

    printf("Adding...\n");
    for (int i=0; !queue_full(&int_queue); i++) {
        queue_add(&int_queue, &i);
        printf("%d\n", i);
    }

    printf("\nRetrieving...\n");
    for (int i=0; !queue_empty(&int_queue); i++) {
        //int new = *((int*)queue_retrieve(&int_queue));
        int new = *queue_retrieve(&int_queue);
        printf("%d\n", new);
    }

    queue_destroy(&int_queue);

    return 0;
}
