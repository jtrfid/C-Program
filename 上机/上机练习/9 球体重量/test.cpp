#include<stdio.h>
#include<math.h>   // ÊýÑ§¿âº¯Êý 
#define PI 3.1415926       
int main()                   
{  
   int a,b;
   scanf("%d%d",&a,&b);
   float v1= 4.0/3.0*pow(a/2.0/10,3)*PI;
   float v2= 4.0/3.0*pow(b/2.0/10,3)*PI;
   printf("%.3f %.3f\n",7.86*v1,19.3*v2); 
   return 0;           
}                   
