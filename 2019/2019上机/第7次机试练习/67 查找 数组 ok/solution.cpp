# include <stdio.h>
#define N 100

int main()
{
 	int a[N],n,i,k,flag=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(k==a[i]) 
		{
			printf("%d ",i);
			flag=1;
		}
	} 
	if(flag) printf("\n");
	else printf("-1\n");
    return 0;
}
