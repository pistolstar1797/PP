#include <stdio.h>
int n, ans;

int diag(int x){
    return 4*(x-2)*(x-2) + 10*(x-1);
}

int main(){
    int i;

    scanf("%d", &n);

    ans = 1;

    for(i=3 ; i<=n ; i+=2){
        ans = ans + diag(i);
    }

    printf("%d", ans);

    return 0;
}
