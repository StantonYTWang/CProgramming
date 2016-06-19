/*Simulation*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int xMax, yMax;
int map[55][55], startX, startY;
char startDir, instruc[105];
int deadflag;

void init()
{
	memset(map, 0, sizeof(map));
}

int main()
{	
	int i;
	init();
	scanf("%d%d", &xMax, &yMax);
	while(scanf("%d %d%c%c", &startX, &startY, &startDir, &startDir) != EOF){
		/*read a instruction at a time, do simulation, only need to calculate the position, no need for do such a walk*/
		scanf("%s", instruc);
		deadflag = 0;
		for(i=0 ;i<strlen(instruc); i++){
			if(instruc[i] == 'F'){
				switch(startDir){
					case 'N' : startY++; break;
					case 'E' : startX++; break;
					case 'S' : startY--; break;
					case 'W' : startX--; break;
				}
			}else if(instruc[i] == 'R'){
				switch(startDir){
					case 'N' : startDir = 'E'; break;
					case 'E' : startDir = 'S'; break;
					case 'S' : startDir = 'W'; break;
					case 'W' : startDir = 'N'; break;
				}
			}else if(instruc[i] == 'L'){
				switch(startDir){
					case 'N' : startDir = 'W'; break;
					case 'E' : startDir = 'N'; break;
					case 'S' : startDir = 'E'; break;
					case 'W' : startDir = 'S'; break;
				}
			}
			/*judge if fall out of the edge*/
			if(startX<0 || startX >xMax || startY<0 || startY>yMax){
				switch(startDir) {
					case 'N' : startY--; break;
					case 'E' : startX--; break;
					case 'S' : startY++; break;
					case 'W' : startX++; break;
				}
				if(map[startX][startY] == 1)	continue;
				deadflag = 1;
				map[startX][startY] = 1;
				break;
			}
		}
		if(deadflag == 0)
			printf("%d %d %c\n", startX, startY, startDir);
		else 
			printf("%d %d %c LOST\n", startX, startY, startDir);
	}

	return 0;
}