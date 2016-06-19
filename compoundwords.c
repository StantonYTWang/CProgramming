/*
binary search 
use c standard bsearch, need to write the compare function by yourself
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char  words[120000][50] = {0};
int isCompound[120000] = {0};

int cmp(const void *a, const void *b)
{
	return strcmp((char*)a, (char*)b);
}

int main()
{
	int wordCnt=0;
	int i, j;
	char *wptr=0;

	while(scanf("%s", words[wordCnt]) != EOF){
		wordCnt++;
	}
	for(i=0; i<wordCnt; i++){
		for(j=i+1; j<wordCnt; j++){
			/*check if words[i] is prefix of words[j]*/
			if(isCompound[j] == 1)
				continue;
			else if(strncmp(words[i], words[j], strlen(words[i])) == 0){
				/*find suffix of words[j] in other words*/
				wptr = bsearch(words[j]+strlen(words[i]), words, wordCnt, 50, cmp);
				if(wptr != NULL)	/*found!*/
					isCompound[j] = 1;
			}else {
				break;
			}
		}
	}
	for(i=0; i<wordCnt; i++){
		if(isCompound[i] == 1){
			printf("%s\n", words[i]);
		}
	}

	return 0;
}