#include <stdio.h>

int main(){
	int n, max1, max2;
	
	max1 = -1;
	max2 = -1;

	while(scanf("%d", &n)!=EOF){
		if(n > max1){
			max2 = max1;
			max1 = n;
		}
		else if(n > max2 && n < max1){
			max2 = n;
		}
	}
	
	printf("%d\n", max2);

	return 0;
}
