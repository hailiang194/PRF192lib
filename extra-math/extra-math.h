/*
 * This is the extension for math standard library in C
 */
#ifndef EXTRA_MATH_H
	#define EXTRA_MATH_H

#include <math.h>
#include "..\constant.h"

//return x ^ y with x and y are integer
int powInt(int x, int y);

//return n!
int fact(int n);

//return the value of n choose k
int nCk(int n, int k);

//return GCD of a and b
//return -1 if can't calculate GCD
int GCD(int a, int b);

//return LCM of a and b
//return -1 if GCD can't be calculated
int LCM(int a, int b);

//return the prime number right after n
//return -1 if overflow
int nextPrime(int n);

//check if n is prime number
int isPrime(int n);

//check if n is square number
int isSquareNum(int n);

//check if n is perfect number or not
int isPerfectNumber(int n);

//calculate sum of all digits of an integer number
int sumDigit(int n);

//summation of many similar terms
double sigmaSum(int lower, int upper, double(*func)(int));

#endif