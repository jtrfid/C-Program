#include<stdio.h>
#include<math.h>   // ��ѧ�⺯��        
int main()                   
{  
   int n=0; //���� 
   int a,b; // a,b ����
   int i,t;   // ѭ������������a,b�����ÿ����
   int sum; // i�ĸ�λ������ 
   scanf("%d%d",&a,&b);
   for(i=a;i<=b;i++) 
   { 
	  // ����i�Ƿ�ˮ���� 
	  sum = 0; t=i;
	  while(t!=0) // �ۼӸ�λ���� 
	  {
	  	sum+=pow(t%10,3);
	  	t=t/10;
      }
      if(sum==i) n++; // i��ˮ���� 
   }
   printf("%d\n",n);
   return 0;           
}                   
