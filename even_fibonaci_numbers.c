/**
 * Find the sum of all even-valued fibonaci terms less than or equal to 4 million.
 *
 * https://projecteuler.net/problem=2
 */


#include <stdio.h>

#define CEILING 4000000

int main(){
	int a = 1; // first fib #
	int b = 2; // second fib #
	int sum = 0;

	while (b < CEILING){
		if (b % 2 == 0)
			sum += b;
		int c = a+b;
		a = b;
		b = c;
	}

	printf("The sum of all even-valued fib. terms less than %d is %d", CEILING, sum); 

	return 0;
}