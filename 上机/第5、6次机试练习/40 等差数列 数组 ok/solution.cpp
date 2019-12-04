# include <stdio.h>
#define N 100

// 选择法从大到小排序 
int sorts(int a[],int n)
{
	int i,j,k,tmp;
	for(i=0;i<n-1;i++)
	{
		k=i; // 未排序中较大者 
		for(j=i+1;j<n;j++)
			if(a[j]>a[k]) k=j;
		if(k!=i)
		{
			tmp=a[i];
			a[i]=a[k];
			a[k]=tmp;
		} 
	}
}

// 排序后的a是否构成等差数列，是返回1，否则返回0
// 若是等差数列, 参数返回公差的绝对值。 
int check(int a[],int n, int *tolerance)
{
	int i;
	*tolerance = a[0]-a[1]; // 大-小，不用求绝对值 
	for(i=1;i<n-1;i++)
	{
		if(a[i]-a[i+1] != *tolerance) return 0;
	} 
	return 1;
}

int main()
{
 	int a[N],n,i,tolerance;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	} 
	// 排序
	sorts(a,n);
	// check
	if(check(a,n, &tolerance)) printf("%d\n",tolerance);
	else printf("no\n");
    return 0;
}
