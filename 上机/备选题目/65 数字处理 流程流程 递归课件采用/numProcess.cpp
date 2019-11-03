/*****************************************************************
编写一个程序，从键盘输入一个非零整数n（0 < n <= 1000000000），对整数n进行如下处理：
将整数的各位数字取出来相加，如果结果是一位数则输出该数，否则重复上述过程，直到得到的结果为一位数，并输出该结果。
例如：n=456，变换过程如下
4+5+6=15
1+5=6
输出结果为6

输入说明	
一个非零整数n。

输出说明	
输出整数n的处理结果。

输入样例	
456

输出样例	
6
**********************************************************************/
#include <stdio.h>
#include <math.h>

int bitsSum1(int a)
{
  int sum=0;
  while(a)
  {
    sum += a%10;
    a /= 10;
  }
  return sum;
}

int main1()
{
	int n,sum=0;
	scanf("%d",&n);
	while(1)
	{
		sum=bitsSum1(n);
		if(sum<=9) break;
		else n=sum; // 继续下一轮迭代 
	}
	printf("%d\n",sum); 
	return 0;
}

///////////递归实现
int bitsSum(int a)
{
  int sum;
  if(a==0) sum=0;  
  else sum= bitsSum(a/10)+a%10;
  return sum;
}

int bits1(int n)
{
	int result;
	result=bitsSum(n);
	if(result<=9) return result; // 1位数字则返回 
	else result=bits1(result);   // 否则, 递归 
}

int main()
{
	int n,sum=0;
	scanf("%d",&n);
	printf("%d\n",bits1(n)); 
	return 0;
} 
