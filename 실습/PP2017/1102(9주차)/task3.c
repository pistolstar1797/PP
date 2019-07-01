#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *a[10000];
int n, cnt[10000], add[10000];

int main(){
    int i, j, check=0, tmp;
    char temp[1001];

    while(scanf("%s", temp) != EOF){
        a[n] = (char*)malloc(sizeof(char)*strlen(temp));
        
        strcpy(a[n], temp);

        n++;
    }

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n-1-i ; j++){
            if(strcmp(a[j], a[j+1]) > 0){
                strcpy(temp, a[j]);
                strcpy(a[j], a[j+1]);
                strcpy(a[j+1], temp);
            }
        }
    }

    cnt[check] = 1;
    add[check] = 0;

    for(i=1 ; i<n ; i++){
        if(strcmp(a[i-1], a[i]) != 0){
            check++;
            add[check] = i;
        }
        cnt[check]++;
    }

    for(i=0 ; i<=check ; i++){
        for(j=0 ; j<=check-1-i ; j++){
            if(cnt[j] < cnt[j+1]){
                tmp = cnt[j];
                cnt[j] = cnt[j+1];
                cnt[j+1] = tmp;
                tmp = add[j];
                add[j] = add[j+1];
                add[j+1] = tmp;
            }
        }
    }

    for(i=0 ; i<=check ; i++){
        printf("%s\n", a[add[i]]);
    }

    return 0;
}
