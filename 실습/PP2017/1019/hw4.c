#include <stdio.h>
int n, m, cnt, a[1000], b[1000], ans[1000];

int main(){
    int i, j, check;

    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);

    for(i=0 ; i<m ; i++){
        scanf("%d", &b[i]);
    }

    for(i=0 ; i<=n-m ; i++){
        check = 0;

        for(j=0 ; j<m ; j++){
            if(a[i+j]!=b[j]){
                check = 1;
            }
        }

        if(check==0){
            ans[cnt] = i;
            cnt++;
        }
    }

    printf("%d\n", cnt);

    for(i=0 ; i<cnt ; i++){
        printf("%d ", ans[i]);
    }

    printf("\n");

    return 0;
}
