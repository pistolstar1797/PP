#include <stdio.h>
int table[3][3], check_table[3][3], bingo[8], check_bingo[8];

int main(){
    int i, j, k, temp;

    for(i=0 ; i<3 ; i++){
        for(j=0 ; j<3 ; j++){
            scanf("%d", &table[i][j]);
        }
    }

    while(scanf("%d", &temp)!=EOF){
        for(i=0 ; i<3 ; i++){
            for(j=0 ; j<3 ; j++){
                if((table[i][j]==temp) && (check_table[i][j]==0)){
                    check_table[i][j] = 1;
                    bingo[j]++;
                    bingo[i+3]++;
                    if(i==j){
                        bingo[6]++;
                    }
                    if(i+j==2){
                        bingo[7]++;
                    }

                    for(k=0 ; k<8 ; k++){
                        if((bingo[k]==3) && (check_bingo[k]==0)){
                            check_bingo[k] = 1;
                            printf("Bingo!\n");
                        }
                    }
                }
            }
        }
    }

    return 0;
}

