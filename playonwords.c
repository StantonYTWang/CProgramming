#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordNum;
int map[26][26];
int outdeg[26], indeg[26];
int start, end, startNum, endNum, diff;
int visited[26], answer;

void init()
{
	memset(map, 0, sizeof(map));
	memset(outdeg, 0, sizeof(outdeg));
	memset(indeg, 0, sizeof(indeg));
	memset(visited, 0, sizeof(visited));
	startNum = 0;
	endNum = 0;
	diff = 0;
	answer = 0;
}

void walk(int node)
{
	int i;
	if(visited[node])
		return;
	visited[node] = 1;
	for(i=0; i<26; i++){
		if(map[node][i])
			walk(i);
	}
}

int main()
{
	int testcase, m, i, j, len;
	char word[1001];

	scanf("%d", &testcase);
	while(testcase-- > 0){
		init();
		scanf("%d\n", &wordNum);
		for(m=0; m<wordNum; m++){
			scanf("%s", word);
			len = strlen(word);
			i = word[0] - 'a';
			j = word[len - 1] - 'a';
			map[i][j]++;	/*construct map, add outdeg of i and indeg of j */
			outdeg[i]++;
			indeg[j]++;
		}
		/*find start point and end point, also check for the graph is usable or not*/
		for(i=0; i<26; i++){
			if(indeg[i] + 1 == outdeg[i]){
				/*out-degree is 1 more than in-degree : start vertex*/
				start = i;
				startNum++;
			}else if(outdeg[i] + 1 == indeg[i]){
				/*in-degree is 1 more than out-degree : end vertex*/
				end = i;
				endNum++;
			}else{
				/*check for the vertex which in!=out and not start or end*/
				if(indeg[i] != outdeg[i])
					diff++;
			}
		}
		if(startNum==1 && endNum==1 && diff==0){
			answer = 1;
			walk(start);
			for(i = 0; i < 26; i++) {
                			if(indeg[i] != 0 || outdeg[i] != 0) {
                    				/*if any vertex is not visited, doesn't work*/
                    				if(visited[i] == 0)
                       					answer = 0;
                			}
            			}
		}else {
			if(startNum==0 && endNum==0 && diff==0){
				answer = 1;
				for(i=0; i<26; i++){
					if(indeg[i])
						start = i;
				}
				walk(start);
				for(i = 0; i < 26; i++) {
                				if(indeg[i] != 0 || outdeg[i] != 0) {
                    					/*if any vertex is not visited, doesn't work*/
                    					if(visited[i] == 0)
                       						answer = 0;
                				}
            				}
			}else answer = 0;
		}
		if(answer)
           			printf("Ordering is possible.\n");
        		else
            			printf("The door cannot be opened.\n");
	}
	return 0;
}