/**
 * How many such routes are there through a 20×20 grid?
 *
 * https://projecteuler.net/problem=15
 */


#include <stdio.h>

int main(){
	// the number of ways to get to a square is the sum of the number of ways to get to the top left square
	long g[21][21];
	int i, j;
    for (i = 0; i < 21; i++) {
        g[i][0] = 1;
        g[0][i] = 1;
    }
    for (i = 1; i < 21; i++) {
        for (j = 1; j < 21; j++) {
            g[i][j] = g[i-1][j] + g[i][j-1];
        }
    }

    printf("%lu\n", g[20][20]);
    return 0;
}