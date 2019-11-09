#include<stdio.h>
#include<math.h>   // 数学库函数 
#include<string.h>

#define N 1000

int n1=0; // 记录递归次数

// 一般递归：从n开始到0或1结束, 自上而下计算, 即top-down递归 
double F(int n) // Fn较大，因此函数返回类型设置为double
{
   n1++; // 递归次数 
   if(n==0 || n==1) return 1;
   else return F(n-1)+F(n-2);
}

int main()                   
{  
   int i,n;
   double lookup[N];
   n=20;
   printf("top-down\n");
   for(i=0;i<n;i++)
   {
   	   printf("%d(%d)\t",(int)F(i),n1); // printf("%.0f\t",F(i)); 不会损失精度 
       if((i+1)%4==0) printf("\n");	
   } 
   return 0;           
} 
                     
