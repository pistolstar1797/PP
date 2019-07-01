#include <stdio.h>
#include <string.h>
int ans;
char key[3];
char* str =
    "\
        P-P-A-P\
        I have a pen, I have a apple\
        Uh! Apple-Pen!\
        I have a pen, I have pineapple\
        Uh! Pineapple-Pen!\
        Apple-Pen, Pineapple-Pen\
        Uh! Pen-Pineapple-Apple-Pen\
        Pen-Pineapple-Apple-Pen\
    ";

int main(){
    int i;

    scanf("%s", key);

    for(i=0 ; i<strlen(str)-1 ; i++){
        if(str[i]==key[0] && str[i+1]==key[1]){
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
