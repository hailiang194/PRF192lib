#include "char-string.h"

int numChar(char *s, char k)
{
	int count = 0;
	
	for(char *c = s; *c != '\0'; c++)
	{
		if((*c) == k)
			count++;
	}
	
	return count;
}

int isPalindrome(char *s)
{
	char * left = s;
	char * right = &s[strlen(s) - 2];
	
	while(left <= right)
	{
		if(*left != *right)
			return FALSE;
				
		left++;
		right--;
	}
	
	return TRUE;
}

int numWord(char *s)
{
	int count = (isspace(s[0])) ? 0 : 1;
	for(char *c = &s[1]; *c != '\0'; c++)
	{
		if(isspace(*(c - 1)) && !isspace(*c))
			count++;
	}
	
	return count;
}

void chrSwap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t; 
}

char * strReverse(char *s)
{
	const size_t sLen = strlen(s);
	char *rev = (char *)malloc((sLen + 1) * sizeof(char));
	
	strcpy(rev, s);
	
	char *left = rev;
	char *right = &rev[sLen - 1];

	while(left < right)
	{
		chrSwap(left, right);
		left++;
		right--;
	}
	
	return rev;
}

int * fChar(char *s)
{
	int *f = (int *)malloc(NUM_PRINTABLE_CHAR * sizeof(int));

	for(int i = 0; i < NUM_PRINTABLE_CHAR; i++)
	{
		f[i] = 0;
	}

	for(char *c = s; (*c) != '\0'; c++)
	{
		f[(*c) - START_PRINTABLE_CHAR] ++;
	}

	return f;
}

char * strWord(char *s, char *subStr)
{
	char * locate = strstr(s, subStr);
	
	size_t subLen = strlen(subStr);
	
	while(TRUE)
	{
			if(locate == NULL)
				return NULL;
			
			//check if this location is a word or not
			//check the left side	
			if(((locate == s) || (isspace(locate[-1]))) 
				//check the right side
				&&(locate[subLen] == '\0' || isspace(locate[subLen])))
				return locate;
			
			locate = strstr(locate + 1, subStr);
	}
	
}

void caesarCipher(char *plain, char *cipher, int key)
{
	strcpy(cipher, plain);

	for(char *c = cipher; (*c) != '\0'; c++)
	{
		if(islower(*c))
			*c = ((*c) - 'a' + key) % 26 + 'a';
		else if(isupper(*c))
			*c = ((*c) - 'A' + key) % 26 + 'A';
	}
}

char * getMaxLenWord(char *s)
{
	char *word = strtok(s, WORD_DELIMITERS);
	size_t maxWordLen = strlen(word);
	char * wordMaxLen = word;
	
	while(word != NULL)
	{
		size_t currentWordLen = strlen(word);
		if(currentWordLen > maxWordLen)
		{
			wordMaxLen = word;
			maxWordLen = currentWordLen;
		}
		
		
		word = strtok(NULL, WORD_DELIMITERS);
	}
	
	return wordMaxLen;
}

char *getWordAt(char *s, size_t pos)
{
	char *word = strtok(s, WORD_DELIMITERS);

	for(int i = 0; i < pos; i++)
	{
		word = strtok(NULL, WORD_DELIMITERS);
	}

	return word;
}