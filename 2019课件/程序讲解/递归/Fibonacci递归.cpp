#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 
#include<string.h>

#define N 1000

int n1=0; // ��¼�ݹ����

// һ��ݹ飺��n��ʼ��0��1����, ���϶��¼���, ��top-down�ݹ� 
double F(int n) // Fn�ϴ���˺���������������Ϊdouble
{
   n1++; // �ݹ���� 
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
   	   printf("%d(%d)\t",(int)F(i),n1); // printf("%.0f\t",F(i)); ������ʧ���� 
       if((i+1)%4==0) printf("\n");	
   } 
   return 0;           
} 
                     
