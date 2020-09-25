#include <stdio.h>
int main()
{
	int m,k,cnt[3]={0},n;
	
	scanf("%d %d",&m,&k);
	for(n=1;n<=k;n++)
	{
		int fn;
		if(n==1)
			fn=2;
		else if(n==2)
			fn=3;
		else
			fn=(n-1)*(n-1)+3*(n-2)+1;
		if(fn%m==0)
			cnt[0]++;
		else if(fn%m==1)
			cnt[1]++;
		else
			cnt[2]++;
	}
	printf("%d %d %d",cnt[0],cnt[1],cnt[2]);
	
	return 0;
}

