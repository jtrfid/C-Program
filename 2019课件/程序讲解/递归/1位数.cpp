#include<stdio.h>
#include<math.h>   // 数学库函数 
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

// 整数a的各位数字之和
int bitsSum(int a)
{
   int sum;
   if(a==0) sum=0;  
   else sum=bitsSum(a/10)+a%10;
   return sum;
}
// 确保最后是1位数字
int bits1(int n)
{
   int result;
   result=bitsSum(n);
   if(result>9) result=bits1(result);//递归
   return result; 
}
