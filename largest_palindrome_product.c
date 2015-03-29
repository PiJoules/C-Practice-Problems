/**
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * https://projecteuler.net/problem=4
 */

#include <stdio.h>

int main(){
	int i, j, product = 0;
	for (i = 999; i-- > 100; ){
		for (j = 999; j-- > 100; ){
			if (isPalindrome(i*j)){
				product = max(product, i*j);
			}
		}
	}

	printf("The largest palindrome made from the product of two 3-digit numbers is %d", product);

	return 0;
}


/**
 * Check if a palindrome by reversing the number
 */
int isPalindrome(int n){
	if (n < 10)
		return 1;

	int nCopy = n;
	int reverse = 0;
	while (n > 0){
		int lastDigit = n % 10;
		reverse = reverse*10 + lastDigit;
		n /= 10;
	}

	return nCopy == reverse;
}

int max(a,b){
	return a > b ? a : b;
}