#include <stdio.h>
#include <stdlib.h>

int* sort_array(int n, int* arr){
    int* a;
    int i, j, temp;

    a = (int*)malloc(sizeof(int)*n);
    a = arr;

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n-1-i ; j++){
            if(*(a+j) < *(a+j+1)){
                temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }

    return a;
}
/*
int main(){
    int* sorted;
    int original[10] = {2,1,3,4,5,8,10,7,6,9};
    
    sorted = sort_array(10, original);
    
    int i;
 
    for(i=0 ; i<10 ; i++){
        printf("%d ", sorted[i]);
    }

    return 0;
}*/
