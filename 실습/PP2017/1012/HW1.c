#include <stdio.h>
int n;
long long a[51];

int main(){
    int i;

    scanf("%d", &n);

    a[0] = 0;
    a[1] = 1;

    for(i=2 ; i<=n ; i++){
        a[i] = a[i-1] + a[i-2];
    }

    printf("%lld\n", a[n]);

    return 0;
}
