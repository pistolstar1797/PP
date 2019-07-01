#include <stdio.h>
#include <stdlib.h>
int n, m;
int *a, *b, *c;

int main(){
    int i, j, t;

    scanf("%d %d", &n, &m);

    a = (int*)malloc(sizeof(int)*n);
    b = (int*)malloc(sizeof(int)*m);
    c = (int*)malloc(sizeof(int)*(n+m));

    for(i=0 ; i<n ; i++){
        scanf("%d", a+i);
    }

    for(i=0 ; i<m ; i++){
        scanf("%d", b+i);
    }

    i=0;
    j=0;
    t=0;

    while(t<n+m){
        if(i==n){
            *(c+t) = *(b+j);
            j++;
        }
        else if(j==m){
            *(c+t) = *(a+i);
            i++;
        }
        else{
            if(*(a+i) < *(b+j)){
                *(c+t) = *(a+i);
                i++;
            }
            else{
                *(c+t) = *(b+j);
                j++;
            }
        }

        t++;
    }

    for(i=0 ; i<t ; i++){
        printf("%d ", *(c+i));
    }

    return 0;
}
