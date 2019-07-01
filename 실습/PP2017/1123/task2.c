#include <stdio.h>
#include <math.h>
long long a, b, c, d;
int n, ans[3], cnt;

long long Calc(long long x){
    return a*x*x*x + b*x*x + c*x + d;
}

void search(long long l, long long r){
    long long f1 = Calc(l);
    long long f2 = Calc(r);
    long long m = (l+r)/2;
    long long f3 = Calc(m);

    if(f1==0){
        ans[cnt] = l;
        cnt++;
        return;
    }
    else if(f2==0){
        ans[cnt] = r;
        cnt++;
        return;
    }
    else{
        if(l<r){
            if((f1 < 0 && f3 >= 0) ||(f1 > 0 && f3 <= 0)){
                search(l, m);
            }
            else if((f3 <= 0 && f2 > 0) ||(f3 >= 0 && f2 < 0)){
                search(m, r);
            }
        }
    }
}

int main(){
    int i, j;
    long long det, min, max;

    scanf("%d", &n);

    for(i=1 ; i<=n ; i++){
        cnt = 0;

        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

        det = b*b - 3*a*c;

        if(det > 0){
            if(a>0){
                min = (-b-sqrt(det))/(3*a);
                max = (-b+sqrt(det))/(3*a);
            }
            else{
                min = (-b+sqrt(det))/(3*a);
                max = (-b-sqrt(det))/(3*a);
            }
            search(0, min);

            if(min<max){
                search(min+1, max);
            }

            search(max+1, 10000);
        }
        else{
            search(0, 10000);
        }

        for(j=0 ; j<cnt ; j++){
            printf("%d ", ans[j]);
        }

        printf("\n");
    }

    return 0;
}
