 #include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n<=1 || n>100000)
	{
		printf("%d\n",0);
		exit(-1);
	}
	
	int i,sum = 0;
	for(i=2;i<=n;i++)
	{
		int j;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
				break;
		}
		if(i == j)
			sum += i;
	}
	
	printf("%d\n",sum);
	return 0;
}
