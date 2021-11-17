#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	long long int sum = 0;
	int i,j;
	
	if(n<=0)
	{
		printf("%d\n",-1);
		exit(-1);
	}
	
	for(i=1;i<=n;i++)
	{
		long long int f = 1;
		for(j=1;j<=i;j++)
		{
			f *= j;
		}
		sum += f;
	}
	
	if(sum>1e15)
		printf("%d\n",-1);
	else
		printf("%lld\n",sum);
	return 0;
} 
