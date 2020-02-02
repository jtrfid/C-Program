#include <stdio.h>
int main()
{
	int y,d,leap=0;
	scanf("%d %d",&y,&d);
	if(y<1900||y>2100||d>29)
	{
		printf("-1");
		return 0;
	}
	leap=(y%400==0||(y%4==0&y%100!=0));
	if(!leap&&d>28)
	{
		printf("-1");
		return 0;
	}
	
	printf("%d",d%7);
	
	return 0;
}

