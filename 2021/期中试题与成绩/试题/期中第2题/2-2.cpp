#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int count = 0;
	if(a>b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if(a<2)
		a = 2;
	for(int i=a;i<=b;i++)
	{
		int j;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
				break;
		}
		if(j==i)
			count ++;
	}
	
	printf("%d\n",count);
	return 0;
} 
