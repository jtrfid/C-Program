#include<stdio.h>
#include<math.h>   // ÊýÑ§¿âº¯Êý 
#define PI 3.1415926       
int main()                   
{  
   int a,b=10000,i=5;
   scanf("%d",&a);
   while(i>=1)
   {
   	if (i==1)printf("%d\n",a/b);
   	else printf("%d ",a/b);
	a = a-a/b*b;
   	b/=10;
   	i--;
   } 
   return 0;           
}                   
