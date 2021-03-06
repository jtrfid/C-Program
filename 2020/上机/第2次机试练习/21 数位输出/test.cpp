#include<stdio.h>
/******************************************************
 5位整数已知. 首先用10000除以整数a(分子), 得到分子最高位。 
 改变分子分母, 循环迭代, 依次获得分子的最高位。
*******************************************************/        
int main1()              
{  
	int a,b=10000,i=5; // i记录整数a的初始位数
	scanf("%d",&a);
	while(i>=1)
	{
		if (i==1) printf("%d\n",a/b); // 输出当前a的最高位
		else printf("%d ",a/b);
		a = a-a/b*b;  // 去除当前a的最高位，准备下轮迭代的分子a
		b/=10; // b=b/10, 准备下轮迭代的分母b
		i--;   // 不要忘记位数减1 
	} 
	return 0;           
}      

/******************************************************
 假设不知整数a的位数。
 除10取余，迭代循环，可方便获取整数a的个位，十位，百位，千位, ... 
 利用数组存储个位，十位，百位，千位, ... 最后反序输出即是所求。 
*******************************************************/        
int main2()              
{  
	int a, tmp[100]; // tmp数组存储100(估计的最大值)个整数，用tmp[0],tmp[1],tmp[2],...读写各个整数。
	int i=0, j;         // i: 记录整数a的位数 
	scanf("%d",&a);
	if(a==0) // 考虑整数0的特殊情况，直接输出即可。
	{
		printf("%d\n",a); 
	}
	else // 因为循环语句判断a是否为0, 因此要有上述判断才能考虑到所有可能情况的发生 
	{
		while(a!=0) // 迭代逆序求出整数a的各位数字 
		{
			tmp[i]=a%10; // 存储本轮循环a的末位数
			//printf("调式查看tmp[i]=%d\n",tmp[i]); // 提交时，别忘了注释或删除调试语句 
			a=a/10;      // 改变分子, 准备下轮循环
			i++;         // 位数递增 
		}
		//printf("调式查看i=%d\n",i); 
		//  逆序输出tmp, 此时的i是整数a的位数, 注意tmp的下标从i-1开始到下标0结束。 
		for(j=i-1;j>=0;j--)
		{
			printf("%d ",tmp[j]);
		} 
	}
	return 0;           
}    

/******************************************************
 假设不知整数a的位数。
 利用递归函数求解, a==0的情况在函数外处理输出较方便。
 因此该函数仅考虑a!=0的情况。 
*******************************************************/    
void output(int a)              
{  
	if(a!=0) // 如果考虑a==0的情况, 不好判断是初始a=0还是迭代后a=0的情况。这里考虑后者。前者的处理留给调用它的程序。 
	{
		// '栈'是一种'先进后出'的数据结构 
		output(a/10); // 递归调用, 函数参数会自动存储在系统维护的'栈'中。 
		printf("%d ",a%10);  // 从内部存储'栈'中，依次弹出各位数，输出之。 
	}
	else // a==0 ,可省略else语句，隐含结束递归调用
	{
		return; // 函数结束, 注意本函数无返回值，因此return后无表达式。 
	} 
} 

int main()
{
	int a;
	scanf("%d",&a);
	if(a==0) // 考虑整数0的特殊情况，直接输出即可。
	{
		printf("%d\n",a); 
	}
	else
	{
		output(a); // 函数调用, 完成逆序输出。 
	} 
	return 0; 
}

                               
