/***********************************************************
	������	42
	��������	���ַֽ�����
	ʱ������:	2 ��
	�ڴ�����:	10000MB
	��������	
	��������
	����һ��9λ���ڵ�������n������ֵ�Ӹߵ��͵�˳�����n�ĸ�λ���֡�
	����˵��
	һ��������n(0<n<1000000000) 
	���˵��
	����ֵ�Ӹߵ��͵�˳�����n�ĸ�λ���֣�����֮���ÿո����
	��������
	564391 
	�������
	9 6 5 4 3 1 
	��ʾ��Ϣ
 ***********************************************************/
#include <stdio.h>

int main1()
{
	int i = 0,j,k,n,num[9],t;
	scanf("%d",&n);
	if(n <= 0 || n > 1000000000) return 0;
	while(n)
	{
		num[i++] = n%10;
		n /= 10;
	}
	k = i--; // k: ���ָ��� 
	
	// �����֤ 
	for(j = 0; j < k; j++) printf("%d ",num[j]);
	printf("\n");
	 
	// ð������
	for(j = 1; j <= k-1; j++) 
		for(i = 0; i < k - j; i++)
			if (num[i] < num[i+1]) 
			{ t = num[i]; num[i] = num[i+1]; num[i+1] = t; }
			
	// ���
	for(j = 0; j < k; j++) printf("%d ",num[j]);
	printf("\n");
	return 0;
} 

int main2()
{
	int i = 0,j,k,n,num[9],t;
	scanf("%d",&n);
	if(n <= 0 || n > 1000000000) return 0;
	while(n)
	{
		num[i++] = n%10;
		n /= 10;
	}
	k = i--; // k: ���ָ��� 
	 
	// ð������
	for(j = 1; j <= k-1; j++) 
		for(i = 0; i < k - j; i++)
			if (num[i] < num[i+1]) 
			{ t = num[i]; num[i] = num[i+1]; num[i+1] = t; }
			
	// ���
	for(j = 0; j < k; j++) printf("%d ",num[j]);
	printf("\n");
	return 0;
} 

int main()
{
	void order(int a[],int n);  // ������˵��
	
	int i = 0,j,k,n,num[9];
	scanf("%d",&n);
	if(n <= 0 || n > 1000000000) return 0;
	while(n)
	{
		num[i++] = n%10;
		n /= 10;
	}
	k = i--; // k: ���ָ��� 
	
	// �����֤ 
	for(j = 0; j < k; j++) printf("%d ",num[j]);
	printf("\n");
	 
    order(num,k);  // ������˵�� 
			
	// ���
	for(j = 0; j < k; j++) printf("%d ",num[j]);
	printf("\n");
	return 0;
} 

// ������ 
void order(int a[],int n)
{ 
	int i,j,t;
	// ð������
	for(j = 1; j <= n-1; j++) 
		for(i = 0; i < n - j; i++)
			if (a[i] < a[i+1]) 
			{ t = a[i]; a[i] = a[i+1]; a[i+1] = t; }
}
