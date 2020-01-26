/**
 * @author Ricardo Monreal
 * @email moises.monreal@gmail.com
 * @create date 2020-01-23 21:31:09
 * @modify date 2020-01-26 14:03:52
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
	FILE * fp;
	fp = fopen ("Deadlock_Avoidance_log.txt", "w+");
	// display process A resource info
	fprintf(fp, "Process A has %d resources and requires %d resources.\n", processAHas, processANeeds);
	fprintf(fp, "Process A will request additional resources.\n");

	// Process A requests resources using loop until all resources are acquired
	while (processANeeds > processAHas) {

		processAHas++;
		resourcesAvailable--;
		resourcesRequired++;

		fprintf(fp, "Process A has %d resources and required %d resources\n",processAHas, processANeeds);
		fprintf(fp, "%d total resources available\n", resourcesAvailable);
	}

	// Process A start
	fprintf(fp, "Process A has all required resources\n");
	
	// Process B requests resources using loop until all resources are acquired
	while (processBNeeds > processBHas) {

		// if not enough resources, try again using timer
		if (resourcesAvailable <= 0) {
			fprintf(fp, "required resources not met, trying later..\n");
			int seconds = 0;  

			// Timer with sleep
    			while (seconds <= 2) {
        			fprintf(fp, "%d Seconds\n", seconds);
        			sleep(1);  
        			seconds++;
    			}
			// Process A done. Resources will be freed
    			resourcesRequired
			 = 0;
			processAHas = 0;
			resourcesAvailable = 5;
			fprintf(fp, "Process A is done and has freed its resources\n");

		// Process B will acquire the necessary resources
		} else {
			processBHas++;
			resourcesAvailable--;
			resourcesRequired++;

			// acquiring resources
			fprintf(fp, "Process B has %d resources and requires %d resources\n", processBHas, processBNeeds);
			fprintf(fp, "%d resources available\n",resourcesAvailable);
		}				
	}
	
	// Process B start
	fprintf(fp, "Process B has all required resources\n");
}