#include<stdio.h>

int main()
{
	int m, n, sum = 0, i=0;
	
	scanf("%d", &n);
	
	m = 0;
	sum += m;
	while(++i <= n) {
		m = 2*m+1;
		sum += m;
	}
	
	printf("%d", sum);
}

