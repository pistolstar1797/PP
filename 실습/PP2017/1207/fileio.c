#include <stdio.h>
#include <string.h>
FILE *fp1, *fp2, *fp3;
char dic[100][51], dic_t[100][51], con[5000][51], con_t[5000][51];
int cnt_d, cnt_c;

int main(){
    int i, j, check=0, cnt_t=0;
    char c;

    fp1 = fopen("dict.txt", "r");
    fp2 = fopen("input.txt", "r");
    fp3 = fopen("output.txt", "w");

    while(fscanf(fp1, "%s", dic[cnt_d++])!=EOF);

    for(i=0 ; i<cnt_d ; i++){
        for(j=0 ; j<strlen(dic[i]) ; j++){
            if(dic[i][j] >= 'A' && dic[i][j] <= 'Z'){
                dic_t[i][j] = dic[i][j] - 'A' + 'a';
            }
            else{
                dic_t[i][j] = dic[i][j];
            }
        }
    }

    while(!feof(fp2)){
        c = fgetc(fp2);
        if((c >= 'A' && c <='Z') || (c >= 'a' && c <= 'z')){
            if(check!=0){
                cnt_c++;
                cnt_t = 0;
                check = 0;
            }
            con[cnt_c][cnt_t++] = c;

            if(c >= 'A' && c <= 'Z'){
                con_t[cnt_c][cnt_t-1] = c - 'A' + 'a';
            }
            else{
                con_t[cnt_c][cnt_t-1] = c;
            }
        }
        else{
            check++;
        }
    }

    for(i=0 ; i<cnt_c ; i++){
        check = 0;

        for(j=0 ; j<cnt_d ; j++){
            if(strcmp(con_t[i], dic_t[j])==0){
                check = 1;
            }
        }

        if(check==0){
            fprintf(fp3, "%s\n", con[i]);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}
