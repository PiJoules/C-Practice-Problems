/**
 * Helper function for subtracting 2 numbers as strings
 */


#include <stdio.h>
#include "string_math.h"

// remove these l8er
#include <string.h>
#include <stdlib.h>



int main(){
	char * num1 = "1234";
	char * num2 = "1235";
	printf("sum: %s\n", addNumbers(num1, num2));
	printf("diff: %s\n", subtractNumbers(num1, num2));

	return 0;
}