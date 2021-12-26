#include<stdio.h>
int main()
{
	int n;
	int a[101];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	  scanf("%d",&a[i]);	
	} 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j+1]>a[j])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0) printf("%d ",a[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0) printf("%d ",a[i]);
	}
	return 0;
	
}
