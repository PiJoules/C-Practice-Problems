/**
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 * https://projecteuler.net/problem=5
 */

#include <stdio.h>

int main(){
	int num = 1;
	int found = 0;
	while (!found){
		int i;
		for (i = 1; i <= 20; i++){
			if (num % i != 0){
				break;
			}
			found = (i == 20);
		}
		if (!found)
			num++;
	}

	printf("The smallest positive number that is evenly divisible by all the numbers from 1 to 20 is %d", num);

	return 0;
}

int isDivisible(int num, int diveder){

}