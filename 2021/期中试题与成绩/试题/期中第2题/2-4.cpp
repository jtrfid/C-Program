#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	int count=0;
	int maxd,mind;
	if(n==0)
	{
		count = 1;
		maxd = mind = 0;
	}
	maxd = mind = n%10;
	while(n>0)
	{
		int d = n%10;
		if(d>maxd)
			maxd = d;
		if(d<mind)
			mind = d;
		count ++;
		n /= 10;
	}
	
	printf("%d %d %d\n",count,maxd,mind);
	return 0;
}
