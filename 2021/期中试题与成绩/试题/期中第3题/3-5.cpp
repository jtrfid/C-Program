#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	long long int fn,sn;
	
	scanf("%d",&n);
	if(n<=0 || n>=16)
	{
		printf("%d\n",-1);
		exit(-1);
	}
	int i,j;
	sn = 0;
	for(i=1;i<=n;i++)
	{
		fn = 1;
		for(j=0;j<i;j++)
			fn *= i;
		sn += fn;
	}
	
	printf("%lld\n",sn);
	return 0;
}
