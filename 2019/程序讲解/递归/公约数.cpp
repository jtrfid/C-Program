#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 
#include<string.h>

/****************************************
 �����������������Լ���������н�С���Ǹ���������������������Լ����
a,b�����Լ����[��: a=mb+r, m=a/b; r=a%b]
ѭ��, b������������ĸ������r, 
[��: n=b/r; r=nb; a=mb+nb=(m+n)b; ���һ������������b, ������a]
ֱ��r=0, ����ѭ����a(����ѭ����b)�������Լ�� 
*****************************************/
 
int gcd(int a, int b) 
{
   int result; 
   if(b==0) result=a; 
   else result=gcd(b,a%b); // b�Ƿ��ӣ�a%b��Ϊ��ĸ 
   return result;
}

int main()                   
{  
   int a,b,t;
   scanf("%d%d",&a,&b);
   if(a<b) // ȷ�� a > b 
   {
   	  t=a; a=b; b=t;
   }
   printf("%d\n",gcd(a,b));
   return 0;           
}                   
