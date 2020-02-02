#include <stdio.h>
int a(int i);

int main()
{
	int sum_0=0,sum_1=0,sum_other=0;
	int m,k;
	int i;
	scanf("%d%d",&m,&k);
	for(i=1;i<=k;i++)
	{
		int an=a(i);
		if(an%m==0)
			sum_0++;
		else if(an%m==1)
			sum_1++;
		else
			sum_other++;
	}
	printf("%d %d %d",sum_0,sum_1,sum_other);
	return 0;
}

int a(int i)
{
	if(i==1)
		return 2;
	else if(i==2)
		return 3;
	else
		return (i-1)*(i-1)+3*(i-2)+1;
}
