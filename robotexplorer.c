/*Simulation*/
/*
This is a question of simulation.
just simulate the 'walk' behavior, no need for actually do the walk on map
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int xMax, yMax;	/*x y boundary*/
int map[55][55], startX, startY;	/*map records the dead robot position*/
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
		/*
		read all instructions in, and do one at a time;
		Use simulation, only need to calculate the position, no need for do such a walk
		*/
		scanf("%s", instruc);
		deadflag = 0;	/*to indicate the robot falls out of the world or not*/
		for(i=0 ;i<strlen(instruc); i++){
			if(instruc[i] == 'F'){	/*F instruction is to walk a step forward*/
				switch(startDir){
					case 'N' : startY++; break;
					case 'E' : startX++; break;
					case 'S' : startY--; break;
					case 'W' : startX--; break;
				}
			}else if(instruc[i] == 'R'){	/*R instruction is the turn right*/
				switch(startDir){
					case 'N' : startDir = 'E'; break;
					case 'E' : startDir = 'S'; break;
					case 'S' : startDir = 'W'; break;
					case 'W' : startDir = 'N'; break;
				}
			}else if(instruc[i] == 'L'){		/*L instruction is the turn left*/
				switch(startDir){
					case 'N' : startDir = 'W'; break;
					case 'E' : startDir = 'N'; break;
					case 'S' : startDir = 'E'; break;
					case 'W' : startDir = 'S'; break;
				}
			}
			/*judge if fall out of the edge, is fall mark the deadflag*/
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