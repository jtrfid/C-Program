/*#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	
	int i,j,count=0;
	int h,l;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		l = x%10;
		int f = 1;
		for(j=0;j<m-1;j++)
			f *= 10;
		h = x/f;	
		if(m == h+l)
		{
			int sum = 0;
			int temp = x;
			while(temp>0)
			{
				sum += temp%10;
				temp /= 10;
			}
			if(sum%3 == 0)
			{
				count ++;
				printf("%d ",x);
			}
		}
	}
	
	if(count == 0)
		printf("%d\n",-1);
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	
	int i,j,count=0;
	int h,l;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		l = x%10;
		int f = 1;
		for(j=0;j<m-1;j++)
			f *= 10;
		h = x/f;	
		if(m == h+l && x%3==0)
		{
				count ++;
				printf("%d ",x);
			
		}
	}
	
	if(count == 0)
		printf("%d\n",-1);
	return 0;
}
