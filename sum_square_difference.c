/**
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 *
 * https://projecteuler.net/problem=6
 */

#include <stdio.h>

 int main(){
 	unsigned int sumOfSquare = 0;
 	unsigned int squareOfSums = 0;

 	int i;
 	for (i = 1; i <= 100; i++){
 		sumOfSquare += i*i;
 		squareOfSums += i;
 	}
 	squareOfSums *= squareOfSums;

 	printf("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is %d\n", (squareOfSums - sumOfSquare));

 	return 0;
 }