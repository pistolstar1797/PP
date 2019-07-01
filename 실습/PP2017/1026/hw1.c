#include <stdio.h>
char a[10001];
int cnt;

int main(){
    
    while(1){
        if(scanf("%s", a) == EOF){
            break;
        }
        else{
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}
