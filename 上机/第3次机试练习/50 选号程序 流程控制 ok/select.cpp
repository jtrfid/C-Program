#include <stdio.h>
#include <math.h>
#define N 100 // 估计最大数组长度 

int main() // 仅存储备选qq号及其各位和 
{ 
    // select_qq,select_sum表示备选qq及其各位之和，qq,sum表示当前读取的qq及其各位和 
	int i,n,select_qq,select_sum,qq,sum,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&qq);
		tmp=qq; // 保存到临时变量中，因为下面的循环语句要更改。 
		sum=0;  // 一定初始化 
		while(tmp) // 计算各位之和 
		{
			sum+=tmp%10;
			tmp/=10;
		}
		// 第1轮迭代，当前读取的qq就是所选; 
		// ||和 &&运算从左到右执行，取得结果，则不执行后面的表达式。
		// 取得结果的含义是: if (条件1||条件2||条件3)运算中, 只要有一个条件表达式为真(非0)，即整个条件()结果即为真。 
		// if (条件1&&条件2&&条件3)运算中, 只要有一个条件表达式为假(0)，即整个条件()结果即为假。
		if(i==0 || sum>select_sum || (sum==select_sum && qq>select_qq))
        { 
			select_qq=qq;
			select_sum=sum;
		} 
	}
	printf("%d",select_qq);
	return 0;
} 

int main1() // 另解(存储所有qq号及其各位和) 
{
	// 二维数组No, 第一列表示qq号, 第二列表示该qq号的各位数字之和。 
	int i,n,No[N][2],tmp,sum,max=0,largest=0,select;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&No[i][0]);
		tmp=No[i][0];
		sum=0;  // 一定初始化 
		while(tmp)
		{
			sum+=tmp%10;
			tmp/=10;
		}
		No[i][1]=sum;
		if(sum>=max) max=sum; 
	}
	for(i=0;i<n;i++)
	{
		if(No[i][1]==max) // 备选号码
		{
		   if(No[i][0]>=largest)
		   {
		   	  select=No[i][0];
		   	  largest=No[i][0];
		   }
		} 
	}
	printf("%d",select);
	return 0;
} 
