#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[101][101], maxpnum, page[101], pagecnt;

void init()
{
	memset(map, 0, sizeof(map));
	maxpnum = 0;
	pagecnt = 0;
	memset(page, 0, sizeof(page));
}

void putInMap(int a, int b)
{
	if(a > maxpnum)	maxpnum = a;
	if(b > maxpnum)	maxpnum = b;
	if(page[a] != 1){
		page[a] = 1;
		pagecnt++;
	}
	if(page[b] != 1){
		page[b] = 1;
		pagecnt++;
	}
	map[a][b] = 1;

}

void weight()
{
	int i, j;
	for(i=1; i<=maxpnum; i++){
		for(j=1; j<=maxpnum; j++){
			if(i!=j && map[i][j]==0)	map[i][j] = 6000;
		}
	}
}

void FW()
{
	int i, j, k;
	for(k=1; k<=maxpnum; k++){
		for(i=1; i<=maxpnum; i++){
			for(j=1; j<=maxpnum; j++){
				if(map[i][k]+map[k][j] < map[i][j])	map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
}

int countSum()
{
	int i, j, sum;
	sum = 0;
	for(i=1; i<=maxpnum; i++){
		for(j=1; j<=maxpnum; j++){
			if(i!=j && map[i][j]<4901)	sum += map[i][j];
		}
	}
	return sum;
}

int main()
{
	int  pagea, pageb, testcase, sum;

	testcase = 0;
	while(1){
		scanf("%d%d", &pagea, &pageb);
		if(pagea==0 && pageb==0)	break;
		testcase++;
		init();
		putInMap(pagea, pageb);
		while(1){
			scanf("%d%d", &pagea, &pageb);
			if(pagea==0 && pageb==0)	break;
			putInMap(pagea, pageb);
		}
		weight();
		FW();
		sum = countSum();
		printf("Case %d: average length between pages = %1.3f clicks\n", testcase, (float)sum/(float)(pagecnt*(pagecnt-1)));
	}

	return 0;
}