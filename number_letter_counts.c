/**
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *
 * https://projecteuler.net/problem=17
 */


#include <stdio.h>

int letterCount(int digit){
	switch (digit){
		case 1:
			return 3;
		case 2:
			return 3;
		case 3:
			return 5;
		case 4:
			return 4;
		case 5:
			return 4;
		case 6:
			return 3;
		case 7:
			return 5;
		case 8:
			return 5;
		case 9:
			return 4;
		case 10:
			return 3;
		case 11:
			return 6;
		case 12:
			return 6;
		case 13:
			return 8;
		case 14:
			return 8;
		case 15:
			return 7;
		case 16:
			return 7;
		case 17:
			return 9;
		case 18:
			return 8;
		case 19:
			return 8;
		case 20:
			return 6;
		case 30:
			return 6;
		case 40:
			return 5;
		case 50:
			return 5;
		case 60:
			return 5;
		case 70:
			return 7;
		case 80:
			return 6;
		case 90:
			return 6;
		default:
			return 0;
	}
}

int main(){
	/*
	1 one
	2 two
	3 three
	4 four
	5 five
	6 six
	7 seven
	8 eight
	9 nine
	10 ten
	11 eleven
	12 twelve
	13 thirteen
	14 fourteen
	15 fifteen
	16 sixteen
	17 seventeen
	18 eighteen
	19 nineteen
	20 twenty
	2x twenty-x
	3x thirty-x
	4x forty-x
	5x fifty-x
	6x sixty-x
	7x seventy-x
	8x eighty-x
	9x ninety-x
	x00 x hundred
	xyy x hundred and yy
	1000 one thousand
	 */
	
	int i;
	unsigned int count = 0;
	for (i = 1; i <= 1000; i++){
		int num = i;
		int thisCount = 0;
		if (num == 1000){
			thisCount += 11;
		}
		else {
			int wasGreaterThan100 = 0; // a flag
			if (num >= 100){
				int hundredsDigit = num/100;
				thisCount += letterCount(hundredsDigit) + 7; // x hundred
				num -= hundredsDigit*100;
				wasGreaterThan100 = 1;
			}
			if (num > 0){
				if (wasGreaterThan100)
					thisCount += 3; // and
				if (num >= 20){
					int tensDigit = num/10;
					tensDigit *= 10;
					thisCount += letterCount(tensDigit); // xty
					num -= tensDigit;
					thisCount += letterCount(num); // y
				}
				else {
					thisCount += letterCount(num);
				}
			}
		}
		count += thisCount;
	}
	printf("%d\n", count);

	return 0;
}