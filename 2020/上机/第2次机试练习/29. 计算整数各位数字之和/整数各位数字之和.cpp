#include <stdio.h>

// 体会除10取余, 迭代循环的整数分解技巧 
int main1()
{
    int n,sum = 0; // 注意初始化sum
	scanf("%d",&n);
	while(n) // 等效于n!=0 
	{
		sum += n%10; // 累加本轮循环的末位数
		n /= 10;     // 准备下轮循环的分子
	}
	printf("%d",sum);
	return 0;	
}

// 另解: 定义递归函数, 返回整数n的各位数之和 
int sum(int n)
{
	if(n!=0)
	{
		return (sum(n/10)+n%10);     // 累加本轮循环的末位数, 准备下轮循环的分子
	}
	else return 0;	
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",sum(n)); // 函数调用。 
	return 0; 
}


