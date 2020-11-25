#include<stdio.h>
int isPrime(int n)
{
	int i;
	for(i=2;i<n/2;i++)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}
int main1()
{
	int big_even;
	scanf("%d",&big_even);
	
	int a,b;
	for(a=2;a<big_even;a++)
	{
		if(isPrime(a))
		{
			b = big_even-a;
			if(isPrime(b) && b<=a) // 无后者，a,b将不是最接近的两个素数，如10=3+7，10=5+5 
			//if(isPrime(b))
			{
				printf("%d %d\n",b,a);
				break;
			} 
		}
	}
	return 0;
}

