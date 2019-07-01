#include <stdio.h>
int n, x[1001], y[1001], max, min;

int abs(int k);

int main(){
    int i, j;

    scanf("%d", &n);

    for(i=1 ; i<=n ; i++){
        scanf("%d %d", &x[i], &y[i]);
    }

    max = abs(x[1]-x[2]) + abs(y[1]-y[2]);
    min = abs(x[1]-x[2]) + abs(y[1]-y[2]);

    for(i=1 ; i<=n ; i++){
        for(j=i+1 ; j<=n ; j++){
            if(max < abs(x[i]-x[j]) + abs(y[i]-y[j])){
                max = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            }
            else if(min > abs(x[i]-x[j]) + abs(y[i]-y[j])){
                min = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            }
        }
    }

    printf("%d\n%d\n", min, max);

    return 0;
}

int abs(int k){
    if(k<0){
        return -k;
    }
    else{
            return k;
    }
}
