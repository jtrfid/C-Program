#include<stdio.h>
#include<math.h>   // 数学库函数 
#define N 3  // 数组长度     
int main()                   
{  
   //int a[N]={7,8,7,6,5,6,7,8,9,10},i,j,t,flag;
   int a[N]={3,2,1},i,j,t,flag;
for(j=1;j<=N-1;j++) //进行N-1次循环，实现N-1趟比较
{
   flag = 0; // 每趟排序，初始化flag，表示未进行交换
   for(i=0;i<=N-1-j;i++) //在每一趟中进行N-j次相邻元素两两比较
   {
      if(a[i]>a[i+1]) //相邻两个数比较, 注意检查数组不要越界 
       { t=a[i]; a[i]=a[i+1]; a[i+1]=t; flag=1; } // 交换, 设置标志变量
   }
   printf("\n 第%d趟排序: \n", j); 
   for(t=0;t<N;t++) printf("%d ",a[t]); // 临时变量t的复用
   if(!flag) break; // 表示第j趟未交换，排序好了!
}
printf("\n the sorted numbers :\n");
for(i=0;i<N;i++) printf("%d ",a[i]);
   return 0;           
}                   
