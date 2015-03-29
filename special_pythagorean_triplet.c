/**
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
 *
 * https://projecteuler.net/problem=9
 */


#include <stdio.h>

int main(){
	int i,j,k;
	for (i = 1; i < 1000; i++){
		for (j = 1; j < 1000; j++){
			for (k = 1; k < 1000; k++){
				if (i*i + j*j == k*k && i+j+k == 1000){
					printf("The numbers are %d, %d, and %d, and the product is %d\n", i, j, k, i*j*k);
					return 0;
				}
			}
		}
	}

	printf("Couldn't find it cuz I'm a scrub.\n");

	return 0;
}