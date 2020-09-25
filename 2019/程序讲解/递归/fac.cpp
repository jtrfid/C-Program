#include<stdio.h>
#include<math.h>   // ÊýÑ§¿âº¯Êý 
#include<string.h>

double fac(int n)
{
   if(n==0 || n==1) return 1;
   else return n*fac(n-1);
}

int main()                   
{  
   printf("%.0lf\n",fac(2));
   printf("%.0lf\n",fac(3));
   printf("%.0lf\n",fac(4));
   printf("%.0lf\n",fac(20));
   return 0;           
}                   
