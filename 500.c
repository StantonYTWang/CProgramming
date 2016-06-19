#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[1500];
int answer[1500];

void BigNumMul(int *num, int n, int *answer)
{
    int i, j, t;
    int carry;
    carry = 0;
    for(i=0; i<1500; i++){
        t = answer[i] + n*num[i] + carry;
        answer[i] = t % 100;
        carry = t/100;
    }
}

int main()
{
    int n, i, headflag;
    freopen("623.in", "r", stdin);
    freopen("623_test.out", "w", stdout);

    while(scanf("%d", &n) != EOF){
        headflag = 0;
        memset(num, 0, sizeof(num)/sizeof(int));
        memset(answer, 0, sizeof(answer)/sizeof(int));
        num[0] = 1;
        for(i=1; i<n; i++){
            BigNumMul(num, i, num);
        }

        printf("%d!\n", n);
        for(i=1500-1; i>=0; i--){
            if(headflag == 0){
                if(num[i]!=0){
                    headflag = 1;
                    printf("%d", num[i]);
                }
            }else {
	   if(num[i] < 10) printf("0%d", num[i]);
                else printf("%d", num[i]);
            }
        }
        printf("\n");

    }
    return 0;
}

