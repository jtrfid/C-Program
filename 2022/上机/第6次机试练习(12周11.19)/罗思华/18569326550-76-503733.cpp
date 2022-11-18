#include<stdio.h>
int m[200000];
int main()
{
	int n;
	int max=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);

		m[x]++;
	}
	for(int i=0;i<100800;i++)
	{
		if(m[i]!=0)
		printf("%d:%d\n",i,m[i]);
	}
	return 0;
}
