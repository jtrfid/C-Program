#include<stdio.h>
#include<math.h>   // 数学库函数 
#define PI 3.1415926       
int main()                   
{  
   int a,b;
   scanf("%d%d",&a,&b);
   // 不要随意化简公式，有精度问题 
   float v1= 4.0/3.0*pow(a/2.0/10,3)*PI;
   float v2= 4.0/3.0*pow(b/2.0/10,3)*PI;
   printf("%.3f %.3f\n",7.86*v1,19.3*v2); 
   return 0;           
}                   
