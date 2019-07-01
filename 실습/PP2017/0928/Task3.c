#include <stdio.h>
int a[1001], n;

int main(){
    int i, temp;

    while(scanf("%d", &temp)!=EOF){
        a[n] = temp;
        n++;

        if(getchar()=='\n'){
            break;
        }
    }

    for(i=n-1 ; i>=0 ; i--){
        printf("%d ", a[i]);
    }

    return 0;
}
