/**
 * @author Ricardo Monreal
 * @email moises.monreal@gmail.com
 * @desc
 * Understanding the problem was the first challenge for this assignment. 
 * Once I understand that each process (Producer and consumer) share a common, fixed-size buffer,
 * I was able to understand that I needed to have the Producer place information 
 * into the buffer and have the Consumer retrieve that information. 
 * In order to avoid having the Producer but information in the buffer when it is already full, 
 * I put the Producer to sleep while it waits for the consumer to retrieve 
 * that information in order to avoid the problem of having a full buffer. 
 * 
 * Grand Canyon University
 * CST-221
 * Producer and Consumer Assignment
 * 
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define N 10 // how many numbers to produce
int produce();
void put();
void *producer();
void *consumer();
void consume();
int get();
int buffer[N]; // number of items in the buffer

int Product;

void *producer() { // produce the data
	int i;
	while(1) {      // producer loop
		i = produce();
		put(i);     // put the product generated in variable i, once data generated and in buffer go to sleep
		sleep(1);
	}
}

void *consumer() { // consume the data generated in variable i, if data consumed go to sleep
	int i;
	while(1) {      // consumer loop
		i = get();
		consume(i);
		sleep(1);
	}
}

int produce() {
	return Product + 1; //increment count of product
}

void consume(int i) {
	printf("Consumer thread slot # : %i\n",i); // display the current consumer thread
	
}

void put(int i) {
	Product = i;
	printf("Producer thread slot #: %d\n", i); // display the current producer thread
	return;
}

int get() {
	return Product;
}

void main() {
	pthread_t threads[2];
 	pthread_create(&threads[0], 0, consumer, 0); // thread identifier of newly created thread is returned as the function value
 	pthread_create(&threads[1], 0, producer, 0);
 	pthread_join(threads[0], 0);   // join thread waiting create calls, parameters given as identifier of thread to wait for. 
	pthread_join(threads[1], 0);

}