#include <stdio.h>
int n;
long long price[100001], cost, profit;

int main(){
    int i;
    long long cnt, max;

    scanf("%d", &n);

    for(i=1 ; i<=n ; i++){
        scanf("%lld", &price[i]);
    }

    price[0] = 10000000000;
    cnt = 0;
    max = price[n];

    for(i=n ; i>=1 ; i--){
        if(max >= price[i-1]){
            cnt++;
            cost = cost + price[i-1];
        }
        else{
            profit = profit + cnt*max;
            cnt = 0;
            max = price[i-1];
        }
    }

    printf("%lld", profit - cost);

    return 0;
}
