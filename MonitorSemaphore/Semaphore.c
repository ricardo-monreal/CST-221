/**
 * @author Ricardo Monreal
 * @email moises.monreal@gmail.com
 * @create date 2020-01-19 15:12:49
 * @modify date 2020-01-19 21:15:02
 * 
 * 
 * @desc 
 * 
 * For this assignment I wanted to fill the buffer, use monitor to check when the buffer is full and then use consumer to empty the buffer. 
 * Process will loops once Monitor checks that the buffer is empty and the Producer will start filling the buffer again. 
 * 
 * Grand Canyon Univeristy
 * CST-221
 * Monitor and Semaphores Assignment
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 100 // define max buffer size

int semaphore = 1; // semepahore unlock = 1, locked = 0
int buffer = 0; //buffer variable
int produce() {
  return 20; // int return and add to bufer
}

int get() {
  return 20; // int return to consume from buffer
}

void consume(int i) {
  buffer -= i; // remove define int size from buffer
}

void put(int i) {

    buffer += i; // add int to buffer

}

void producer() {
  int i;

  while (buffer < N) { // loop until buffer its full

    while (semaphore != 1) { // semaphore unlocked = 1, locked = 0
    }

    semaphore = 0; // semaphore unlocked = 1, locked = 0

    i = produce(); // generate and add int to buffer

    put(i);
    printf("Adding value to Buffer: %i \n", buffer); // display values of current buffer 

    semaphore = 1; // semaphore unlocked = 1, locked = 0
  }

  printf("Buffer is currently full\n");

  consumer(); // consume from buffer
}


void consumer() {
  int i;
  while (buffer > 0) { // process will loop until buffer is empty

    while (semaphore != 1) { // semaphore unlocked = 1, locked = 0
    }
    semaphore = 0; // semaphore unlocked = 1, locked = 0

    i = get();

    consume(i); // consume from buffer

    printf("Consuming value from buffer: %i, Current Buffer Size: %i \n", i, buffer); // display buffer values

    semaphore = 1; // semaphore unlocked = 1, locked = 0
  }

  printf("Buffer is now empty\n");

  producer(); // start producer
}

void main() {

  producer();


}