# C pracitice problems
Because I'm a scrub. These problems are from [Project Euler](https://projecteuler.net/)

- 3/28/15 (0)
	1) multiples_of_3_and_5)c
	2) even_fibonaci_numbers.c (yes I know it's spelled incorrectly)
	3) largest_prime_factor.c
	4) largest_palindrome_product.c (could've been done more efficiently)
	5) smallest_multiple.c
- 3/29/15 (0)
	6) sum_square_difference.c
	7) 10001st_prime.c
	8) largest_product_in_a_series.c (I have no idea what I was doing)
	9) special_pythagorean_triplet.c
	10) summation_of_primes.c (I wish I had known about the sqrt thing earlier)
- 3/30/15 (0)
	11) largest_product_in_a_grid.c
	12) highly_divisible_triangular_number.c
	13) large_sum.c
	14) longest_collatz_sequence.c
	15) lattice_paths.c
- 3/31/15 (-3)
	16) power_digit_sum.c
	17) number_letter_counts.c
- 4/1/15
	18) maximum_path_sum_1.c

## Ryan plz
```c
char* substr(char * str, int start, int length){
	char * sub = "";
	sub = malloc(sizeof(char)*(length+1));
	memcpy(sub, &str[start], length);
	sub[length] = '\0';
	return sub;
}

void substr(char ** str, int start, int len){
	str = realloc(str, sizeof(char)*(len+1)); // +1 for the null terminator
	memcpy(str, &str[start], len);
	*str[len] = '\0';
}

char * test = "test";
substr(&test, 1, 2);
printf("%s\n", test);
```