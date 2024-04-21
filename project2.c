//this is the file for proj 2

// Miled Kalbourji 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10 
#define NUM_CONSUMERS 3 

int buffer[BUFFER_SIZE]; 
pthread_mutex_t our_mutex = PTHREAD_MUTEX_INITIALIZER; //initilzing the mutex in order to be called later on
pthread_cond_t producer_cond = PTHREAD_COND_INITIALIZER; // initialzing the producer conditions 
pthread_cond_t consumer_cond = PTHREAD_COND_INITIALIZER; //initialzing the consumer conditions 
int next_consumer = 0; // Index indicating which comsemr should consume next 
int next_producer = 0; // Index indicating where the producer should place the next integer     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void *producer(void *arg) { //Producer function
	
	while(1){//i don't know what this means I went off what our professor said in the pseudocode and didn't understand all of it
    //there's a lot to fix here
	
		pthread_mutex_lock(&our_mutex);
	
		while()//while there are unconsumed array elements
			pthread_cond_wait(&producer_cond, &our_mutex);
	
		srand(time(NULL)); 
		int R = rand( ) % 10 + 1; // can generate a random number of integer in range [1, 10] 
	
	
		for(int i = 0; i < R; ++i)
			array[i] = 435;
	
		pthread_mutex_unlock(&our_mutex);
	
		pthread_cond_broadcast(&consumer_cond); //broadcast the wake up all consumer threads
	}
}


void *consumer(void *arg) { //Consumer function

	srand(time(NULL)); 
	int R = rand( ) % 3 + 1; // can generate a random number of integer in range [1, 3]

}

main() { 
	pthread_create
	for()
		pthread_create(&con[i])
	
	pthread_join(producer)
	for()
		pthread_join(con[i])
}
