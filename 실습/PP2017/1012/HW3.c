#include <stdio.h>
int n, a[1001], r[1001];

int main(){
    int i, j;

    scanf("%d", &n);

    for(i=1 ; i<=n ; i++){
        scanf("%d", &a[i]);
    }

    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=n ; j++){
            if(a[i] < a[j]){
                r[i]++;
            }
        }
    }

    for(i=1 ; i<=n ; i++){
        printf("%d ", r[i]+1);
    }

    printf("\n");

    return 0;
}
