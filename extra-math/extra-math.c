#include "extra-math.h"

int powInt(int x, int y)
{
	int s = 1, i = 0;

    for(i = 1; i <= y; i++) 
    {
        s = s * x;
    }
        
    return s;
}

int fact(int n)
{
	int product = 1, i = 0;

	for(i = 2; i <= n; i++)
	{
		product *= i;
	}

	return product;
}

int nCk(int n, int k)
{	
	if(n < k)
		return 0;

	int fracN = 1, fracK = 1, fracNMinusK = 1, i = 1;

	/* we have k <= n and (n - k) <= n
	 * that mean k! <= n! and (n - k)! <= n!
	 */

	for (i = 1; i <= n; ++i)
	{
		fracN *= i;

		if(i == k)
			fracK = fracN;

		if(i == n - k)
			fracNMinusK = fracN;
	}

	return (fracN / (fracK * fracNMinusK));
}

int GCD(int a, int b)
{
	if((a <= 0) || (b <= 0))
		return -1;

	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
	}

	return a;
}

int LCM(int a, int b)
{
	int gcd = GCD(a, b);

	if(gcd == -1)
		return -1;

	return (a * b) / gcd;
}

int isPrime(int n)
{
	if(n < 2)
		return FALSE;

	/* all even numbers except 2 are not prime numbers
	 */
	if(n == 2)
		return TRUE;

	if(n % 2 == 0)
		return FALSE;

	for(int i = 3; i <= sqrt(n); i += 2)
	{
		if(n % i == 0)
			return FALSE;
	}

	return TRUE;
}

int isSquareNum(int n)
{
	const int SQRT_N = (int)sqrt(n);

	return(SQRT_N * SQRT_N == n);
}

int nextPrime(int n)
{	
	if(n < 2)
		return 2;

	/* we all know that, all even numbers except 2 are not prime number
	 * so, we just need to check all the odd numbers are prime number or not
	 * it helps our function run faster
	 */
	const int START = (n % 2 == 0) ? (n + 1) : (n + 2);

	for(int i = START; TRUE; i += 2)
	{

		if(i < 0)
			return -1;

		if(isPrime(i))
			return i;
	}  
}

int isPerfectNumber(int n)
{
	/*
	 * Because if a factor is greater than the square root of n,
	 * the other factor that would multiply with it to equal n is less than the square root of n
	 * DivSum = 1 because 1 is alway a division of n
	 */
	int DivSum = 1;
	
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0)
		{
			DivSum += i;
			DivSum += (n / i);
		}
	}
	
	return (DivSum == n);
}

int sumDigit(int n)
{
	int sum = 0, digit = 0;
	while(n > 0)
	{
		digit = n % 10;

		sum += digit;

		n /= 10;
	}

	return sum;
}

double sigmaSum(int lower, int upper, double(*func)(int))
{
	double sum = 0.0;

	for(int i = lower; i <= upper; i++)
	{
		sum += (*func)(i);
	}

	return sum;
}