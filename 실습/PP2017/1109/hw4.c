#include <stdio.h>
long long n, lx, ly, rx, ry;
long long a[100001];

int main(){
    long long i, x1, y1, x2, y2;

    scanf("%lld", &n);

    scanf("%lld %lld %lld %lld", &lx, &ly, &rx, &ry);

    a[0] = (rx-lx)*(ry-ly);

    for(i=1 ; i<n ; i++){
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        if(lx < x1){
            lx = x1;
        }
        if(ly < y1){
            ly = y1;
        }
        if(rx > x2){
            rx = x2;
        }
        if(ry > y2){
            ry = y2;
        }
        if(rx <= lx || ry <= ly){
            a[i] = 0;
        }
        else{
            a[i] = (rx-lx)*(ry-ly);
        }
    }

    for(i=0 ; i<n ; i++){
        printf("%lld\n", a[i]);
    }

    return 0;
}

