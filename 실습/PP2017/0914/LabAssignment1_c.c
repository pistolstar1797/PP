#include <stdio.h>

int main(){
	int n, sum, cnt;
	float avg;

	cnt = 0;
	
	while(scanf("%d", &n)!=EOF){
		sum = sum + n;
		cnt++;
	}

	avg = (float)sum/cnt;

	printf("%f\n", avg);

	return 0;
}
