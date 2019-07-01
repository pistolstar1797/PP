#include <stdio.h>
int n, cn[10000001], a[101];

int main(){
    int i, t, k;

    scanf("%d", &n);

    for(i=1 ; i<=n ; i++){
        scanf("%d", &a[i]);
    }

    for(i=1 ; i<=10000000 ; i++){
        t = i;
        k = 0;

        while(t>0){
            k = k + t%2;
            t = t>>1;
        }

        if(cn[i+k]==0 && (i+k) <= 10000000){
            cn[i+k] = i;
        }
    }

    for(i=1 ; i<=n ; i++){
        if(cn[a[i]]==0){
            printf("-1\n");
        }
        else{
            printf("%d\n", cn[a[i]]);
        }
    }

    return 0;
}

