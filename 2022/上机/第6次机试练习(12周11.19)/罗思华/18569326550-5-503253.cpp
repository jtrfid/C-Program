#include<stdio.h>
int main()
{
	int n,m;
	int data[40][40];
	int map[40][40];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&data[i][j]);
		
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
				if(j>=2)
			{
				if(data[i][j]==data[i][j-1]&&data[i][j]==data[i][j-2])
				{
					int x=data[i][j];
					for(int k=j-2;;k++)
					{
						if(data[i][k]==x)
						{
							j=k+1;
							map[i][k]=-1;
						}
						else break;
					}
				}
			}
		}
	}
		for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
				if(i>=2)
			{
				if(data[i][j]==data[i-1][j]&&data[i][j]==data[i-2][j])
				{
					int x=data[i][j];
					for(int k=i-2;;k++)
					{
						if(data[k][j]==x)
						{
							i=k+1;
							map[k][j]=-1;
						}
						else break;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==-1) data[i][j]=0;
			printf("%d ",data[i][j]);
		}
		printf("\n"); 
	}
	return 0;
	
}
