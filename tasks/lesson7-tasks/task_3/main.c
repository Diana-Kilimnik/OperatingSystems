#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define NUM 3

void *func()
{
    for (int i = 1; i < 11; i++)
    {
        printf("Child Thread. Iteration: %d\n", i);
        sleep(1);
    }
}

void *randomnum()
{
    while (1)
    {
        int n = rand() % 7;
        printf("Random gen. Num: %d\n", n);

        if (NUM == n)
        {
            fprintf(stderr, "Random gen. Got right num!\n");
            pthread_exit(NULL);
        }
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, &func, NULL) != 0)
    {
        fprintf(stderr, "Error: Thread 1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, &randomnum, NULL) != 0)
    {
        fprintf(stderr, "Error: Thread 2\n");
        return 1;
    }

    if (pthread_join(thread1, NULL) != 0)
    {
        fprintf(stderr, "Join error: Thread 1\n");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0)
    {
        fprintf(stderr, "Join error: Thread 2\n");
        return 1;
    }

    printf("Main Thread. All the threads finished their work!\n");
    return 0;
}