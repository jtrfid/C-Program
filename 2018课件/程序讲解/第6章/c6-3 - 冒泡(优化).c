#include <stdio.h>
#define MAX 100 
int main()
 {
   int a[MAX] = {4,3,2,1};
   int n = 5; // ʵ�������С 
   int i,j,t,flag; // ��־����flag 
//   printf("input array size:");
//   scanf("%d",&n);   
//   printf("input 10 numbers :\n");
//   for (i=0;i<10;i++)                    
//     scanf("%d",&a[i]);                  
//   printf("\n");
   for(j = 1;j <= n-1;j++) // ����n-1��ѭ����ʵ��n-1�˱Ƚ�
   {
	flag = 0;
	for(i=0;i < n-j;i++)  // ��ÿһ���н���n-j�αȽ�  
	  if (a[i]>a[i+1])    // �����������Ƚ� 
	    {t=a[i];a[i]=a[i+1];a[i+1]=t; flag = 1;}
    printf("��%d������:",j);
    for(t = 0;t < n;t++) printf("%d ",a[t]);  // ��ʱ����t�ĸ��� 
    printf("\n");
    if(!flag) break;
   }   
   printf("\nthe sorted numbers :\n");
   for(i = 0;i < n;i++)
     printf("%d ",a[i]);
   printf("\n");
   return 0;
}

int main1()
 {
   int a[10] = {7,9,3,8,10,1,2,-1,20,21};
   int i,j,t,flag;
//   printf("input 10 numbers :\n");
//   for (i=0;i<10;i++)                    
//     scanf("%d",&a[i]);                  
//   printf("\n");
   for(j=0;j<9;j++)                        // ����9��ѭ����ʵ��9�˱Ƚ�
   {
	flag = 0;
	for(i=0;i<9-j;i++)                     // ��ÿһ���н���9-j�αȽ�  
	  if (a[i]>a[i+1])                     // �����������Ƚ� 
	    {t=a[i];a[i]=a[i+1];a[i+1]=t; flag = 1;}
    printf("��%d������:",j);
    for(t=0;t<10;t++) printf("%d ",a[t]);  
    printf("\n");
    if(!flag) break;
   }   
   printf("\nthe sorted numbers :\n");
   for(i=0;i<10;i++)
     printf("%d ",a[i]);
   printf("\n");
   return 0;
}
