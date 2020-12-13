# include <stdio.h>
#define N 100

// ѡ�񷨴Ӵ�С���� 
int sorts(int a[],int n)
{
	int i,j,k,tmp;
	for(i=0;i<n-1;i++)
	{
		k=i; // δ�����нϴ��� 
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

// ������a�Ƿ񹹳ɵȲ����У��Ƿ���1�����򷵻�0
// ���ǵȲ�����, �������ع���ľ���ֵ�� 
int check(int a[],int n, int *tolerance)
{
	int i;
	*tolerance = a[0]-a[1]; // ��-С�����������ֵ 
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
	// ����
	sorts(a,n);
	// check
	if(check(a,n, &tolerance)) printf("%d\n",tolerance);
	else printf("no\n");
    return 0;
}
