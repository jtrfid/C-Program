#include<stdio.h>
#include<math.h>   // 数学库函数 
#include<string.h>

int gcd(int a, int b) 
{
   int result; 
   if(b==0) result=a; 
   else result=gcd(b,a%b); // b是分子，a%b成为分母 
   return result;
}

int main()                   
{  
   int a,b,t;
   scanf("%d%d",&a,&b);
   if(a<b) // 确保 a > b 
   {
   	  t=a; a=b; b=t;
   }
   printf("%d\n",gcd(a,b));
   return 0;           
}                   
