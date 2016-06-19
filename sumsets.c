/*
binary search
*/
#include <stdio.h>
#include <stdlib.h>

long long int in[1000];
long long int X[1000000];
long long int a[1000000], b[1000000];
long long int indx[1000000];
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
        if(target > X[indx[mid]]){
            L = mid;

        }else if (target < X[indx[mid]]){
            U = mid;

        }else return mid;
    }
    return -1;
}

int main()
{
    int n, i, j, YIndex, flag, l;

    while(1){
        scanf("%d", &n);
        if (n==0) break;
        flag = 0;
        for (i=0; i<n; i++){
            scanf("%lld", &in[i]);
        }

        /*sort input*/
        qsort(in, n, sizeof(in[0]), cmp_input);
        
        /*count and record all the a+b possibility : a in a[], b in b[], a+b in X[], indx stores index of X[]*/
        k = 0;
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                X[k] = in[i] + in[j];
                a[k] = in[i];
                b[k] = in[j];
                indx[k] = k;
                k++;
            }
        }
        /*sort by index, check out cmp_func, the compare is according to X[] value*/
        qsort(ind, k, sizeof(long long int), cmp_func);

        for(i=n-1; i>=1; i--){
            for(j=n-1; j>=0; j--){
                Y = in[i] - in[j];  /*Y = d - c*/
                YIndex = binary_search(Y);   /*try to find Y*/

                if (YIndex>0){
                    /*check out 2 numbers to the left and 2 to the right*/
                    for (l=-2; l<=2; l++){
                        if(YIndex+l > k ) continue; /*exceed the range*/
                        if(X[indx[YIndex+l]] != Y) continue;    /*is not the answer we want*/
                        if (a[indx[YIndex+l]]==in[i] || a[indx[YIndex+l]]==in[j] || b[indx[YIndex+l]]==in[i] || b[indx[YIndex+l]]==in[j])
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
