/**
 * Helper function for subtracting 2 numbers as strings
 */


#include <stdio.h>
#include <string.h>
#include "string_math.h"

int main(){
	int i;
	char * largeNum = "1";
	// takes approx 31s
	for (i = 1; i <= 1000; i++){
		largeNum = multiplyNumbers(largeNum, intToString(2));
	}

	int sum = 0;
	for (i = 0; i < strlen(largeNum); i++){
		sum += charToInt(largeNum[i]);
	}
	printf("number: %s\nsum of digits: %d\n", largeNum, sum);

	return 0;
}