#include "multi-int.h"

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t; 
}

int * min(int *a, int n)
{
	int *pMin = a;
	
	for(int i = 1; i < n; i++)
	{
		if(a[i] < *pMin)
		{
			pMin = &a[i];	
		}	
	}	
	
	return pMin;
}

int * max(int *a, int n)
{

	int *pMax = a;
	
	for(int i = 1; i < n; i++)
	{
		if(a[i] > *pMax)
		{
			pMax = &a[i];	
		}	
	}	
	
	return pMax;
}


int * find(int *a, int n, int key)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == key)
			return &a[i];
	}
	
	return 0; //return NULL
}

int remove_at(int *a, int *n, int rmIndex)
{
	if((rmIndex < 0) || (rmIndex > (*n) - 1))
		return FALSE;

	for(int i = rmIndex; i < (*n) - 1; i++)
	{
		a[i] = a[i + 1];
	}

	(*n)--;

	return TRUE;
}


int insert_at(int *a, int *n, int index, int value)
{
	if((index < 0) || (index > (*n) - 1))
		return FALSE;

	for(int i = (*n); i > index; i--)
	{
		a[i] = a[i - 1];
	}

	a[index] = value;

	(*n)++;

	return TRUE;
}

void sort(int *a, int n)
{
	if(n <= 1)
		return;

	int *left = &a[1];
	int *right = &a[n - 1];

	while(left <= right)
	{
		while((left <= right) && ((*left) <= a[0]))
			left++;

		while((left <= right) && ((*right) > a[0]))
			right--;

		if(left < right)
		{
			swap(left, right);
			left++;
			right--;
		}
	}

	swap(&a[0], right);

	sort(a, (right - 1) - a + 1);
	sort(right + 1, n - (right + 1 - a));
}

int * b_search(int *a, int n, int key)
{
	int first = 0, last = n - 1;
	
	while(first <= last)
	{
		int mid = (first + last) / 2;
		
		if(a[mid] == key)
			return &a[mid];
			
		if(a[mid] > key)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return 0; //return NULL
}

void reverse(int *a, int n)
{
	int *left = &a[0];
	int *right = &a[n - 1];

	while(left < right)
	{
		swap(left, right);
		left++;
		right--;
	}
}

int * sievePrime(int n)
{
	int * isPrime = (int *)malloc((n + 1) * sizeof(int));

	for(int i = 0; i <= n; i++)
		isPrime[i] = TRUE;

	isPrime[0] = FALSE;
	isPrime[1] = FALSE;

	for(int i = 2; i <= n; i++)
	{
		if(isPrime[i] == FALSE)
			continue;

		for(int j = 2 * i; j <= n; j += i)
			isPrime[j] = FALSE;
	}

	return isPrime;
}

int *unique(int *a, const int n, int *uniLeng)
{
	sort(a, n);
	
	(*uniLeng) = 0;
	
	int *uniValue = (int *)calloc((*uniLeng), sizeof(int));
	
	uniValue[(*uniLeng)++] = a[0];
	
	for(int i = 1; i < n; i++)
	{
		if(a[i - 1] != a[i])
			uniValue[(*uniLeng)++] = a[i];
	}
	
	uniValue = (int *)realloc(uniValue, (*uniLeng) * sizeof(int));
	
	return uniValue;
}