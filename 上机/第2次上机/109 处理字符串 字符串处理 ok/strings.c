/******************************************************
	试题编号	29
	试题名称	处理字符串
	时间限制:	2 秒
	内存限制:	10000MB
	问题描述	
	问题描述
	从键盘输入一字符串，将该字符串按下述要求处理后输出：
	将大于原首字符的各字符按原来相互间的顺序关系集中在原首字符的左边，
	小于等于原首字符的各字符按升序集中在原首字符的右边。
	输入说明
	输入只有一行字符串,字符串当读不超过100.
	输出说明
	输出只有一行字符串
	输入样例
	aQWERsdfg7654!@#$hjklTUIO3210X98aY
	输出样例
	sdfghjkla!#$0123456789@EIOQRTUWXYa
	提示信息
 ******************************************************/
// 思路：left[N],right[N]分别存放左右字符串；排序right[N]; 调用库函数strcat，连接两个字符串。 
// 本题可以不必进行字符串连接操作，printf("%s%s\n",left,right); 亦可。
 
#include <stdio.h>
#include <string.h> // str前缀的字符串处理函数需要此头文件
// 估计字符串长度，实际容纳(N-1)个有效字符，预留最后一个字符'\0'  
#define N 100

// 排序函数(升序) 
void sort(char a[],int n)
{ 
	int i,j,t;
	// 冒泡排序
	for(j = 1; j <= n-1; j++) 
		for(i = 0; i < n - j; i++)
			if (a[i] > a[i+1]) 
			{ t = a[i]; a[i] = a[i+1]; a[i+1] = t; }
}

 
int main()
{
    char s[N],left[N],right[N];
    char *p = s;
    int i = 0,j = 0;
	gets(s); // 不能使用scanf("%s",lines),因其遇空格结束
	// 使用指针处理较方便 
    while(*p)
    {
    	if(*p > s[0]) left[i++] = *p;
    	else if(p != s) right[j++] = *p; // 原首字符不加入到right 
		p++; 
	}
	left[i++] = s[0]; // 原首字符加入到left中 
	left[i] = '\0';   // left,right添加结束字符 
	right[j] = '\0';
	sort(right,strlen(right)); // 排序right 
	
	// 本题可以不必进行字符串连接操作，printf("%s%s\n",left,right); 亦可。
	strcat(left,right); // 连接两个字符串 
	puts(left);
    return 0;
} 
