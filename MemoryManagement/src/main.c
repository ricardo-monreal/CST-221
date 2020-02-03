/**
 * @author Ricardo Monreal
 * @email moises.monreal@gmail.com
 * @create date 2020-01-29 12:49:44
 * @modify date 2020-02-02 22:52:13
 * @desc 
 * 
 * The purpose of this application is to convert a number
 * input by the user to binary and hexadecimal
 * 
 * 
 *Grand Canyon University 
 *CST-221
 *Memory Management Assignment 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	int i, b, n, number, binary[20];
	BEGINNING: printf("Enter a number between 0 and 4095:   "); 
	scanf("%d", &number); // scanner for user input
	int s = number; // define scanner variable
 	char h[17] = "0123456789abcdef"; 
	int decimal, quotient, remainder;
	char hex[1024];
	i = 0;
	
	if (s < 0 || s > 4095) { // entered number must be in this range
		printf("The input number in not in range\n");
		goto BEGINNING; // go to the beginning of the program if not in range
	}

	/* hexadecimal conversion */
	
	decimal = s;
	hex[0] = '\0';

	while (decimal != 0) { // formala to convert input number to hexadecimal
		quotient = decimal / 16;
		remainder = decimal % 16;

		memmove( &hex[1], hex, strlen(hex) + 1);

		hex[0] = h[remainder];

		decimal = quotient;
	}
	printf("The equivalent of %d in hexadecimal is: 0x%s", s, hex);

	/* binary conversion */
	
	while (number > 0) { 	// formula to convert  number to binary

		n = number % 2;
		binary [i] = n;
		number = number / 2;
		i++;
	}

	printf("\nThe equivalen of %d in binary is: 0b", s); // binary conversion
		for (b = i - 1; b >= 0; b--) {
		printf("%d", binary[b]);
	}

	/* decimal conversion
	this is not needed for we just need to print the input number */
	printf("\nThe equivlanet of %d in decimal is: %d\n\n", s, s);
	
	return 0;
}

