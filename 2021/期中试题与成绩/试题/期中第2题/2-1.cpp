#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	
	int flag = 0;
	if(n==0)
	{
		m = 0;
		flag = 1;
	}		
	else if(n==1)
	{
		m = 1;
		flag = 1;
	}
	else
	{
		for(m=2;m<=n/2;m++)
		{
			if(m*m==n)
			{
				flag = 1;
				break;
			}
		}
	}	
	
	if(flag)
		printf("%d\n",m);
	else
		printf("no\n");
	return 0;
}
