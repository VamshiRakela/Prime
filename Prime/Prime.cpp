// Prime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <malloc.h>
const int segment_size = 262144;
unsigned int GetNthPrime(int n)
{
	bool *li_primes;
	bool *sieve;
	int *primes;
	int *next;
	unsigned int initlen;
	unsigned int bound;
	if (n <= 0){
		printf("n cannot be lower than 1 !\n");
		return 0;
	}
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
	else{
		printf("out of range!\n");
		return 0;
	}
	sieve = (bool*)malloc(sizeof(bool)*segment_size);
	li_primes = (bool*)malloc(sizeof(bool)*(bound + 1));
	primes = (int*)malloc(sizeof(int)*(initlen));
	next = (int*)malloc(sizeof(int)*(initlen));
	int count = 0;
	for (int i = 2; i <= bound; i++)
		li_primes[i] = 0;
	for (int i = 2; i*i <= bound; i++){
		if (li_primes[i] == 0){
			count++;
			if (count == n)
				return i;
			for (int j = i*i; j <= bound; j += i)
				li_primes[j] = 1;
		}
	}	
	unsigned int s = 2;
	unsigned int l = 3;
	unsigned int pPrimes = 0;
	unsigned int pNext = 0;
	count = 1;
	for (unsigned int low = 0; low <= initlen; low += segment_size){
		for (int i = 0; i < segment_size; i++)
			sieve[i] = 0;
		unsigned int high = low + segment_size - 1 < initlen - 1 ? low + segment_size - 1 : initlen - 1;
		for (; s*s <= high; s++){
			if (li_primes[s] == 0){
				primes[pPrimes++] = s;
				next[pNext++] = s*s - low;
			}
		}
		for (unsigned int i = 1; i < pPrimes; i++){
			int j = next[i];
			for (int k = primes[i] * 2; j < segment_size; j += k)
				sieve[j] = 1;
			next[i] = j - segment_size;
		}
		for (; l <= high;l+=2)
			if (sieve[l - low] == 0){
				count++;
				if (count == n)
					return l;
			}
	}
	//while (1){
	//	i++;
	//	if (primes[i] == 0){
	//		count++;
	//		if (count == n)
	//			break;
	//		if (i <= bound){
	//			j = i * i;
	//			while (j < initlen){
	//				primes[j] = 1;
	//				j = j + i;
	//			}
	//		}
	//	}
	//}
	free(primes);
	return 0;
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

