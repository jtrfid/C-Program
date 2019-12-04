/******************************************************
问题描述	
若一个非负整数其各位数字按照正反顺序读完全相同，则称之为回文数，例如12321。
判断输入的整数是否是回文数。若是，则输出该整数各位数字之和，否则输出no。

输入说明	
输入为一个整数n，0<=n<100000000。

输出说明	
若该整数为回文数，则输出整数各位数字之和，否则输出no。

输入样例	
样例1输入
131
样例2输入
24

输出样例
样例1输出	
5
样例2输出
no
 ******************************************************/
 
#include <stdio.h>

// 判断num是否是回文数，是：返回1；不是，返回0
// 指针参数*sum，返回这个数的各位之和  
int isPalindromic(int num,int *sum)
{
	int reverse = 0, tmp = num;
	*sum = 0; 
	while(tmp)
	{
		reverse = reverse*10 + tmp%10;
		*sum += tmp%10;
		tmp /= 10;
	}
	if(reverse == num ) return 1;
	else return 0;	
}

int main()
{
    int i,num,sum;

    scanf("%d",&num); 
    if(isPalindromic(num,&sum)) printf("%d\n",sum);
    else printf("no\n");
    return 0;
} 

