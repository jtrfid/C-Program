#include <stdio.h>
int main()
{
	int n,i,a[100]={0},min=65536;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		int j;
		for(j=i+1;j<n;j++)
		{
			int d=a[i]-a[j];
			if(d<0)
				d*=-1;
			if(d<min)
				min=d;
		}	
	}
	printf("%d",min);
	 
	return 0;
}

