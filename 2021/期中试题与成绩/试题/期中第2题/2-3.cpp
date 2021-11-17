#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	int gcd;
	if(a>b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	
	if(a==0)
		gcd = b;
	else
	{
		for(int i=a;i>=1;i--)
		{
			if(a%i==0 && b%i==0)
			{
				gcd = i;
				break;
			}
		}
	}
	
	printf("%d\n",gcd);
	return 0;
}
