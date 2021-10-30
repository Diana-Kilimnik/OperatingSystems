#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct thread_arg
{
    char *name;
    char *str;
    int num;
};

void *func(void *arg)
{
    struct thread_arg thrarg = *(struct thread_arg *)arg;
    for (int i = 0; i < thrarg.num; i++)
    {
        fprintf(stderr, "%s. %s %d\n", thrarg.name, thrarg.str, i + 1);
    }
}

int main()
{
    pthread_t thread1, thread2, thread3, thread4;
    struct thread_arg thrarg1 = {"Thread1", "Привiт", 5};
    struct thread_arg thrarg2 = {"Thread2", "Привет", 3};
    struct thread_arg thrarg3 = {"Thread3", "Hallo", 4};
    struct thread_arg thrarg4 = {"Thread4", "Hello", 2};

    if (pthread_create(&thread1, NULL, &func, &thrarg1) != 0)
    {
        fprintf(stderr, "Error : Thread1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, &func, &thrarg2) != 0)
    {
        fprintf(stderr, "Error : Thread2\n");
        return 1;
    }
    if (pthread_create(&thread3, NULL, &func, &thrarg3) != 0)
    {
        fprintf(stderr, "Error : Thread3\n");
        return 1;
    }
    if (pthread_create(&thread4, NULL, &func, &thrarg4) != 0)
    {
        fprintf(stderr, "Error : Thread4\n");
        return 1;
    }

    sleep(1);

    return 0;
}