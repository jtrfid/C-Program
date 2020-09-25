#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 100
int main ()
{
	int a[N],i,n,k,t,x,sum=0;
    scanf("%d",&n);
    x=n;
    while(x>1)
    {
	x=x/10;
    sum++;
	}
    for(i=0;i<sum;i++)
    {
    	a[i]=n%10;
    	n=n/10;
	}
	for(k=0;k<sum;k++)
		//for(i=0;i<sum-k;i++) // k=0时，当i=sum-1, a[i+1]越界 
		for(i=0;i<sum-k-1;i++)
		if (a[i]<a[i+1])
		{
			t=a[i];a[i]=a[i+1];a[i+1]=t;
		 } 
	for(i=0;i<sum;i++)
		 printf("%d ",a[i]); 
	return 0;
}
