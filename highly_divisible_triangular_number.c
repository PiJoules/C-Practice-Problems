/**
 * What is the value of the first triangle number to have over five hundred divisors?
 *
 * https://projecteuler.net/problem=12
 */


#include <stdio.h>
#include <math.h>


int main(){
	int i = 1, j, counter = 0, max = 0, ans = 0;
	while (counter <= 500){
		ans += i++;
		counter = 0;
		/**
		 * only need to check up to sqrt, and there will be 1 other number to comlement the divisor
		 */
		int end = sqrt(ans);
		for (j = 1; j < end; j++){
			if (ans % j == 0){
				counter += 2;
			}
		}
		if (end*end == ans)
			counter++; // perfect square
	}
	printf("%d with %d divisors\n", ans, counter);

	return 0;
}