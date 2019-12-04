/************************************************************************** 
试题编号	25
试题名称	括号匹配
时间限制:	2 秒
内存限制:	10000MB
问题描述	
问题描述
请写一个程序，判断给定表达式中的括号是否匹配。表达式中的合法括号为“(”、“)”、“[”、“]”、“{”、“}”，这三种括号可以按照任意的次序嵌套使用。
输入说明
有多个表达式，每个表达式占一行。当输入的表达式为空字符串（长度为0）时表示输入结束
输出说明
对每个表达式，若其中的括号是匹配的，则输出“yes”，否则输出“no”。
输入样例
[(d+f)*{}2] 
[(2+3)) 
()} 
[4(6]7)9 

输出样例
yes 
no 
no 
no
提示信息
 ************************************************************************/
 #include <stdio.h>
 #include <string.h>
 #define N 100
 
 // 检查字符串s的括号匹配情况，匹配返回：1，否则返回：0 
 // 参数state记录当时的括号栈的状态
 // 仅能处理单一括号'(','[','{',不能互相嵌套，如 // [4(6]7)9 
 int match(char s[],char left,char right,int state)
 {
 	if(*s == '\0')
 	{
 		if(state == 0) return 1;
 		else return 0;
	}
	if(state < 0) return 0;
	if(*s == left) return match(s+1,left,right,state+1);
	else if(*s == right) return match(s+1,left,right,state-1);
 	else return match(s+1,left,right,state);		
 } 
 
 // 检查字符串s的括号匹配情况，匹配返回：1，否则返回：0 
 int check(char s[])
 {
    return(match(s,'(',')',0) && match(s,'[',']',0) && match(s,'{','}',0)); 
 } 
 
 int main()
 {
	char s[N];
	while(1)
	{
		// 输入[4(6]7)9会出错  
		gets(s);  // 可以接收空串的输入，不能使用scanf("%s",s); 
		if(s[0] == '\0') break;  // 结束循环 
		if (check(s)) printf("yes\n");
		else printf("no\n"); 
	}
 	return 0;
 }
