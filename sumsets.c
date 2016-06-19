#include <stdio.h>
#include <stdlib.h>

long long int in[1000];
long long int X[1000000];
long long int a[1000000], b[1000000];
long long int ind[1000000];
long long int Y;
int k;

int cmp_func(const void *a, const void *b)
{
    long long int A, B;
    A = *(long long int *) a;
    B = *(long long int *) b;
    if (X[A] > X[B]) return 1;
    else if (X[A] == X[B]) return 0;
    else return -1;
}

int cmp_input(const void *a, const void *b)
{
    long long int ina, inb;
    ina = *(long long int *) a;
    inb = *(long long int *) b;
    if (ina > inb) return 1;
    else if (ina == inb) return 0;
    else return -1;
}

int binary_search(int target)
{
    long long int U = k-1;
    long long int L = 0;
    long long int mid;
    while(U - L > 1){
        mid = (U + L)/2;
        if(target > X[ind[mid]]){
            L = mid;

        }else if (target < X[ind[mid]]){
            U = mid;

        }else return mid;
    }
    return -1;
}

int main()
{
    int n, i, j, check, flag, l;

    while(1){
        scanf("%d", &n);
        if (n==0) break;
        flag = 0;
        for (i=0; i<n; i++){
            scanf("%lld", &in[i]);
        }
        qsort(in, n, sizeof(in[0]), cmp_input);
        
        k = 0;
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                X[k] = in[i] + in[j];
                a[k] = in[i];
                b[k] = in[j];
                ind[k] = k;
                k++;
            }
        }
     
        qsort(ind, k, sizeof(long long int), cmp_func);

        for(i=n-1; i>=1; i--){
            for(j=n-1; j>=0; j--){
                Y = in[i] - in[j];
                check = binary_search(Y);

                if (check>0){
                    for (l=-2; l<=2; l++){
                        if(check+l > k ) continue;
                        if(X[ind[check+l]] != Y) continue;
                        if (a[ind[check+l]]==in[i] || a[ind[check+l]]==in[j]
                        || b[ind[check+l]]==in[i] || b[ind[check+l]]==in[j])
                            continue;
                        else {
                            printf("%lld\n", in[i]);
                            flag = 1;
                        }
                        if(flag) break;
                    }

                }else continue;
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) printf("no solution\n");

    }
    return 0;
}
