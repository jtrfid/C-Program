/******************************************************
	试题编号	23
	试题名称	寻找最长的行
	时间限制:	2 秒
	内存限制:	10000MB
	问题描述	
	问题描述
	寻找若干行文本中最长的一行
	输入说明
	输入为多个字符串(每个字符串长度不超过100个字符)，每个字符串占一行，输入的行为“***end***”时表示输入结束
	输出说明
	输出其中最长的一行长度后换行再输出最长行的内容，如果最长行不止一个，则输出其中的第一行。
	输入样例
	abce 
	abdf dlfd 
	***end***
	输出样例
	9 
	abdf dlfd
	提示信息
 ******************************************************/ 
#include <stdio.h>
#include <string.h> // str前缀的字符串处理函数需要此头文件 

// 估计字符串长度，实际容纳(N-1)个有效字符，预留最后一个字符'\0' 
#define N 100
 
int main()
{
    char lines[N],maxLine[N];
	
	// 在输入的同时，即可处理，不必设置一个一维数组存储这些数。
	while(1)
	{
		gets(lines);  // 不能使用scanf("%s",lines),因其遇空格结束 
		if(strcmp(lines,"***end***") == 0) break;
		if(strlen(lines) > strlen(maxLine)) strcpy(maxLine,lines);
	}
	
	printf("%d\n%s\n",strlen(maxLine),maxLine); 
    
    return 0;
} 
