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
#include <string.h>

// 思路1:  求该整数的反序组成的整数，如整数1234, 其反序整数即为4321, 如果二者相等即为回文数 
// 判断num是否是回文数，是：返回1；不是，返回0
// 指针参数*sum，返回这个数的各位之和  
int isPalindromic1(int num,int *sum)
{
	int reverse = 0, tmp = num;
	*sum = 0; // 初始换指针内容 
	while(tmp)
	{
		reverse = reverse*10 + tmp%10;
		*sum += tmp%10;
		tmp /= 10;
	}
	if(reverse == num ) return 1;
	else return 0;	
}

// 思路2:  构造数组reverse, 反序存储该整数各位数，按照数组下标，前后数组元素相等则为回文数 
// 判断num是否是回文数，是：返回1；不是，返回0
// 指针参数*sum，返回这个数的各位之和  
int isPalindromic2(int num,int *sum)
{
	int reverse[9], len=0, i=0; // 依题意数组最大长度为9，最多存储9位数。实际长度用len变量表示 
	
	*sum = 0; // 初始换指针内容 
	//构造数组reverse, 反序存储该整数各位数
	while(num)
	{
		reverse[i]=num%10;  
		*sum += num%10;   // 累加各位数字 
		num /= 10;
		len++; // 计算数组实际长度 
		i++; 
	}
	//按照数组下标，前后数组元素相等则为回文数
	for(i=0; i<len/2;i++)
	{
		if(reverse[i] != reverse[len-i-1]) return 0;  // 不是回文数 
	}
	return 1;	// 至此，必然是回文数 
}

int main12()
{
    int i,num,sum;

    scanf("%d",&num); 
    //if(isPalindromic1(num,&sum)) printf("%d\n",sum);
    if(isPalindromic2(num,&sum)) printf("%d\n",sum);
    else printf("no\n");
    return 0;
} 

// 思路3:  按照字符串处理输入的整数，前后数组元素相等则为回文数 
int main3()
{
	char s[10]; // 留出'\0', 最多存储9位数。实际长度用len变量表示
	int sum=0, len=0,i; 
	
	// 以字符串形式接收输入的整数 
	gets(s);
	
	// 计算len, 或者len=strlen(s), 同时计算各位数字之和 
	for(len=0;s[i]!='\0';) 
	{
		len++;
		sum=sum+s[i]-'0'; // 计算各位数字之和
		i++;  
	}
	
	//按照数组下标，前后数组元素相等则为回文数
	for(i=0; i<len/2;i++)
	{
		if(s[i] != s[len-i-1]) // 不是回文数 
		{
			printf("no\n");
			return 0;  // 主函数结束 
		} 
	}
	// 至此，必然是回文数 
	printf("%d\n",sum);
	return 0;
}

// 思路4:  按照字符串处理输入的整数，前后数组元素相等则为回文数。
// 使用指针操作 
int main()
{
	char s[10]; // 留出'\0', 最多存储9位数。实际长度用len变量表示
	int sum=0; 
	char *p1=s,*p2=s; // 用于正序和反序遍历s数组，初始指向第一个元素 
	
	// 以字符串形式接收输入的整数 
	gets(s);
	
	// 用p2遍历字符串,同时计算各位数字之和 
	for(;*p2!='\0';p2++) 
	{
		sum=sum+(*p2)-'0'; // 计算各位数字之和
	}
	// 至此，p2指向最后一个元素'\0', 我们使它指向最后一个有效元素： 
	p2--; 
	
	//按照数组下标，前后数组元素相等则为回文数
	for(;p1<p2;p1++,p2--)
	{
		if(*p1 != *p2) // 不是回文数 
		{
			printf("no\n");
			return 0;  // 主函数结束 
		} 
	}
	// 至此，必然是回文数 
	printf("%d\n",sum);
	return 0;
}



