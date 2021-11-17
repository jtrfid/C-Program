#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m,n, sum=1;
	scanf("%d%d", &m, &n);
	
	while(sum <= n)
		sum *= m;
	
	printf("%d", sum);
}

