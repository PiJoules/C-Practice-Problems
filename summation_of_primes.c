/**
 * Find the sum of all the primes below two million.
 *
 * https://projecteuler.net/problem=10
 */


#include <stdio.h>
#include <math.h>

#define N 2000000

int isPrime(int);

int main(){
	unsigned long sum = 0;

	int i;
	for (i = 2; i < N; i++) {
		if (isPrime(i) == 1) {
			sum += i;
		}
	}
	printf("%lu\n", sum);

	return 0;
}

int isPrime(int num){
	int i;
	// num is divisible by i if sqrt(num) is divisible by i
	for (i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}

	return 1;
}
