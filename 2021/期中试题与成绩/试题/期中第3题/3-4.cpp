#include<stdio.h>
int main()
{
	int n,x,max,min;
	int maxs,mins;
	
	scanf("%d",&n);
	int i;
	scanf("%d",&x);
	max = min = x;
	for(i=1;i<n;i++)
	{
		scanf("%d",&x);
		if(x>max)
			max = x;
		if(x<min)
			min = x;
	}
	
	maxs = mins = 0;
	while(max>0)
	{
		maxs += max%10;
		max /= 10;
	}
	while(min>0)
	{
		mins += min%10;
		min /= 10;
	}
	
	printf("%d %d\n",maxs,mins);
	return 0;
}
