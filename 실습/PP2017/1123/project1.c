#include <stdio.h>
#include <string.h>
int n;
char rank[10][30]
    = {"No Pair",
        "One Pair",
        "Two Pair",
        "Three Card",
        "Straight",
        "Flush",
        "Full House",
        "Four Card",
        "Straight Flush",
        "Royal Straight Flush"};
char hand[5][4];

int check(){
    int i, j, k, tmp, c[5]={0,}, t[15]={0, };

    for(i=0 ; i<5 ; i++){
        if(hand[i][0]=='S'){
            c[0]++;
        }
        else if(hand[i][0]=='D'){
            c[1]++;
        }
        else if(hand[i][0]=='C'){
            c[2]++;
        }
        else if(hand[i][0]=='H'){
            c[3]++;
        }
        if(hand[i][1]=='A'){
            t[14]++;
        }
        else if(hand[i][1]=='K'){
            t[13]++;
        }
        else if(hand[i][1]=='Q'){
            t[12]++;
        }
        else if(hand[i][1]=='J'){
            t[11]++;
        }
        else if(hand[i][1]=='T'){
            t[10]++;
        }
        else{
            t[hand[i][1]-'0']++;
        }
    }

    for(i=0 ; i<4 ; i++){
        if(c[i]==5){
            for(j=14 ; j>=2 ; j--){
                if(t[j]==1){
                    tmp = 0;

                    for(k=0 ; k<5 ; k++){
                        if(t[j-k]==1){
                            tmp++;
                        }
                    }

                    if(tmp==5){
                        if(j==14){
                            return 9;
                        }
                        else{
                            return 8;
                        }
                    }
                }
            }

            return 5;
        }
    }

    for(i=2 ; i<=14 ; i++){
        if(t[i]==4){
            return 7;
        }
        else if(t[i]==3){
            for(j=2 ; j<=14 ; j++){
                if(i!=j && t[j]==2){
                    return 6;
                }
            }
            return 3;
        }
        else if(t[i]==2){
            for(j=2 ; j<=14 ; j++){
                if(i!=j && t[j]==3){
                    return 6;
                }
                else if(i!=j && t[j]==2){
                    return 2;
                }
            }
            return 1;
        }
        else if(t[i]==1 && i<=10){
            tmp=0;

            for(j=i ; j<=i+4 ; j++){
                if(t[j]==1){
                    tmp = tmp + t[j];
                }
            }

            if(tmp==5){
                return 4;
            }
        }
    }

    return 0;
}

int main(){
    int i, j, r;

    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<5 ; j++){
            scanf("%s", hand[j]);
            if(hand[j][1]=='1' && hand[j][2]=='0'){
                hand[j][1]='T';
                hand[j][2]='\0';
            }
        }
        r = check();
        printf("%s\n", rank[r]);
    }

    return 0;
}
