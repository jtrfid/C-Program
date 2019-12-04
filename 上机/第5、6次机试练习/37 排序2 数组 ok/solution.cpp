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

int main()
{
 	int even[N],odd[N],n,i,num;
 	int evenN=0, oddN=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		if(num%2==0) // even
		{
			even[evenN]=num;
			evenN++;
		}
		else
		{
			odd[oddN]=num;
			oddN++;
		}
	} 
	// 排序
	sorts(even,evenN);
	sorts(odd,oddN);
	// 输出 
	for(i=0;i<evenN;i++) printf("%d ",even[i]); 
	for(i=0;i<oddN;i++) printf("%d ",odd[i]); 
	printf("\n"); 
    return 0;
}
