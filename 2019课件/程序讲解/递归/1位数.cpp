#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 
#include<string.h>

int bitsSum(int a);
int bits1(int n);

int main()
{
   int n,sum=0;
   scanf("%d",&n);
   printf("%d\n",bits1(n)); 
   return 0;
} 

// ����a�ĸ�λ����֮��
int bitsSum(int a)
{
   int sum;
   if(a==0) sum=0;  
   else sum=bitsSum(a/10)+a%10;
   return sum;
}
// ȷ�������1λ����
int bits1(int n)
{
   int result;
   result=bitsSum(n);
   if(result>9) result=bits1(result);//�ݹ�
   return result; 
}
