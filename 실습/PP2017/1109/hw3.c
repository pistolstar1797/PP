#include <stdio.h>
int n, d[400], p[400];

struct cod{
    int x;
    int y;
};

int dis(struct cod p1, struct cod p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int main(){
    struct cod a[400];
    int i, j;

    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        d[i] = 2147483647;
        scanf("%d %d", &a[i].x, &a[i].y);
    }

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
            if(i!=j && d[i] > dis(a[i], a[j])){
                d[i] = dis(a[i], a[j]);
                p[i] = j;
            }
        }
    }
    
    for(i=0 ; i<n ; i++){
        printf("%d\n", p[i]);
    }
    
    return 0;
}
