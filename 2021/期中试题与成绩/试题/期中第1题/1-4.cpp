#include<stdio.h>

int main()
{
	int m, n, sum = 0, i=0;
	
	scanf("%d%d", &m, &n);
	
	while(++i <= n) 
		sum += (i+m)*(i+m);
	
	printf("%d", sum);
}

