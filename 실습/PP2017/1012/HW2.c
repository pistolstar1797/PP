#include <stdio.h>
int n, k, ans;

int Combination(int a, int b);

int main(){
    scanf("%d %d", &n, &k);

    printf("%d\n", Combination(n, k));

    return 0;
}

int Combination(int a, int b){
    if(b==0 || a==b){
        return 1;
    }
    else{
        return Combination(a-1, b-1) + Combination(a-1, b);
    }
}
