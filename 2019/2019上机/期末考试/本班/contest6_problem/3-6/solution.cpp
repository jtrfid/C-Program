#include <stdio.h>

int main()
{
	int n,i,j,cnt=1,tmp;	
	int min;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++) 
		scanf("%d",&arr[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
			if(arr[j]>arr[j+1])
			{
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
	}
	for(i=n-1;i>0;i--)
		arr[i]=arr[i]-arr[i-1];
	
	min=arr[1];
	for(i=1;i<n;i++)
		if(min>arr[i])
			min=arr[i];
	printf("%d\n",min);
	
	return 0;
}
