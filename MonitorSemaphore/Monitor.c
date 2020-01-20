/**
 * @author Ricardo Monreal
 * @email moises.monreal@gmail.com
 * @create date 2020-01-19 12:39:10
 * @modify date 2020-01-19 21:12:25
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

#define N 100   // define max buffer size

typedef struct Monitor // setup Monitor
{
  int mutex; // mutex variable
  int full; // buffer variables
  int empty;

} Monitor;

int buffer = 0; // starting buffer
int produce() {
  
  return 20; // Size of increments to add to buffer
}

int get() {
  return 20; //int return to consoume from buffer
}

void consume(int i) {
  
  buffer -= i; // remove defined int size from buffer
}

void put(int i) {
    buffer += i; // add defined int size to buffer
}

void producer(Monitor *monitor) {
  int i;

  while (monitor->full == 0) { // loop until buffer its full

    while (monitor->mutex != 1) {  // mutex unlock = 1, lock = 0
    }

    monitor->empty = 0; // set monitor to empty
    monitor->mutex = 0; // mutex unlock = 1, lock = 0

    i = produce(); // generate and add int to buffer
    put(i);
    printf("Adding value to Buffer: %i \n", buffer); // display values of current buffer

    if (buffer >= N) {
      monitor->full = 1; // monitor will be set to full once buffer is full
    }
    monitor->mutex = 1; // mutex unlock = 1, lock = 0
  }

  printf("Buffer is currently full.\n");
  consumer(monitor); // consume the full buffer 
}

void consumer(Monitor *monitor) {
  int i;

  while (monitor->empty == 0) {  // process will loops until buffer is empty

    while (monitor->mutex != 1) { // mutex unlock = 1, lock = 0
    }
    monitor->full = 0; // set monitor to empty
    monitor->mutex = 0;  // mutex unlock = 1, lock = 0
    i = get(); 

    consume(i); // consume from buffer

    printf("Consuming value from buffer: %i, Current Buffer Size: %i \n", i, buffer); // display values
    if (buffer <= 0) {
      monitor->empty = 1; // monitor will be empty once buffer is empty
    }
    monitor->mutex = 1; // mutex unlock = 1, lock = 0
  }

    printf("Buffer is now empty.\n");
    producer(monitor); // start producer process
}

void main() { 
  Monitor monitor = { // setup monitor
    //set unlocked
    .mutex = 1, // set mutex to unlocked (mutex unlock = 1, lock = 0)
    .full = 0, // set to not full
    .empty = 1 // set to empty
  };
  producer(&monitor); //start producer and monitor
    //return(0);

}