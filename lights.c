#include <stdio.h>
#include <string.h>

char g[15][15];
int lights[15][15], res;

void press(int x, int y) 
{
	lights[x][y] = !lights[x][y];
	if(x-1 >= 0)    lights[x-1][y] = !lights[x-1][y];
	if(x+1 < 10)    lights[x+1][y] = !lights[x+1][y];
	if(y-1 >= 0)    lights[x][y-1] = !lights[x][y-1];
	if(y+1 < 10)    lights[x][y+1] = !lights[x][y+1];
}

void dfs(int x, int y, int step) 
{
	if(y == 10)  x++, y = 0;
	if(step >= res) return;
	if(x == 0) {
		dfs(x, y+1, step);
		press(x, y);
		dfs(x, y+1, step+1);
		press(x, y);
	} else if(x < 10) {
		if(lights[x-1][y] == 1) {
			press(x, y);
			dfs(x, y+1, step+1);
			press(x, y);
		} else
		dfs(x, y+1, step);
	} else {
		int i;
		for(i = 0; i < 10; i++)
			if(lights[x-1][i])
				return;
			if(step < res)  res = step;
		}
	}
int main() 
{
	char name[50];
	int i, j;
	while(1) {
		scanf("%s", name);
		if(strcmp(name, "end") == 0)
			break;
		for(i = 0; i < 10; i++)
			scanf("%s", g[i]);
		for(i = 0; i < 10; i++) {
			for(j = 0; j < 10; j++) {
				lights[i][j] = g[i][j] == 'O';
			}
		}
		res = 255;
		dfs(0, 0, 0);
		printf("%s %d\n", name, res);
	}
	return 0;
}