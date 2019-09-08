#include <stdio.h>
#define MAX 100 
int main()
 {
   int a[MAX] = {4,3,2,1};
   int n = 5; // 实际数组大小 
   int i,j,t,flag; // 标志变量flag 
//   printf("input array size:");
//   scanf("%d",&n);   
//   printf("input 10 numbers :\n");
//   for (i=0;i<10;i++)                    
//     scanf("%d",&a[i]);                  
//   printf("\n");
   for(j = 1;j <= n-1;j++) // 进行n-1次循环，实现n-1趟比较
   {
	flag = 0;
	for(i=0;i < n-j;i++)  // 在每一趟中进行n-j次比较  
	  if (a[i]>a[i+1])    // 相邻两个数比较 
	    {t=a[i];a[i]=a[i+1];a[i+1]=t; flag = 1;}
    printf("第%d趟排序:",j);
    for(t = 0;t < n;t++) printf("%d ",a[t]);  // 临时变量t的复用 
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
   for(j=0;j<9;j++)                        // 进行9次循环，实现9趟比较
   {
	flag = 0;
	for(i=0;i<9-j;i++)                     // 在每一趟中进行9-j次比较  
	  if (a[i]>a[i+1])                     // 相邻两个数比较 
	    {t=a[i];a[i]=a[i+1];a[i+1]=t; flag = 1;}
    printf("第%d趟排序:",j);
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
