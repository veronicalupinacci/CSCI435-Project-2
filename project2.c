//this is the file for proj 2

// Miled Kalbourji 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10 
#define NUM_CONSUMERS 3 

int buffer[BUFFER_SIZE]; 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALZIER; //initilzing the mutex in order to be called later on
pthread_cond_t producer_cond = PTHREAD_COND_INITIALIZER; // initialzing the producer conditions 
pthread_cond_t consumer_cond = PTHREAD_COND_INITIALIZER; //initialzing the consumer conditions 
int next_consumer = 0; // Index indicating which comsemr should consume next 
int next_producer = 0; // Index indicating where the producer should place the next integer     
//######################################################################################################################################
