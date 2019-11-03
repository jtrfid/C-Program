/***********************************************************
	题目6：数字排序
问题描述
　　给定n个整数，请计算每个整数各位数字和，按各位数字和从大到小的顺序输出。
输入格式
　　输入的第一行包含一个整数n，表示给定数字的个数。
　　第二行包含n个整数，相邻的整数之间用一个空格分隔，表示所给定的整数。
输出格式
　　输出多行，每行包含两个整数，分别表示一个给定的整数和它的各位数字和。按各位数字和递减的顺序输出。如果两个整数各位数字和相同，则先输出值较小的，然后输出值较大的。
样例输入
5
101 100 999 1234 110
样例输出
999 27
1234 10
101 2
110 2
100 1
评测用例规模与约定
　　1 ≤ n ≤ 1000，给出的数都是不超过10000的非负整数。
 ***********************************************************/
#include <stdio.h>
#define N 1000
int main()
{
	int i,j,n; // 是实际个数 
	int num[N][2]; // 第0列是整数，第1列是其各位数字的和  
	int temp,flag;
	scanf("%d",&n);
	for(i=0;i<n;i++) 
	{
	   scanf("%d",&num[i][0]); // 第0列 
	   // 计算第1列 
	   num[i][1]=0;
	   temp=num[i][0];
	   while(temp)
		{
			num[i][1] += temp%10;
			temp /= 10;
		}
	} 
	
	// 冒泡排序
	for(j = 1; j <= n-1; j++) 
	{
		flag=0;
		for(i = 0; i < n - j; i++)
		{
			if (num[i][1] < num[i+1][1]) 
			{ 
				temp = num[i][0]; num[i][0] = num[i+1][0]; num[i+1][0] = temp; 
				temp = num[i][1]; num[i][1] = num[i+1][1]; num[i+1][1] = temp; 
				flag=1;
			}
	    }
	    if(!flag) break;
  	}
	// 输出
	for(i = 0; i < n; i++)
	{
		printf("%d %d\n",num[i][0],num[i][1]);
	} 
	  
	return 0;
} 

// 冒泡测试 
int main1()
{
    int i,j,temp,n=10, num[10]={3,5,2,10,9,8,7,6,5};
    int flag;
	// 冒泡排序
	for(j = 1; j <= n-1; j++) 
	{
		flag=0;
		for(i = 0; i < n - j; i++)
		{
			if (num[i] < num[i+1]) 
			{ 
				temp = num[i]; num[i] = num[i+1]; num[i+1] = temp; 
				flag=1;
			}
	    }
	    // 输出
	    printf("第%d次\n",j); 
	    for(i = 0; i < n; i++)
	    {
		    printf("%d ",num[i]);
	    } 
	    printf("\n"); 
	    if(!flag) break;
  	}
  	
    // 输出
	for(i = 0; i < n; i++)
	{
		printf("%d ",num[i]);
	} 
    return 0;
}

