#include <stdio.h>
int n, m, l, r;
int a[100001];

int main(){
    int i, sum, tl;

    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        scanf("%d", &a[i]);
    }

    m = a[0];
    tl = 0;
    r = 0;
    sum = a[0];

    for(i=1 ; i<n ; i++){
        if(sum < 0){
            sum = a[i];
            tl = i;
        }
        else{
            sum = sum + a[i];
        }
        if(m < sum){
            m = sum;
            l = tl;
            r = i;
        }
    }

    if(n >= 1000){
        printf("big\n");
    }
    else{
        printf("small\n");
    }
    printf("%d,%d\n", l, r);
    printf("%d\n", m);

    return 0;
}
