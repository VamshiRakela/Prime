// Prime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <malloc.h>

unsigned int GetNthPrime(int n)
{
	bool *primes;
	unsigned int initlen;
	unsigned int bound;
	if (n <= 0)
		return 0;
	else if (n <= 10){
		initlen = 30;
		bound = 5;
	}
	else if (n <= 100){
		initlen = 542;
		bound = 23;
	}
	else if (n <= 1000){
		initlen = 7920;
		bound = 88;
	}
	else if (n <= 5000){
		initlen = 48612;
		bound = 220;
	}
	else if (n <= 10000){
		initlen = 104730;
		bound = 323;
	}
	else if (n <= 50000){
		initlen = 611954;
		bound = 782;
	}
	else if (n <= 100000){
		initlen = 1299710;
		bound = 1140;
	}
	else if (n <= 500000){
		initlen = 7368788;
		bound = 2714;
	}
	else if (n <= 1000000){
		initlen = 15485864;
		bound = 3935;
	}
	else if (n <= 5000000){
		initlen = 86028122;
		bound = 9275;
	}
	else if (n <= 10000000){
		initlen = 179424674;
		bound = 13394;
	}
	else if (n <= 50000000){
		initlen = 982451654;
		bound = 31344;
	}
	else if (n <= 100000000){
		initlen = 2038074744;
		bound = 45145;
	}
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
			if (i <= bound){
				j = 2 * i;
				while (j < initlen){
					primes[j] = 1;
					j = j + i;
				}
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

