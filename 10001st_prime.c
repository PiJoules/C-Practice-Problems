/**
 * What is the 10 001st prime number?
 *
 * https://projecteuler.net/problem=7
 */

#include <stdio.h>

#define NTH_PRIME 10001

int isPrime(int);

int main(){
	int count = 0;
	int nth_prime_number = -1;

	while (count < NTH_PRIME){
		if (isPrime(++nth_prime_number)){
			count++;
		}
	}

	printf("%d\n", nth_prime_number);

	return 0;
}

int isPrime(int num){
	if (num < 2)
		return 0;

	int i;
	for (i = 2; i < num; i++){
		if (num % i == 0)
			return 0;
	}
	return 1;
}