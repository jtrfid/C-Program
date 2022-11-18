#include<stdio.h>
int main()
{
	int n;
	int a[201];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	  scanf("%d",&a[i]);	
	} 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				
			}
		}
	}
	int x=a[1]-a[0];
	for(int i=2;i<n;i++)
	{
	  if((a[i]-a[i-1])!=x)
	  {
	  	
	  	printf("no");
	  	return 0;
	  }
	}
    printf("%d",x);
	return 0;
	
}
