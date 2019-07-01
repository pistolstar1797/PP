#include <stdio.h>

int my_strlen(char *str){
    int n=0;

    while(*(str+n) != '\0'){
        n++;
    }

    return n;
}

void my_strrev(char *str1, char *str2){
    int n = my_strlen(str1);
    int i;

    for(i=0 ; i<n ; i++){
        *(str2+n-1-i) = *(str1+i);
    }

    *(str2+n) = '\0';
}
/*
int main(){
    char str1[100] = "Arsenal";
    char str2[100];
    my_strrev(str1, str2);
    printf("%d\n", my_strlen(str1));
    printf("%s\n", str2);

    return 0;
}*/
