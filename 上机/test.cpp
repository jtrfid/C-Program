#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 
#define N 3  // ���鳤��     
int main()                   
{  
   //int a[N]={7,8,7,6,5,6,7,8,9,10},i,j,t,flag;
   int a[N]={3,2,1},i,j,t,flag;
for(j=1;j<=N-1;j++) //����N-1��ѭ����ʵ��N-1�˱Ƚ�
{
   flag = 0; // ÿ�����򣬳�ʼ��flag����ʾδ���н���
   for(i=0;i<=N-1-j;i++) //��ÿһ���н���N-j������Ԫ�������Ƚ�
   {
      if(a[i]>a[i+1]) //�����������Ƚ�, ע�������鲻ҪԽ�� 
       { t=a[i]; a[i]=a[i+1]; a[i+1]=t; flag=1; } // ����, ���ñ�־����
   }
   printf("\n ��%d������: \n", j); 
   for(t=0;t<N;t++) printf("%d ",a[t]); // ��ʱ����t�ĸ���
   if(!flag) break; // ��ʾ��j��δ�������������!
}
printf("\n the sorted numbers :\n");
for(i=0;i<N;i++) printf("%d ",a[i]);
   return 0;           
}                   
