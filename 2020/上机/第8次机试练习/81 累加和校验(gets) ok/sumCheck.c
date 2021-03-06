/***********************************************************
	试题编号	81
	试题名称	2017期末考试-题目1-累加和校验
	时间限制:	1 秒
	内存限制:	256MB
	问题描述	
	问题描述
	数据传输中一种常见的校验方式是累加和校验。其实现方式是在一次通讯数据包的最后加入一个字节的校验数据。
	这个字节内容为前面数据包中所有数据按字节累加所得结果的最后一个字节。例如： 
	要传输的信息为： TEST（ASCII码为0x54,0x45,0x53,0x54） 
	四个字节的累加和为：0x54+0x45+0x53+0x54=0x140 
	校验和为累加和的最后一个字节，即0x40，也就是十进制的64 
	现在请设计一个程序计算给出的待传输信息的累加校验和 
	输入说明
	输入为一个字符串，字符串长度不超过100个字符
	输出说明
	输出一个十进制整数，表示输入字符串的累加校验和。
	输入样例
	TEST
	输出样例
	64
	提示信息
 ***********************************************************/

#include <stdio.h>
int main()
{
	char s[101];
	int i,check,sum = 0; 
	
	gets(s); // scanf("%s",s);  // 不能完整接收含空格的字符串 
	for(i = 0; s[i] != '\0'; i++) sum += s[i];
	check = (sum/16%16)*16+sum%16;
	printf("%d\n",check);
	return 0;
}

