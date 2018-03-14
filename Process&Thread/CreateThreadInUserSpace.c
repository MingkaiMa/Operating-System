#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
    printf("hello World. Greetings from thread %d", (int)tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;

    for(i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Main here. Creating thread %d", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);

        if(status != 0)
        {
            printf("Oops. pthread_create returned error code %d", status);
        }
    }

    exit(NULL);
}