#include <stdio.h>
#include <string.h>
int ans[26];
char a[1002];

int main(){
    int i;

    scanf("%s", a);

    for(i=0 ; i<strlen(a) ; i++){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            ans[a[i]-'A']++;
        }
        else if(a[i] >= 'a' && a[i] <= 'z'){
            ans[a[i]-'a']++;
        }
    }

    for(i=0 ; i<26 ; i++){
        if(ans[i]!=0){
            printf("%c %d\n", i + 'a', ans[i]);
        }
    }

	return 0;
}
