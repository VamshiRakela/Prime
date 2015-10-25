// Prime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <malloc.h>

unsigned int GetNthPrime(int n)
{
	bool *primes;
	unsigned int initlen;
	if (n <= 0)
		return 0;
	else if (n <= 10)
		initlen = 30;
	else if (n <= 100)
		initlen = 542;
	else if (n <= 1000)
		initlen = 7920;
	else if (n <= 5000)
		initlen = 48612;
	else if (n <= 10000)
		initlen = 104730;
	else if (n <= 50000)
		initlen = 611954;
	else if (n <= 100000)
		initlen = 1299710;
	else if (n <= 500000)
		initlen = 7368788;
	else if (n <= 1000000)
		initlen = 15485864;
	else if (n <= 5000000)
		initlen = 86028122;
	else if (n <= 10000000)
		initlen = 179424674;
	else if (n <= 50000000)
		initlen = 982451654;
	else if (n <= 100000000)
		initlen = 2038074744;
	else
		return 0;
	primes = (bool*)malloc(sizeof(bool)*(initlen));
	unsigned int i = 0;
	for (i = 0; i < initlen; i++)
		primes[i] = 0;
	int count = 0;
	unsigned int j;
	i = 1;
	while (count < n){
		i++;
		if (primes[i] == 0){
			count++;
			j = 2 * i;
			while (j < initlen){
				primes[j] = 1;
				j = j + i;
			}
		}
	}
	free(primes);
	return i;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	unsigned int res;
	scanf("%d", &n);
	res = GetNthPrime(n);
	printf("%u\n", res);
	return 0;
}

