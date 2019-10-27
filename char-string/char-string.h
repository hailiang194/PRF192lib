#ifndef CHAR_STRING_H
	#define CHAR_STRING_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "..\constant.h"

//count times k appear in s
int numChar(char *s, char k);

//swap the value of 2 characters
void chrSwap(char *a, char *b);

//check if s is palindrome string or not
int isPalindrome(char *s);

//count words in s
int numWord(char *s);

//return the reverse of s
char * strReverse(char *s);

//get frequencies of all printable character in s
int * fChar(char *s);

//return the first word that is subStr
char * strWord(char *s, char *subStr);

#endif