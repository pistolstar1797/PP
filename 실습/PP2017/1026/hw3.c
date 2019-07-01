#include <stdio.h>
#include <stdlib.h>

int* number_malloc(int n){
    int* a;

    a = (int*)malloc(sizeof(int)*n);

    int i;

    for(i=0 ; i<n ; i++){
        a[i] = i+1;
    }

    return a;
}
/*
int main(){
    int* arr;
    int num;
    
    scanf("%d", &num);
    arr = number_malloc(num);
    
    int i;
    
    for(i=0 ; i<num ; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}*/
