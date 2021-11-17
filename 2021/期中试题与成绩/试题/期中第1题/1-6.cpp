#include<stdio.h>

int main()
{
	int m, n, sum=10000;
	scanf("%d%d", &m, &n);
	
	if (m <= 1 || n <= 1){
		printf("error");
		return 0;
	}
	
	while(sum >= n){
		sum /= m;
	}
	
	printf("%d", sum);	
}

