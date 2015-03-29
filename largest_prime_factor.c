/**
 * What is the largest prime factor of the number 600851475143 ?
 *
 * https://projecteuler.net/problem=3
 */

#include <stdio.h>

unsigned long max(unsigned long, unsigned long);

int main(){
	unsigned long largest = 0;
	unsigned long oldNum = 600851475143;
	unsigned long num = oldNum;

	// keep dividing n by numbers until n reaches 0
	unsigned long divider = 2; // first prime #
	while (num > 1){
		while (num % divider == 0){
			largest = max(largest, divider);
			num /= divider;
		}
		divider++;
	}

	printf("The largest prime factor of %lu is %lu", oldNum, largest);

	return 0;
}

unsigned long max(unsigned long a, unsigned long b){
	return a > b ? a : b;
}