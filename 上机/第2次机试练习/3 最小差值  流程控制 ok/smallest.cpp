#include <stdio.h>
#include <math.h>
#define N 10000
int main()
{
	int i,j,n,num[N],smallest,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	smallest=(int)fabs(num[0]-num[1]);// abs()在低版本编译器中有问题 
	for(i=0;i<=n-2;i++) 
	{
		for(j=i+1;j<n;j++)
		{
			temp=(int)fabs(num[i]-num[j]);
			if(smallest>temp) smallest=temp;
		}
	}
	printf("%d\n",smallest);
	return 0;
} 
