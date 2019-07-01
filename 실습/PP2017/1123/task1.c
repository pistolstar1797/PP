#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i = l, j = m+1, k;
    int* temp;

    temp = (int*)malloc(sizeof(int)*(r-l+1));

    for(k=0 ; k<=r-l ; k++){
        if(i==m+1){
            temp[k] = *(arr+j);
            j++;
        }
        else if(j==r+1){
            temp[k] = *(arr+i);
            i++;
        }
        else{
            if(*(arr+i) < *(arr+j)){
                temp[k] = *(arr+i);
                i++;
            }
            else{
                temp[k] = *(arr+j);
                j++;
            }
        }
    }

    for(k=l ; k<=r ; k++){
        *(arr+k) = temp[k-l];
    }

    free(temp);
}
 
void mergeSort(int arr[], int l, int r)
{
    int m = l + (r-l)/2;
    int temp;

    if(m-l >= 1){
        mergeSort(arr, l, m);
    }
    if(r-m-1 >= 1){
        mergeSort(arr, m+1, r);
    }
    merge(arr, l, m, r);
}
/*
int main()
{
    int n;
    scanf("%d",&n);
    
    int* arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
 
    return 0;
}*/
