#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 
#include<string.h>

double F(int n) // Fn�ϴ���˺���������������Ϊdouble
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
