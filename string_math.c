#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void reverse(char*);
int charToInt(char);
int compare(char*, char*);
char intToChar(int);
char * trimZeroes(char*);
char * padZeroes(char*, char*);
char * intToString(int);
char * substr(char*, int, int);
char * append(char*, char);
char * prepend(char*, char);
char * addNumbers(char*, char*);
char * subtractNumbers(char*, char*);
char * multiplyNumbers(char*, char*);


char * addNumbers(char * num1, char * num2){
	char * result = "";

	int num1IsNegative = (num1[0] == '-');
	int num2IsNegative = (num2[0] == '-');

	if (num1IsNegative && num2IsNegative){
		result = addNumbers( substr(num1, 1, strlen(num1)-1), substr(num2, 1, strlen(num2)-1) );
		result = prepend(result, '-');
		return result;
	}
	else if (num1IsNegative && !num2IsNegative){
		return subtractNumbers( num2, substr(num1, 1, strlen(num1)-1) );
	}
	else if (!num1IsNegative && num2IsNegative){
		return subtractNumbers( num1, substr(num2, 1, strlen(num2)-1) );
	}

	int i, j, carry;
	for (i = strlen(num1)-1, j = strlen(num2)-1, carry = 0; i >= 0 || j >= 0 || carry != 0; i--, j--){
		int digit1;
		if (i < 0)
			digit1 = 0;
		else
			digit1 = charToInt(num1[i]);

		int digit2;
		if (j < 0)
			digit2 = 0;
		else
			digit2 = charToInt(num2[j]);

		int digit = digit1 + digit2 + carry;
		if (digit > 9){
			carry = 1;
			digit -= 10;
		}
		else {
			carry = 0;
		}

		result = prepend(result, intToChar(digit));
	}

	return result;
}

char * subtractNumbers(char * num1, char * num2){
	char * result = "";

	int num1IsNegative = (num1[0] == '-');
	int num2IsNegative = (num2[0] == '-');

	if (num2IsNegative){
		return addNumbers( num1, substr(num2, 1, strlen(num2)-1) );
	}
	else if (num1IsNegative){
		result = addNumbers( substr(num1, 1, strlen(num1)-1), num2 );
		result = prepend(result, '-');
		return result;
	}
	else if (compare(num1, num2) == -1){
		result = subtractNumbers(num2, num1);
		result = prepend(result, '-');
		return result;
	}

	/* After this point, num1 > num2 */

	int i, j, carry;
	for (i = strlen(num1)-1, j = strlen(num2)-1, carry = 0; i >= 0 || j >= 0 || carry != 0; i--, j--){
		int digit1;
		if (i < 0)
			digit1 = 0;
		else
			digit1 = charToInt(num1[i]);

		int digit2;
		if (j < 0)
			digit2 = 0;
		else
			digit2 = charToInt(num2[j]);

		int digit = digit1 - digit2 + carry;
		if (digit < 0){
			digit += 10;
			carry = -1;
		}
		else {
			carry = 0;
		}

		result = prepend(result, intToChar(digit));
	}

	return result;
}

char * multiplyNumbers(char * num1, char * num2){
	char * result = "0";

	int num1IsNegative = (num1[0] == '-');
	int num2IsNegative = (num2[0] == '-');

	if (num1IsNegative && num2IsNegative){
		return multiplyNumbers( substr(num1, 1, strlen(num1)-1), substr(num2, 1, strlen(num2)-1) );
	}
	else if (num1IsNegative && !num2IsNegative){
		result = multiplyNumbers( substr(num1, 1, strlen(num1)-1), num2 );
		result = prepend(result, '-');
		return result;
	}
	else if (!num1IsNegative && num2IsNegative){
		result = multiplyNumbers( num1, substr(num2, 1, strlen(num2)-1) );
		result = prepend(result, '-');
		return result;
	}

	int i, j, len1 = strlen(num1), len2 = strlen(num2);
	for (i = 0; i < len1; i++){
		int digit1 = charToInt(num1[i]);

		if (digit1 == 0)
			continue;

		int num1Place = len1-1-i;
		if (num1Place < 0)
			num1Place++;

		for (j = 0; j < len2; j++){
			int digit2 = charToInt(num2[j]);

			if (digit2 == 0)
				continue;

			int num2Place = len2-1-j;
			if (num2Place < 0)
				num2Place++;

			char * subProduct = intToString(digit1*digit2);
			int subProductPlace = num1Place + num2Place;

			int k;
			for (k = 0; k < subProductPlace; k++){
				subProduct = append(subProduct, '0');
			}

			result = addNumbers(result, subProduct);
		}
	}

	return result;
}


int charToInt(char c){
	return c - '0';
}

char intToChar(int i){
	return (char)(((int)'0') + i);
}

void reverse(char *string) {
	int length, c;
	char *begin, *end, temp;

	length = strlen(string);
	begin  = string;
	end    = string;

	for (c = 0; c < length - 1; c++)
		end++;

	for (c = 0; c < length/2; c++) {        
		temp   = *end;
		*end   = *begin;
		*begin = temp;

		begin++;
		end--;
	}
}

char * append(char * s, char c) {
    int len = strlen(s), j = 0;
    char *tmp;
    tmp = malloc((len+2) * sizeof(char)); // +2 for the appending character and the null terminator
    while (j < len){
        tmp[j] = s[j];
        j++;
    }
    tmp[j++] = c;
    tmp[j] = '\0';
    return tmp;
}

char * prepend(char * s, char c){
    int len = strlen(s), j = 0;
    char *tmp;
    tmp = malloc((len+2) * sizeof(char)); // +2 for the appending character and the null terminator
    tmp[0] = c;
    while (j < len){
        tmp[j+1] = s[j];
        j++;
    }
    tmp[j+1] = '\0';
    return tmp;
}


char* substr(char * str, int start, int length){
	char * sub = "";
	sub = malloc(sizeof(char)*(length+1));
	memcpy(sub, &str[start], length);
	sub[length] = '\0';
	return sub;
}


char * trimZeroes(char * str) {
	if (strcmp(str, "") == 0)
		return "0";

	char * tmp = malloc(strlen(str)*sizeof(char));
	strcpy(tmp, str);
	while (tmp[0] == '0'){
	    int len = strlen(tmp);
	    memmove(tmp, tmp+1, len);
	}
	return tmp;
}

/**
 * Compares two string numbers.
 *
 * @return number 1 if num1 > num2, 0 if num1 == num2, -1 if num1 < num2.
 */
int compare(char * num1, char * num2){
	num1 = trimZeroes(num1);
	num2 = trimZeroes(num2);

	if (strcmp(num1, num2) == 0){
		return 1; // numbers are equal
	}

	int num1IsNegative = (num1[0] == '-');
	int num2IsNegative = (num2[0] == '-');

	int sign = 1;
	if (!num1IsNegative && num2IsNegative){
		return 1;
	}
	else if (num1IsNegative && !num2IsNegative){
		return -1;
	}
	else if (num1IsNegative && num2IsNegative){
		num1 = substr(num1, 1, strlen(num1)-1);
		num2 = substr(num2, 1, strlen(num2)-1);
		sign = -1;
	}

	num1 = padZeroes(num1, num2);
	num2 = padZeroes(num2, num1);

	int len = strlen(num1);
	int i;
	for (i = 0; i < len; i++){
		int digit1 = charToInt(num1[i]);
		int digit2 = charToInt(num2[i]);

		if (digit1 > digit2){
			return sign;
		}
		else if (digit1 < digit2){
			return sign * -1;
		}
	}

	return 0;
}

/**
 * Add zeroes in front of num1 (which should be positive) until it is equal to the length of num2
 */
char * padZeroes(char * num1, char * num2){
	while (strlen(num1) < strlen(num2)){
		num1 = prepend(num1, '0');
	}
	return num1;
}


char * intToString(int num){
	char * str = "";
 	int i, rem, len = 0, n;
 
    n = num;
    while (n != 0){
        len++;
        n /= 10;
    }
    str = malloc(sizeof(char)*(len+1)); // +1 for the terminating char
    for (i = 0; i < len; i++){
        rem = num % 10;
        num /= 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    return str;
}
