#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 100
int main ()
{
	int a[N],i,n,k,t,sum;
    scanf("%d",&n);
    if(n>0&&n<1000000000)
    {
    for(i=0;i<=9;i++)
    {
    	a[i]=n%10;
    	n=n/10;
    	if(n!=0)
    	sum++;
	}
	for(k=0;k<=9;k++)
		for(i=0;i<=9-k;i++)
		if (a[i]<a[i+1])
		{
			t=a[i];a[i]=a[i+1];a[i+1]=t;
		 } 
	for(i=0;i<=sum;i++)
		 printf("%d ",a[i]); 
	}
	return 0;
}
