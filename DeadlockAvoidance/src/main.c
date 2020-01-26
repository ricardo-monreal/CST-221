/**
 * @author Ricardo Monreal
 * @email moises.monreal@gmail.com
 * @create date 2020-01-23 21:31:09
 * @modify date 2020-01-26 08:36:58
 * 
 * @desc 
 * The porpuse of this application is to demonstrate 
 * Deadlock avoidance using a timer when not enough
 * resources available to run the process. 
 * 
 * Grand Canyon University
 * CST-221
 * Deadlock Avoidance Assignment
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int resourcesAvailable = 4;
int resourcesRequired;
int processANeeds = 5;
int processBNeeds = 10;
int processAHas = 3;
int processBHas = 3;

int main() {
	// display process A resource info
	printf("Process A has %d resources and requires %d resources.\n", processAHas, processANeeds);
	printf("Process A will request additional resources.\n");

	// Process A requests resources using loop until all resources are acquired
	while (processANeeds > processAHas) {

		processAHas++;
		resourcesAvailable--;
		resourcesRequired++;

		printf("Process A has %d resources and required %d resources\n",processAHas, processANeeds);
		printf("%d total resources available\n", resourcesAvailable);
	}

	// Process A start
	printf("Process A has all required resources\n");
	
	// Process B requests resources using loop until all resources are acquired
	while (processBNeeds > processBHas) {

		// if not enough resources, try again using timer
		if (resourcesAvailable <= 0) {
			printf("required resources not met, trying later..\n");
			int seconds = 0;  

			// Timer with sleep
    			while (seconds <= 2) {
        			printf("%d Seconds\n", seconds);
        			sleep(1);  
        			seconds++;
    			}
			// Process A done. Resources will be freed
    			resourcesRequired
			 = 0;
			processAHas = 0;
			resourcesAvailable = 5;
			printf("Process A is done and has freed its resources\n");

		// Process B will acquire the necessary resources
		} else {
			processBHas++;
			resourcesAvailable--;
			resourcesRequired++;

			// acquiring resources
			printf("Process B has %d resources and requires %d resources\n", processBHas, processBNeeds);
			printf("%d resources available\n",resourcesAvailable);
		}				
	}
	
	// Process B start
	printf("Process B has all required resources\n");
}