/**
 * Break down the code to analyse
 * how the threads are scheduled to CPU by the OS?
 * pick a particular C standard to compile a specify code.
 **/
/******************************************************************************
* FILE: hello_arg2.c
* USAGE: gcc -pthread -Wall hello_arg2.c 
* DESCRIPTION:
*   A "hello world" Pthreads program which demonstrates another safe way
*   to pass arguments to threads during thread creation.  In this case,
*   a structure is used to pass multiple arguments.
* ORIGINAL AUTHOR: Blaise Barney
* LAST REVISED: 11/05/19
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS	8

char *messages[NUM_THREADS];

struct thread_data {
   int	thread_id;
   int  sum;
   char *message;
};

struct thread_data thread_data_array[NUM_THREADS];

void *PrintHello(void *threadarg){
    int taskId, sum;
    char *hello_msg;
    struct thread_data *my_data;

    sleep(3);

    my_data = (struct thread_data *) threadarg;
    //decompose data of an element from array
    taskId = my_data->thread_id;
    sum = my_data->sum;
    hello_msg = my_data->message;
    printf("Thread %d: %s  Sum=%d\n", taskId, hello_msg, sum);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];
    int rc, t, flag;

    flag=0;
    messages[0] = "English: Hello World!";
    messages[1] = "French: Bonjour, le monde!";
    messages[2] = "Spanish: Hola al mundo";
    messages[3] = "Klingon: Nuq neH!";
    messages[4] = "German: Guten Tag, Welt!";
    messages[5] = "Russian: Zdravstvytye, mir!";
    messages[6] = "Japan: Sekai e konnichiwa!";
    messages[7] = "Latin: Orbis, te saluto!";

    for(t = 0; t < NUM_THREADS; t++) {
        flag = flag + t;
        // encapsulate data in array element which has data type as struct thread_data
        thread_data_array[t].thread_id = t;
        thread_data_array[t].sum = flag;
        thread_data_array[t].message = messages[t];
        printf("Creating thread %d\n", t);
        //Single thread
        //printf("Thread %d: %s  flag=%d\n", t, messages[t], flag);

        rc = pthread_create(&threads[t], NULL, PrintHello,  &thread_data_array[t]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
            }
    }
    pthread_exit(NULL);
}

/**

    Creating thread 0
    Creating thread 1
    Creating thread 2
    Creating thread 3
    Creating thread 4
    Creating thread 5
    Creating thread 6
    Creating thread 7
    Thread 0: English: Hello World!  Sum=0
    Thread 2: Spanish: Hola al mundo  Sum=3
    Thread 1: French: Bonjour, le monde!  Sum=1
    Thread 4: German: Guten Tag, Welt!  Sum=10
    Thread 5: Russian: Zdravstvytye, mir!  Sum=15
    Thread 6: Japan: Sekai e konnichiwa!  Sum=21
    Thread 7: Latin: Orbis, te saluto!  Sum=28
    Thread 3: Klingon: Nuq neH!  Sum=6

 **/