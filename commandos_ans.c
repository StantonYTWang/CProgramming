/*
use all-pair-shortest-path
weigth() and floyd-warshall()
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b)
{
    if(a > b)   return b;
    else return a;
}

int max(int a, int b)
{
    if(a > b)   return a;
    else return b;
}

int main() {
    int testcase, cases = 0;
    int n, m, i, j, k;
    int start, finish;
    int map[101][101] = {};
    int ans = 0;

    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d", &n, &m);
        ans = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(i != j)
                    map[i][j] = 0xffff; /*weitht() : i!=j and no path between i, j place 256 as infinite*/
                while(m--) {
                    scanf("%d %d", &i, &j);
                    map[i][j] = 1;
                    map[j][i] = 1;
                }
                scanf("%d %d", &start, &finish);
                for(k = 0; k < n; k++)
                    for(i = 0; i < n; i++)
                        for(j = 0; j < n; j++)
                            map[i][j] = min(map[i][k]+map[k][j], map[i][j]);    /*Floyd-Warshall*/
                        for(i = 0; i < n; i++){
                            /*walk from start to finish try all the possible node in middle, find max path*/
                            ans = max(ans, map[start][i]+map[i][finish]);
                        }
                        printf("Case %d: %d\n", ++cases, ans);
                    }
                    return 0;
                }