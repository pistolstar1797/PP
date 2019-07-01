#include <stdio.h>

int main(){
	int a, b;

	scanf("%d, %d", &a, &b);

	if(a>=0 && b>0){
		printf("%d = %d * %d + %d\n", a, a/b, b, a%b);
		printf("%d / %d = %.4f\n", a, b, (float)a/b);
	}
	else if(a>=0 && b<0){
		printf("%d = (%d) * (%d) + %d\n", a, a/b, b, a%b);
		printf("%d / (%d) = %.4f\n", a, b, (float)a/b);
	}
	else if(a<0 && b>0){
		printf("%d = (%d) * %d + %d\n", a, (a/b)-1, b, (a%b)+b);
		printf("%d / %d = %.4f\n", a, b, (float)a/b);
	}
	else{
		printf("%d = %d * (%d) + %d\n", a, (a/b)+1, b, (a%b)-b);
		printf("%d / (%d) = %.4f\n", a, b, (float)a/b);
	}

	return 0;
}
