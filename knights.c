#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[5][5];
int finalState[5][5] = {
	{1,1,1,1,1},
	{0,1,1,1,1},
	{0,0,2,1,1},
	{0,0,0,0,1},
	{0,0,0,0,0}
};
/*dx and dy are the directions that knights can walk*/
int dx[] = {1,-1,1,-1,2,-2,2,-2};
int dy[] = {2,2,-2,-2,1,1,-1,-1};
int min;
int blank_x, blank_y;

void findBlank()
{
	int i, j;
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			if(map[i][j] == 2){
				blank_x = i;
				blank_y = j;
				return;
			}
		}
	}
}

void move(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int findDiff()
{
	int i, j, diff=0;
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			if(map[i][j] != finalState[i][j])	diff++;
		}
	}
	return diff;
}

void dfs(int x, int y, int moves)
{
	int dir, x_next, y_next;
	int diff;	/*the difference from current state to final state*/

	if(moves >= min)	return;

	diff = findDiff();
	if(diff == 0){
		min = moves;
		return;
	}else if(diff/2 + moves >= min){
		return;
	}

	for(dir=0; dir<8; dir++){
		x_next = x + dx[dir];
		y_next = y + dy[dir];
		if(x_next<0 || x_next>=5 || y_next<0 || y_next>=5)	continue;
		move(&map[x][y], &map[x_next][y_next]);
		dfs(x_next, y_next, moves+1);
		move(&map[x][y], &map[x_next][y_next]);
	}
}

int main()
{
	int i, j;
	int testcase;
	char tmpIn[6];

	scanf("%d\n", &testcase);
	while(testcase-- > 0){
		for(i=0; i<5; i++){
			fgets(tmpIn, sizeof(tmpIn), stdin);
			getchar();
			for(j=0; j<5; j++){
				if(tmpIn[j] == '1')	map[i][j] = 1;
				else if(tmpIn[j] == '0')	map[i][j] = 0;
				else map[i][j] = 2;
			}
		}
		min = 17;
		findBlank();
		dfs(blank_x, blank_y, 0);
		if(min == 17){
			printf("Unsolvable in less than 17 move(s).\n");
		}else {
			printf("Solvable in %d move(s).\n", min);
		}
	}

	return 0;
}