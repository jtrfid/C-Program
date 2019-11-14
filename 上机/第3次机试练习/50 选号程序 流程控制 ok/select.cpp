
#include <stdio.h>
#include <math.h>

#define N 100
int main()
{
	int i,n,No[N][2],tmp,sum,max=0,largest=0,select;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&No[i][0]);
		tmp=No[i][0];
		sum=0;  // 一定初始化 
		while(tmp)
		{
			sum+=tmp%10;
			tmp/=10;
		}
		No[i][1]=sum;
		if(sum>=max) max=sum; 
	}
	for(i=0;i<n;i++)
	{
		if(No[i][1]==max) // 备选号码
		{
		   if(No[i][0]>=largest)
		   {
		   	  select=No[i][0];
		   	  largest=No[i][0];
		   }
		} 
	}
	printf("%d",select);
	return 0;
} 
