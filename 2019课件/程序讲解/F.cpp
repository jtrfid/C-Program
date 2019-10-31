#include<stdio.h>
#include<math.h>   // 数学库函数 
#include<string.h>

double F(int n) // Fn较大，因此函数返回类型设置为double
{
   if(n==0 || n==1) return 1;
   else return F(n-1)+F(n-2);
}

int main()                   
{  
   int i;
   for(i=0;i<20;i++)
   {
   	   printf("%d\t",(int)F(i));
       if((i+1)%4==0) printf("\n");	
   } 
   return 0;           
}                   
