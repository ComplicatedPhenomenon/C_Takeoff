/******************************************************************************
* FILE: hello_arg1.c
* USAGE: gcc -pthread hello_arg1.c 
* DESCRIPTION:
*   A "hello world" Pthreads program which demonstrates one safe way
*   to pass arguments to threads during thread creation.
* ORIGINAL AUTHOR: Blaise Barney
* LAST REVISED: 11/05/19
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS	8

char *messages[NUM_THREADS];

void *PrintHello(void *threadid){
    long taskId;
    sleep(1);
    taskId = (long) threadid;
    printf("Thread %ld: %s\n", taskId, messages[taskId]);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    pthread_t threads[NUM_THREADS]; // To store thread id of newly created thread.
    //long taskIds[NUM_THREADS];  //  func args
    int rc;
    long t;

    messages[0] = "English: Hello World!";
    messages[1] = "French: Bonjour, le monde!";
    messages[2] = "Spanish: Hola al mundo";
    messages[3] = "Klingon: Nuq neH!";
    messages[4] = "German: Guten Tag, Welt!";
    messages[5] = "Russian: Zdravstvuyte, mir!";
    messages[6] = "Japan: Sekai e konnichiwa!";
    messages[7] = "Latin: Orbis, te saluto!";

    for(t = 0; t < NUM_THREADS; t++) {
        //taskIds[t] = t;
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *) t);
        //若成功则返回0，若出错则为非零。 anything that is not 0 is true
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}
