/**
 * For testing string_math.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substr(char ** str, int start, int len){
	
}

int main(){
	/*char* num1 = "1234";
	char* num2 = "1234";

	printf("sum: %s\n", addNumbers(num1, num2));
	printf("diff: %s\n", subtractNumbers(num1, num2));
	printf("prod: %s\n", multiplyNumbers(num1, num2));*/

	/*char* test;
	test = malloc(sizeof(char)*4);
	char bob[] = "test";
	memcpy(test,&bob,sizeof(bob));

	//char * sub;
	//sub = substr(test, 1, 2);
	printf("%s\n", test);*/

	free(test);
	//test was some memory address
	//bob was some other address
	//i copied the data of bob into test
	//then freed test
	//I think THINK THINK THINK char* test = "bob". does not malloc memory according to C.
	//Which makes no sense
	//but it's saying I can't free memory I didn't explicitly malloc.
	//So I malloced stuff.
	//When you did test = "test" after your malloc it set the memory to a different pointer. You should be able to test
	//By printing the pointer values as the code goes.
	//Bob was only "allocted" via the char* bob = "test" command. It was not explicity malloced. Now I thought it was equivalent but according to free
	//It thinks the two are different.
	// so test has the value "test"?
	// is a char[] the same as a char*?
	// 
	//char* is unalocated memory. Even with "b;sakd;asd". Same as []. They both are pointers.
	//However if you explicitly set the size [4] then it is malloced. Don't use naked * without a malloc call it's "unsafe" according to 
	//stackoverflow.
	//so If i want to change the size of char[whatever], do I need to use malloc?
	//Yes. but. Common convention is to use a buffer with more size then needed.
	//buf[256]
	//extra space never hurt anyone
	//but this uses memeory that won't really be used in code?
	//this script already uses 2+ gigs,
	//
	/*char* sub;
	sub = substr(test, 1, 2);
	free(test);
	printf("%s\n", sub);*/

	return 0;
}

//where is substr defijed

/*char * test = "test";
char * sub;
sub = substr(test, 1, 2);
free(test); //this is still good?
//This never frees sub
// but I 
printf("%s\n", sub);
free(sub; //now?
//What is test for then?
//test was my original string, but I don't want it anymore. I want the substring after I'm done using test
// I also assume this ^ seems more "readable" than the other solution where free() ciomes before substr()?
// I am not good at reading. I didn't realize test is called by substr. This is the only method that works
// If you called free test before you would get a null pointer dereference
// danka*/