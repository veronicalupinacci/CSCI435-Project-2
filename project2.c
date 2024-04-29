// this is the file for proj 2

// Miled Kalbourji, Veronica Lupinacci, Rebekah Watrous

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 10
#define NUM_CONSUMERS 3

int buffer[BUFFER_SIZE]; // Array to hold integers
int count; // Number of elements in the buffer

pthread_mutex_t our_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for synchronization
pthread_cond_t producer_cond = PTHREAD_COND_INITIALIZER; // Condition variable for producer
pthread_cond_t consumer_cond = PTHREAD_COND_INITIALIZER; // Condition variable for consumers

int next_consumer = 0; // Index indicating which consumer should consume next
int next_producer = 0; // Index indicating where the producer should place the next integer
int unconsumed= 0; // uncosumed elements in array
int TURN = 1; 


void *producer(void *arg) {
    while (1) {
        pthread_mutex_lock(&our_mutex); // Lock the mutex

        int i = 0;

       while(unconsumed != 0) {
           pthread_cond_wait(&producer_cond, &our_mutex); // Wait for signal from consumers
        }

        srand(time(NULL)); // Initialize the random number generator with the current time as the seed
        int R = rand() % 10 + 1; // Generate a random number of elements (between 1 and 10) to be produced
        unconsumed = R; // Set the number of unconsumed elements to the number of elements generated


        printf("Producer generated %d integers. \n ", R);
        for (int j = 0; j < R && i < BUFFER_SIZE; j++, i++) { // Fill the buffer with generated integers
            buffer[i] = 435;
        }

        pthread_cond_broadcast(&consumer_cond); // Signal consumers to consume
        pthread_mutex_unlock(&our_mutex); // Unlock the mutex
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
   int consumerID = *((int *)arg); // Get the consumer's ID
   int lastConsumedIndex = -1; // Initialize the index of the last consumed element
  
    while (1) { // Infinite loop for continuous consumption
        pthread_mutex_lock(&our_mutex); // Lock the mutex for accessing shared resources

        while (unconsumed == 0 || TURN != consumerID) {
            pthread_cond_wait(&consumer_cond, &our_mutex); // Wait for the buffer to be non-empty and for it to be this consumer's turn
        }

        int R = rand() % 3 + 1; // Generate a random number of elements to consume, between 1 and 3 (inclusive)

        R = R > unconsumed ? unconsumed : R; // Limit the number of elements to consume (R) to the number of unconsumed elements,
// ensuring that the consumer does not attempt to consume more elements than available
      
      // Print that they are consuming
        printf("Consumer %d is consuming %d elements\n", consumerID, R);

// Subtract the number of consumed elements (R) from the total unconsumed count
        unconsumed = unconsumed - R;
      
// Update the TURN variable to determine the next consumer to consume elements
// If TURN reaches 3, reset it back to 1 to loop through the consumers
        if (TURN == 3)
            TURN = 1;
        else
            TURN++;   // where it resets 

        if (unconsumed > 0)
            pthread_cond_broadcast(&consumer_cond); // Signal other consumers to check for their turn
        else
            pthread_cond_signal(&producer_cond); // Signal producer if buffer is empty

        pthread_mutex_unlock(&our_mutex); // Unlock the mutex
    }
}

int main() {
  pthread_t producer_tid, consumer_tid[NUM_CONSUMERS]; // Thread IDs for producer and consumers
  int consumerID[NUM_CONSUMERS] = {1, 2, 3}; // IDs for the three consumer threads

  // Initialize buffer to -1 (indicating no integers generated yet)
  for (int i = 0; i < BUFFER_SIZE; ++i) {
    buffer[i] = -1;
  }

  // Create producer thread
  pthread_create(&producer_tid, NULL, producer, NULL);

  // Create consumer threads
  for (int i = 0; i < NUM_CONSUMERS; ++i) {
    pthread_create(&consumer_tid[i], NULL, consumer, (void *)&consumerID[i]);
  }

  // Join threads
  pthread_join(producer_tid, NULL); // Wait for producer to finish (which is never)
  for (int i = 0; i < NUM_CONSUMERS; ++i) {
    pthread_join(consumer_tid[i], NULL); // Wait for each consumer to finish
  }

  // Cleanup
  pthread_mutex_destroy(&our_mutex); // Destroy mutex
  pthread_cond_destroy(&producer_cond); // Destroy producer condition variable
  pthread_cond_destroy(&consumer_cond); // Destroy consumer condition variable

  return 0; // Exit the program
}
