#include <stdio.h>

int main(){
	float n;

	scanf("%f", &n);

	if(n-(int)n < 0.5){
		printf("%d\n", (int)n);
	}
	else{
		printf("%d\n", (int)n+1);
	}

	return 0;
}
