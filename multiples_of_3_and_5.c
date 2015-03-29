/**
 * Find the sum of all the multiples of 3 of 5 below 1000.
 *
 * https://projecteuler.net/problem=1
 */

#include<stdio.h>

#define CEILING 1000

int main(){
	int i;
	int sum = 0;
	for (i = 0; i < CEILING; i++){
		if (i % 3 == 0){
			sum += i;
		}
		else if (i % 5 == 0){
			sum += i;
		}
	}

	printf("The sum of all multiples below %d is %d", CEILING, sum);

	return 0;
}