#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 
#include<string.h>

int f(int n) 
{
int sum;
if(n==0||n==1) sum=n;
else sum=n+f(n-1); // δ��ɵļ�����"ջ"�洢����(push)
return sum; // ����returnǰ����"ջ"��ȡ����,����,ֱ��"ջ"��
}

int main()                   
{  
   printf("%d\n",f(2));
   printf("%d\n",f(3));
   printf("%d\n",f(4));
   printf("%d\n",f(5));
   return 0;           
}                   
