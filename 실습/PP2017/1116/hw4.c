#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ls{
    int value;
    struct ls *next;
} Elmt;
typedef Elmt *LIST;

LIST a[1000];
int n, size[1000];
char name[1000][20];
char Com[20];

int main(){
    char temp[20], temp2[20];
    int index, v, i, ln, ln2, check;
    LIST New, New2;

    while(scanf("%s", Com)!=EOF){
        scanf("%s", temp);
        ln = 0;
        ln2 = 0;
        check = 0;

        for(i=0 ; i<n ; i++){
            if(strcmp(temp, name[i])==0){
                ln = i;
                check = 1;
                break;
            }
        }

        if(check==0 && strcmp(Com, "MAKE")!=0){
            continue;
        }

        if(check==0 && strcmp(Com, "MAKE")==0){
            a[n] = malloc(sizeof(Elmt));
            a[n]->next = NULL;

            strcpy(name[n], temp);
            n++;
        }
        if(strcmp(Com, "PUSH_FRONT")==0){
            scanf("%d", &v);

            New = malloc(sizeof(Elmt));
            New->next = a[ln];
            New->value = v;
            a[ln] = New;

            size[ln]++;
        }
        if(strcmp(Com, "PUSH_BACK")==0){
            scanf("%d", &v);

            New = malloc(sizeof(Elmt));
            New2 = a[ln];

            if(size[ln]==0){
                New->next = a[ln];
                New->value = v;
                a[ln] = New;
            }
            else{
                for(i=0 ; i<size[ln]-1 ; i++){
                    New2 = New2->next;
                }

                New->value = v;
                New->next = NULL;
                New2->next = New;
            }

            size[ln]++;
        }
        if(strcmp(Com, "PRINT_FRONT")==0){
            if(size[ln]==0){
                continue;
            }

            printf("%d\n", a[ln]->value);
        }
        if(strcmp(Com, "PRINT_BACK")==0){
            if(size[ln]==0){
                continue;
            }

            New2 = a[ln];

            for(i=0 ; i<size[ln]-1 ; i++){
                New2 = New2->next;
            }

            printf("%d\n", New2->value);
        }
        if(strcmp(Com, "INSERT")==0){
            scanf("%d %d", &index, &v);

            if(index > size[ln] || index < 0){
                continue;
            }
            else{
                New = malloc(sizeof(Elmt));
                New2 = a[ln];
                New->value = v;

                if(index==0){
                    New->next = New2;
                    a[ln] = New;
                }
                else{
                    for(i=0 ; i<index-1 ; i++){
                        New2 = New2->next;
                    }

                    New->next = New2->next;
                    New2->next = New;
                }
            }
            size[ln]++;
        }
        if(strcmp(Com, "DELETE")==0){
            scanf("%d", &index);
            New = a[ln];

            if(index >= size[ln] || size[ln]==0 || index < 0){
                continue;
            }
            else{
                if(index==0){
                    a[ln] = a[ln]->next;
                    free(New);
                }
                else{
                    for(i=0 ; i<index-1 ; i++){
                        New = New->next;
                    }

                    New2 = New->next;
                    New->next = New2->next;
                    free(New2);
                }
            }

            size[ln]--;
        }
        if(strcmp(Com, "CONCAT")==0){
            scanf("%s", temp2);

            check = 0;

            for(i=0 ; i<n ; i++){
                if(strcmp(temp2, name[i])==0){
                    ln2 = i;
                    check = 1;
                    break;
                }
            }

            if(check==0 || ln==ln2){
                continue;
            }

            New = a[ln];
            New2 = a[ln2];

            for(i=0 ; i<size[ln]-1 ; i++){
                New = New->next;
            }

            New->next = New2;

            size[ln] = size[ln] + size[ln2];
        }
        if(strcmp(Com, "PRINT_ELEMENT")==0){
            scanf("%d", &index);

            if(index >= size[ln] || size[ln]==0 || index < 0){
                continue;
            }

            New = a[ln];

            if(index>0){
                for(i=0 ; i<index ; i++){
                    New = New->next;
                }
            }

            printf("%d\n", New->value);
        }
        if(strcmp(Com, "PRINT")==0){
            New = a[ln];

            for(i=0 ; i<size[ln] ; i++){
                printf("%d ", New->value);

                New = New->next;
            }

            printf("\n");
        }
        if(strcmp(Com, "PRINT_SIZE")==0){
            printf("%d\n", size[ln]);
        }
        if(strcmp(Com, "POP_FRONT")==0){
            if(size[ln]==0){
                continue;
            }

            printf("%d\n", a[ln]->value);

            New = a[ln];
            a[ln] = a[ln]->next;
            free(New);

            size[ln]--;
        }
        if(strcmp(Com, "POP_BACK")==0){
            if(size[ln]==0){
                continue;
            }

            New = a[ln];

            if(size[ln]==1){
                printf("%d\n", New->value);
                a[ln] = a[ln]->next;
                free(New);
            }
            else{
                for(i=0 ; i<size[ln]-2 ; i++){
                    New = New->next;
                }

                New2 = New->next;

                printf("%d\n", New2->value);

                New->next = New2->next;
                free(New2);
            }

            size[ln]--;
        }
    }

    return 0;
}
