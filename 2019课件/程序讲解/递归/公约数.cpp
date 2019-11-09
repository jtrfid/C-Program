#include<stdio.h>
#include<math.h>   // 数学库函数 
#include<string.h>

/****************************************
 定理：两个整数的最大公约数等于其中较小的那个数和两数相除余数的最大公约数。
a,b的最大公约数，[则: a=mb+r, m=a/b; r=a%b]
循环, b作被除数，分母是余数r, 
[则: n=b/r; r=nb; a=mb+nb=(m+n)b; 如果一个整数能整除b, 必整除a]
直到r=0, 本轮循环的a(上轮循环的b)就是最大公约数 
*****************************************/
 
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
