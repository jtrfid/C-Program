#include<stdio.h>
int main()
{
	int count1,count2,count3;
	count1=count2=count3=0;
	int n;//报数到n停止游戏 
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		if(i%7 == 0)
		{
			if(i%3 == 1)
				count1 ++;
			if(i%3 == 2)
				count2 ++;
			if(i%3 == 0)
				count3 ++;
			continue;
		} 	
		int temp = i;
		while(temp>0)
		{
			if(temp%10 == 7)
			{
				if(i%3 == 1)
					count1 ++;
				if(i%3 == 2)
					count2 ++;
				if(i%3 == 0)
					count3 ++;
				break;
			}
			temp /= 10;
		}
	}
	
	printf("%d %d %d\n",count1,count2,count3);
	return 0;
}
