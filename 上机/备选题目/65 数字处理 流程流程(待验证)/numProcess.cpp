/*****************************************************************
��дһ�����򣬴Ӽ�������һ����������n��0 < n <= 1000000000����������n�������´���
�������ĸ�λ����ȡ������ӣ���������һλ������������������ظ��������̣�ֱ���õ��Ľ��Ϊһλ����������ý����
���磺n=456���任��������
4+5+6=15
1+5=6
������Ϊ6

����˵��	
һ����������n��

���˵��	
�������n�Ĵ�������

��������	
456

�������	
6
**********************************************************************/
#include <stdio.h>
#include <math.h>

int bitsSum1(int a)
{
  int sum=0;
  while(a)
  {
    sum += a%10;
    a /= 10;
  }
  return sum;
}

int main1()
{
	int n,sum=0;
	scanf("%d",&n);
	while(1)
	{
		sum=bitsSum1(n);
		if(sum<=9) break;
		else n=sum; // ������һ�ֵ��� 
	}
	printf("%d\n",sum); 
	return 0;
}

///////////�ݹ�ʵ��
int bitsSum(int a)
{
  int sum;
  if(a==0) sum=0;  
  else sum= bitsSum(a/10)+a%10;
  return sum;
}

int bits1(int n)
{
	int result;
	result=bitsSum(n);
	if(result<=9) return result; // 1λ�����򷵻� 
	else result=bits1(result);   // ����, �ݹ� 
}

int main()
{
	int n,sum=0;
	scanf("%d",&n);
	printf("%d\n",bits1(n)); 
	return 0;
} 
