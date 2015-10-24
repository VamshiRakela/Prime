// Prime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
int GetNPrime(int n)
{
	int count = 1, number_to_be_judged = 3, pointer_of_the_prime_array, *primes;
	primes = (int*)malloc(sizeof(int)*n);
	primes[0] = 2;
	primes[1] = 3;
	while (count < n){
		pointer_of_the_prime_array = 1;
		while (primes[pointer_of_the_prime_array] * primes[pointer_of_the_prime_array] <= number_to_be_judged){
			if (number_to_be_judged % primes[pointer_of_the_prime_array] == 0){
				number_to_be_judged += 2;
				pointer_of_the_prime_array = 1;
			}
			else
				pointer_of_the_prime_array++;
		}
		primes[count++] = number_to_be_judged;
		number_to_be_judged += 2;
	}
	return primes[n - 1];
}
int pow_mod(int a, int i, int n)
{
	if (i == 0)
		return 1 % n;
	int temp = pow_mod(a, i >> 1, n);
	temp = temp*temp%n;
	if (i & 1)
		temp = temp*a%n;
	return temp;
}
bool test(int n, int a, int d)
{
	if (n == 2)
		return true;
	if (n == a)
		return true;
	if ((n & 1) == 0)
		return false;
	while (!(d & 1))
		d = d >> 1;
	int t = pow_mod(a, d, n);
	while ((d != n - 1) && (t != 1) && (t!= n - 1))
	{
		t = t*t%n;
		d = d << 1;
	}
	return (t == n - 1 || (d & 1) == 1);
}
bool isPrime(int n)
{
	int i;
	int a[5] = { 2, 3, 5, 7, 61 };
	for (i = 0; i <= 4;i++)
		if (!test(n, a[i], n - 1))
			return false;
	return true;
}
int GetNPrime2(int n)
{
	if (n == 1)return 2;
	int count, i;
	count = 1;
	i = 1;
	srand(time(NULL));
	while (count < n){
		i += 2;
		if (isPrime(i))
			count++;
	}
	return i;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n, res;
	while (scanf("%d",&n) && n != 0){
		res = GetNPrime(n);
		printf("%d\n", res);
	}
	return 0;
}

