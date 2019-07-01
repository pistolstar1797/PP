#include <stdio.h>
#include <string.h>
typedef struct inform{
    char name[20];
    int budget;
    int value;
} Inform;

int check_who(Inform *player, char *who){
    int i;

    for(i=0 ; i<2 ; i++){
        if(strcmp(who, player[i].name)==0){
            return i;
        }
    }

    return 0;
}

int poor(int a, int b){
    if(a<b){
        printf("NOT ENOUGH MONEY\n");
        return 0;
    }

    return 1;
}

void add(Inform *a){
    int v;
    scanf("%d", &v);
    a->budget += v;
}

void minus(Inform *a){
    int v;
    scanf("%d", &v);
    if(poor(a->budget, v)){
        a->budget -= v;
    }
}

void show(Inform *a){
    printf("%d\n", a->budget);
}

void value(Inform *a){
    int v;
    scanf("%d", &v);
    a->value = v;
}

int raise(Inform *player, int t, int bet){
    if(bet > player[1-t].budget){
        return t;
    }

    return -1;
}

int call(Inform *player){
    if(player[0].value > player[1].value){
        return 0;
    }
    else if(player[0].value == player[1].value){
        return 2;
    }
    else{
        return 1;
    }
}

int fold(int t){
    return 1-t;
}

void start(Inform *player){
    int t, win, bet, check;
    char who[10], com[10];

    check = 0;
    bet = 100;

    while(1){
        scanf("%s", who);

        t = check_who(player, who);

        scanf("%s", com);

        if(strcmp(com, "RAISE")==0){
            if(poor(player[t].budget, 2*bet)){
                check = 0;
                bet *= 2;

                win = raise(player, t, bet);
                if(win!=-1){
                    bet /= 2;
                    break;
                }
            }
        }

        if(strcmp(com, "CALL")==0){
            check++;

            if(check==2){
                win = call(player);

                if(win==2){
                    return;
                }

                break;
            }
        }

        if(strcmp(com, "FOLD")==0){
            win = fold(t);
            bet /= 2;
            break;
        }
    }

    if(win==2){
        return;
    }

    player[win].budget += bet;
    player[1-win].budget -= bet;
}


int main(){
    Inform player[2];
    strcpy(player[0].name, "HUMAN");
    strcpy(player[1].name, "COMPUTER");

    int t, i;
    char who[10], com[10];

    for(i=0 ; i<2 ; i++){
        player[i].budget = 0;
        player[i].value = 0;
    }

    while(scanf("%s", who)!=EOF){
        t = check_who(player, who);

        scanf("%s", com);

        if(strcmp(com, "ADD")==0){
            add(&player[t]);
        }
        if(strcmp(com, "MINUS")==0){
            minus(&player[t]);
        }
        if(strcmp(com, "SHOW")==0){
            show(&player[t]);
        }
        if(strcmp(com, "VALUE")==0){
            value(&player[t]);
        }
        if(strcmp(com, "START")==0 && poor(player[t].budget, 100)){
            start(player);
        }
    }

    return 0;
}
