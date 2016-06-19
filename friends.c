/*
DFS problem
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 0
#define GRAY 1

int peoples, pairs;
int *friend;
int *color;
int max, count;

void init()
{
	memset(friend, 0, sizeof(friend));
	memset(color, 0, sizeof(color));
	max = 0;
}

void DFS_visit(int v)
{
	int i;
	color[v] = GRAY;
	for(i=1; i<=peoples; i++){
		if(friend[v*peoples+i] == 1 && color[i] == WHITE){
			count++;
			DFS_visit(i);
		}
	}
	if(count > max)	max = count;
}

void DFS(int v)
{
	int i;
	count = 0;
	for(i=1; i<=peoples; i++){
		if(color[i] == WHITE){
			count++;
			DFS_visit(i);
		}
		count = 0;
	}
}

int main()
{
	int testcase, n, i, j;
	int p1, p2;

	scanf("%d", &testcase);
	while(testcase-- > 0){
		
		scanf("%d %d", &peoples, &pairs);
		friend = malloc((peoples+1)*(peoples+1)*sizeof(int));
		color = malloc((peoples+1)*sizeof(int));
		init();
		for(n=0; n<pairs; n++){
			scanf("%d %d", &p1, &p2);
			friend[p1*peoples+p2] = 1;
			friend[p2*peoples+p1] = 1;
		}
		DFS(1);
		printf("%d\n", max);
	}
	return 0;
}