#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 
#include<string.h>

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
