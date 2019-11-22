#include <stdio.h>
#define N 100

int main()
{
 	int a[N][N],m,n,i,j,start,end,tmpStart,maxLen,tmpLen;
 	scanf("%d%d",&m,&n);
 	for(i=0;i<m;i++)
 		for(j=0;j<n;j++)
 			scanf("%d",&a[i][j]);
 	for(i=0;i<m;i++)
 	{
 		start=-1; end=-1; maxLen=0;
 		tmpStart=-1; tmpLen=0;
		for(j=0;j<n;j++)
 		{
 			if(a[i][j]==1) // 1开始 
 			{
 				if (tmpStart==-1) tmpStart=j; // 开始 
				tmpLen++;
			}
			else // 遇0结算 
			{
				if(tmpStart!=-1 && tmpLen>maxLen) 
				{
					start=tmpStart;
					end=j-1;
					maxLen=tmpLen;
					tmpStart=-1;
					tmpLen=0;
				}
			}
		}
		if(tmpStart!=-1 && tmpLen>maxLen) // 末尾是1的情况 
		{
			start=tmpStart;
			end=n-1;
		}
		printf("%d %d\n",start,end);
	}
    return 0;
}
