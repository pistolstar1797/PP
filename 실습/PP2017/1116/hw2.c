#include <stdio.h>
int a[1000], n;
typedef int (*Calc)(int, int);

int plus(int a, int b){
    return a+b;
}

int minus(int a, int b){
    return a-b;
}

int mult(int a, int b){
    return a*b;
}

int main(){
    char temp;
    Calc t;

    scanf("%d %d", &a[0], &a[1]);
    n = 2;

again:

    while(n>1){
        
        scanf(" %c", &temp);
        
        if(temp >= '0' && temp <= '9'){
            a[n] = temp - '0';
            n++;
        }
        else{
            switch(temp){
                case '+': t = plus; break;
                case '-': t = minus; break;
                case '*': t = mult; break;
            }

            a[n-2] = t(a[n-2], a[n-1]);
            n--;
        }
    }

    if(scanf(" %c", &temp)!=EOF){
        a[1] = temp - '0';
        n++;
        goto again;
    }

    printf("%d", a[0]);

    return 0;
}
