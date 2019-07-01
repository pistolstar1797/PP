#include <stdio.h>

int main(){
	int n, max1, max2, max3;
	
	max1 = -1;
	max2 = -1;
	max3 = -1;

	while(scanf("%d", &n)!=EOF){
		if(n > max1){
			max3 = max2;
			max2 = max1;
			max1 = n;
		}
		else if(n > max2 && n < max1){
			max3 = max2;
			max2 = n;
		}
		else if(n > max3 && n < max2){
			max3 = n;
		}
	}
	
	printf("%d\n", max3);

	return 0;
}
