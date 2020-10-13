#include<stdio.h>
#include<math.h>   // ÊýÑ§¿âº¯Êý 
#define PI 3.1415926       
int main()                   
{  
   int a,b;
   char op;
   scanf("%d%c%d",&a,&op,&b);
   switch(op)
   {
   	 case '+': printf("%d%c%d=%d\n",a,op,b,a+b); break;
   	 case '-': printf("%d%c%d=%d\n",a,op,b,a-b); break;
   	 case '*': printf("%d%c%d=%d\n",a,op,b,a*b); break;
   	 case '/': printf("%d%c%d=%d\n",a,op,b,a/b); break;
   	 case '%': printf("%d%c%d=%d\n",a,op,b,a%b); break;
   }
   return 0;           
}                   
