#include <stdio.h>
int n, a[20][20], b[20][20], c[20][20];

int main(){
    int i, j, k, x, y;

    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
            scanf("%d", &b[i][j]);
        }
    }

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
            for(k=0 ; k<n ; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
