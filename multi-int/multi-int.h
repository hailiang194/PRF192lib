/*
 * This include all function used for integer array
 */
#ifndef MULTI_INT_H
	#define MULTI_INT_H

#include <stdlib.h>
#include "..\constant.h"

//swap values of a and b
void swap(int *a, int *b);

//point to the first minimum value in array
int * min(int *a, int n);

//point to the first maximum value in array
int * max(int *a, int n);

//point to the first element in array that is key
//if key is not in array return NULL
//this function use linear search algorithm
int * find(int *a, int n, int key);

//remove value of element at rmIndex in a
//return the state of the removement
//if it can be removed return TRUE
//else return FALSE
int remove_at(int *a, int *n, int rmIndex);

//insert new value at index in a
//return the state of the insertion
//if it can be inserted return TRUE
//else return FALSE
int insert_at(int *a, int *n, int index, int value);

//sort the integer array
//using quick sort
void sort(int *a, int n);

//point to the element we want to find
//this use binary search
//if can't find return NULL
int * b_search(int *a, int n, int key);

//reverse array
void reverse(int *a, int n);

//using Sieve of Eratosthenes to find all prime numbers up to n
//return an array has n + 1 elements that represent is prime number or not
//if sievePrime at i is FALSE that mean i is not prime number
//else i is prime number
int * sievePrime(int n);

//get all unique integers in a 
//the quantity of unique is stored in uniLeng
int *unique(int *a, const int n, int *uniLeng);

#endif