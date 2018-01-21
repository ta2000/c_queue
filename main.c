#include "queue.h"

#include <stdio.h>

struct test
{
    int num1;
    char char1;
};

int main()
{
    printf("Queue test\n\n");

    struct queue my_queue;
    queue_init(&my_queue, sizeof(struct test), 10);

    printf("Adding...\n");
    struct test test;
    for (int i=0; i<7; i++) {
        test.num1 = i;
        test.char1 = (char)i+65;
        queue_add(&my_queue, &test);
        printf("%d, %c\n", i, (char)i+65);
    }

    printf("\nRetrieving...\n");
    for (int i=0; i<5; i++) {
        //int new = *((int*)queue_retrieve(&int_queue));
        struct test new = *((struct test*)queue_retrieve(&my_queue));
        printf("%d, %c\n", new.num1, new.char1);
    }

    printf("\nAdding...\n");
    for (int i=0; i<8; i++) {
        test.num1 = i;
        test.char1 = (char)i+65;
        queue_add(&my_queue, &test);
        printf("%d, %c\n", i, (char)i+65);
    }

    printf("\nRetrieving...\n");
    for (int i=0; !queue_empty(&my_queue); i++) {
        //int new = *((int*)queue_retrieve(&int_queue));
        struct test new = *((struct test*)queue_retrieve(&my_queue));
        printf("%d, %c\n", new.num1, new.char1);
    }

    queue_destroy(&my_queue);

    return 0;
}
