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
#include <math.h>

void order(int a[],int n);  // ������˵��

int main()
{
	printf("%d,%d\n",(int)pow(5,3),(int)(pow(5,3)+0.5)); // 125,125
	int i = 0,j,k,n,n1,num[9],num1[9];
	scanf("%d",&n);
	k=0; // ���ָ���
	n1=n; 
	while(n)
	{
		num1[i++] = n%10;
		n /= 10;
		k++;
	} 
	
	for(j=0;j<k;j++)
	  num[j]=n1/((int)pow(10,j))%10;  // ��֤pow�������ύ���ܳ�ʱ���õ����󣬱����Ǻõġ� 
	   
	// �����֤ 
	//for(j = 0; j < k; j++) printf("%d,%d ",num[j],num1[j]);
	//printf("aaaaaaaa\n");
	 
    order(num,k);  // ������
			
	// ���
	for(j = 0; j < k; j++) printf("%d ",num[j]);
	printf("\n");
	return 0;
} 

// ������ 
void order1(int a[],int n)
{ 
	int i,j,t,flag;
	// ð������
	for(j = 1; j <= n-1; j++)
	{ 
		flag=0;
		for(i = 0; i < n - j; i++)
			if (a[i] < a[i+1]) 
			{ 
			  t = a[i]; a[i] = a[i+1]; a[i+1] = t; 
			  flag=1;
			}
	    if(!flag) break;
   }
}

// ������ 
void order(int a[],int n)
{ 
	int i,j,t,flag;
	// ð������
	for(j = 0; j < n-1; j++)
	{ 
		flag=0;
		for(i = 0; i < n - j-1; i++)
			if (a[i] < a[i+1]) 
			{ 
			  t = a[i]; a[i] = a[i+1]; a[i+1] = t; 
			  flag=1;
			}
	    if(!flag) break;
   }
}
