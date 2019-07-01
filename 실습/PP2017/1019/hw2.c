#include <stdio.h>
int n, q, a[1001], r[1001], l[1001];

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

    scanf("%d", &q);

    for(i=1 ; i<=q ; i++){
        scanf("%d", &l[i]);
    }

    for(i=1 ; i<=q ; i++){
        for(j=1 ; j<=n ; j++){
            if(l[i] == r[j]+1){
                printf("%d\n", a[j]);
            }
        }
    }

    return 0;
}
