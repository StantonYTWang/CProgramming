#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime[1000000];
int notPrime[1000000];
int primeCnt;
int flag;

void init()
{
	primeCnt = 0;
	memset(prime, 0, sizeof(prime));
	memset(notPrime, 0, sizeof(notPrime));
}

void primeTable()
{
	int i, j;
	for(i=3; i<1000000; i+=2){
		if(notPrime[i] == 0){
			prime[primeCnt] = i;
			primeCnt++;
			for(j=3; i*j<1000000; j+=2){
				notPrime[i*j] = 1;
			}
		}
	}
}

int main()
{
	int num, x, y, i;

	init();
	primeTable();
	while(1){
		scanf("%d", &num);
		if(num == 0)	break;
		flag = 0;
		for(i=0; i<primeCnt; i++){
			x = prime[i];
			y = num - x;
			if(x > y)	break;
			if(notPrime[x]==0 && notPrime[y]==0){
				printf("%d = %d + %d\n", num, x, y);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}