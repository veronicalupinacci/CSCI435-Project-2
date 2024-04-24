// this is the file for proj 2

// Miled Kalbourji, VeronicaLupinacci, Rebekah Watrous

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define NUM_CONSUMERS 3

int buffer[BUFFER_SIZE];
int count;

pthread_mutex_t our_mutex =
    PTHREAD_MUTEX_INITIALIZER;  // initilzing the mutex in order to be called
                                // later on
pthread_cond_t producer_cond =
    PTHREAD_COND_INITIALIZER;  // initialzing the producer conditions
pthread_cond_t consumer_cond =
    PTHREAD_COND_INITIALIZER;  // initialzing the consumer conditions
int next_consumer = 0;  // Index indicating which consumer should consume next
int next_producer =
    0;  // Index indicating where the producer should place the next integer

void *producer(void *arg) {  // Producer function

  while (1) {  // producer thread, like other consumer threads, is always running

    pthread_mutex_lock(&our_mutex);

    int i = 0;
    
    while (buffer[i] != -1 && i < buffer_size)  // while there are unconsumed array elements
      i++;
    pthread_cond_wait(&producer_cond, &our_mutex);

    srand(time(NULL));
    int R = rand() % 10 +
            1;  // generate a random number of integer in range [1, 10]

    // Produce the integers and put them into the buffer
    for (i = 0; i < R; i++) {
      buffer[i] = 435;
    }
  }

  pthread_mutex_unlock(&our_mutex);

  pthread_cond_broadcast(&consumer_cond);  //broadcast to wake up all consumer threads
}

void *consumer(void *arg) {  // Consumer function

  srand(time(NULL));
  int R = rand() % 3 +
          1;  // can generate a random number of integer in range [1, 3]
}


main() {
    pthread_create
    for(i 0..2)
        pthread_create(&con[i])
    ptread_join(producer)
    for(i 0..2)
        pthread_join(con[i])
}
