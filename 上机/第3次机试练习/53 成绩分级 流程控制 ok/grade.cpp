/****************************************************************
	试题编号	36
	试题名称	成绩分级 
	时间限制:	2 秒
	内存限制:	10000MB
	问题描述	
		给出一个百分制的成绩，要求输出成绩等级'A','B','C','D','E'。90分以上为'A'，80~89分为'B',70~79分为'C',60~69分为'D'，60分以下为'E'。
	输入说明
		输入一个正整数m（0<=m<=100）
	输出说明
	   输出一个字符
	输入样例
	59
	输出样例
	E 
	提示信息
 ****************************************************************/
#include <stdio.h>
int main()
{
	int grade;
	scanf("%d",&grade);
	grade /= 10;
	switch(grade)
	{
		case 0: case 1: case 2: case 3: case 4: 
		case 5:  printf("E"); break;
		case 6:  printf("D"); break;
		case 7:  printf("C"); break;
		case 8:  printf("B"); break;
		case 9:
		case 10:  printf("A"); break;
			
	}
	return 0;
} 
