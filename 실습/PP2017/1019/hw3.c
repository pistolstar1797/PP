#include <stdio.h>
int n, a[10000], b[10000];

int array_cmp(int N, int* A, int* B){
    int i;

    for(i=0 ; i<N ; i++){
        if(A[i] < B[i]){
            return 1;
        }
        else if(A[i] > B[i]){
            return -1;
        }
    }

    return 0;
}
/*
int main(){
    int i;

    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        scanf("%d", &a[i]);
    }

    for(i=0 ; i<n ; i++){
        scanf("%d", &b[i]);
    }

    printf("%d\n", array_cmp(n, a, b));

    return 0;
}*/
