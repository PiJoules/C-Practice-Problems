#include <string.h>
#include <stdlib.h>

int charToInt(char);
char intToChar(int);
void reverse(char*);
char * append(char*, char);
char * addNumbers(char*, char*);


char * addNumbers(char * num1, char * num2){
	char * result = "";
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

		result = append(result, intToChar(digit));
	}

	reverse(result);

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
