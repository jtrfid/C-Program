#include<stdio.h>
#include<math.h>   // 数学库函数 
#include<string.h>

int f(int n) 
{
int sum;
if(n==0||n==1) sum=n;
else sum=n+f(n-1); // 未完成的计算用"栈"存储起来(push)
return sum; // 函数return前，从"栈"顶取数据,计算,直到"栈"空
}

int main()                   
{  
   printf("%d\n",f(2));
   printf("%d\n",f(3));
   printf("%d\n",f(4));
   printf("%d\n",f(5));
   return 0;           
}                   
