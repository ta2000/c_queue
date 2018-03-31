#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test
{
    int number;
    char letter;
};

void structure_test()
{
    printf("Queue test\n");

    struct queue my_queue;
    queue_init(&my_queue, sizeof(struct test), 10);

    struct test test;

    printf("\nAdding...\n");
    for (int i=0; i<3; i++) {
        test.number = i;
        test.letter = (char)i+65;
        queue_enqueue(&my_queue, &test);
        printf("%d, %c\n", i, (char)i+65);
    }

    printf("\nRetrieving...\n");
    while (!queue_empty(&my_queue)) {
        struct test new;
        queue_dequeue(&my_queue, &new);
        printf("%d, %c\n", new.number, new.letter);
    }

    queue_destroy(&my_queue);
}

void pointer_test()
{
    printf("Queue test\n");

    struct queue my_queue;
    queue_init(&my_queue, sizeof(int*), 10);
    printf("Address of queue: %p\n", my_queue.data);

    int* refs = malloc(20);
    int numbers[] = {220, 1000, 820, 440, 160};
    memcpy(refs, numbers, sizeof(numbers));

    int* data;

    printf("\nAdding...\n");
    for (int i=0; i<5; i++) {
        data = &refs[i];
        queue_enqueue(&my_queue, &data);
        printf("%p\n", data);
    }

    printf("\nRetrieving...\n");
    for (int i=0; i<3; i++) {
        int* test;
        queue_dequeue(&my_queue, &test);
        printf("%p\n", test);
    }

    printf("\nAdding...\n");
    for (int i=0; i<2; i++) {
        data = &refs[i];
        queue_enqueue(&my_queue, &data);
        printf("%p\n", data);
    }

    printf("\nRetrieving...\n");
    while (!queue_empty(&my_queue)) {
        int* test;
        queue_dequeue(&my_queue, &test);
        printf("%p\n", test);
    }

    queue_destroy(&my_queue);
}

int main()
{
    structure_test();
    //pointer_test();

    return 0;
}
