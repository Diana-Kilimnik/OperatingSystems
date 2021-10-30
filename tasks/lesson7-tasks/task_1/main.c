#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *child_func()
{
    for (int i = 1; i < 11; i++)
    {
        printf("Child Thread. Iteration: %d\n", i);
        sleep(1);
    }
}

int main()
{
    pthread_t thread;
    int status = pthread_create(&thread, NULL, &child_func, NULL);
    if (status != 0)
    {
        fprintf(stderr, "Error!\n");
        return 1;
    }

    for (int i = 1; i < 11; i++)
    {
        printf("Main Thread. Iteration: %d\n", i);
        sleep(1);
    }

    return 0;
}