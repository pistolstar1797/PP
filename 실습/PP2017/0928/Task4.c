#include <stdio.h>
char a[1002];
int n;

int main(){
    int i, check=0;

    scanf("%d", &n);
    scanf("%s", a);

    for(i=0 ; i<n ; i++){
        if(a[i] >= 'a' && a[i] <='z'){
            a[i] = a[i] - 'a' + 'A';
        }
    }

    for(i=0 ; i<n/2 ; i++){
        if(a[i]!=a[n-1-i]){
            check = 1;
            break;
        }
    }

    if(check==0){
        printf("True\n");
    }
    else if(check==1){
        printf("False\n");
    }

    return 0;
}
