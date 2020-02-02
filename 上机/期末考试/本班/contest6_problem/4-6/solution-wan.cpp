#include <stdio.h>
int main()
{
	int m,n,a[50][50],b[50][50],i,j;
	
	scanf("%d %d",&m,&n);
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=a[i][j];
		}
	}
	for(i=0;i<m;i++)
	{
		int cnt=0;
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
				cnt++;
				int k;
				for(k=0;k<m;k++)
					b[k][j]=0;
			}
		}
		if(cnt)
		{
			int k;
			for(k=0;k<n;k++)
				b[i][k]=0;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}

