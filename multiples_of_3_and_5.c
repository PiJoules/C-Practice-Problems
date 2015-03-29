/**
 * Find the sum of all the multiples of 3 of 5 below 1000.
 */

#include<stdio.h>

#define CEILING 1000

int main(){
	int i;
	int sum = 0;
	for (i = 0; i < CEILING; i++){
		if (isDivisibleBy3(i)){
			sum += i;
		}
		else if (isDivisibleBy5(i)){
			sum += i;
		}
	}

	printf("The sum of all multiples below %d is %d", CEILING, sum);

	return 0;
}

/**
 * Keep either subtracting or adding 3 until reach zero.
 * If pass zero, is not divisible by 3.
 */
int isDivisibleBy3(int num){
	if (num > 0){
		while (num > 0){
			num -= 3;
		}
	}
	else if (num < 0){
		while (num < 0){
			num += 3;
		}
	}
	return num == 0;
}


/**
 * Same as previous function, but adding/subtracting 5
 */
int isDivisibleBy5(int num){
	if (num > 0){
		while (num > 0){
			num -= 5;
		}
	}
	else if (num < 0){
		while (num < 0){
			num += 5;
		}
	}
	return num == 0;
}