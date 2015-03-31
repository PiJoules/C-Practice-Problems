/**
 * Which starting number, under one million, produces the longest chain?
 *
 * https://projecteuler.net/problem=14
 */


#include <stdio.h>


int main(){
	unsigned int count, largestCount = 1, i, n, largestNum;
	for (i = 1; i < 1000000; i++){
		n = i;
		count = 1;
		while(n != 1){
			if (n % 2 == 0){
				n /= 2;
			}
			else{
				n = 3*n + 1;
			}
			count++;
		}
		if (count > largestCount){
			largestCount = count;
			largestNum = i;
		}
	}

	printf("%d with a chain of %d\n", largestNum, largestCount);

	return 0;
}