#include <stdio.h>

int main(){
	int n, max;
	
	max = -1;

	while(scanf("%d", &n)!=EOF){
		if(n > max){
			max = n;
		}
	}

	printf("%d\n", max);

	return 0;
}
