/************************************************************************** 
试题编号	56
试题名称	单元测试2-题目2-表达式求值
时间限制:	1 秒
内存限制:	256MB
问题描述	
问题描述
求一个表达式的值。表达式由两个非负整数x，y和一个运算符op构成。
这两个整数和运算符的顺序是随机的，可能是”x op y”， “op x y”或者 “x y op”，
例如，“25 + 3”表示25加3，“5 30 *” 表示5乘以30，“/ 600 15”表示600除以15。
输入说明
输入为一个表达式，表达式由两个非负整数x，y和一个运算符op构成，x，y和op之间以空格分隔，但顺序不确定。
x和y均不大于10000000，op可以是+，-,*，/，%中的任意一种，分表表示加法，减法，乘法，除法和求余。
除法按整数除法求值，输入数据保证除法和求余运算的y值不为0。
输出说明
输出表达式的值。
输入样例
5 20 *
输出样例
100
提示信息
 ************************************************************************/
 
 /**********************************
  思路: 
  gets函数读取字符串，遍历字符串，根据op字符是"非数字字符"的特点，判断表达式的三种形式。\\
  注意: 因为字符串中含有空格, 不能使用\lstinline|scanf("%s",-);|读取字符串。
  设计各个子函数, 进行模块化程序设计。
  编写函数parse, 解析输入字符串, 生成3个子字符串, 分别代表op,x,y
  编写函数strToInt, 将数字字符串转为整数。
  编写函数compute, 根据op,x,y计算表达式的值。
  编写其它辅助函数。
  主程序, 调用上述函数, 完成程序功能。
  **********************************/ 
  
 #include <stdio.h>
// 估计字符串最大长度，存储有效字符(N-1)个，预留最后一个字符'\0' 
 #define N 20 
 
 // 根据参数，计算表达式的值 
 int compute(char op,int x,int y)
 {
 	int result = -1;
 	switch(op)
 	{
 		case '+': result = x+y; break;
 		case '-': result = x-y; break;
 		case '*': result = x*y; break;
 		case '/': if(y != 0) result = x/y; break;
 		case '%': if(y != 0) result = x%y; break;
	}
	return result;
 }
 
 // 数字字符串s转为int, 要求s以'\0'结尾 
 int strToInt(char *s)// int toInt(char s[]) 
 {
 	int result=0;
	while(*s) // *s != '\0'
	{
		result=result*10+ (*s-'0');
		s++; //移至下一字符 
	}
	return result;
 } 
 
 /******************************************************
  提取子串函数 
  忽略s中空格前缀，复制s中的字符串到subs中，遇空格或'\0'结束
  返回subs不含空格。 返回复制后s指针指向(地址) 
  要求s和subs以'\0'结尾。
 *******************************************************/ 
 char* getSubs(char *s, char *subs) 
 {
 	int start=0; 
	while(*s)
 	{
		if(*s==' ') 
		{
			if(start==0) s++; // 忽略s的前缀空格 
			else break; // 是有效字符串后的一个空格 
		}
		else
		{
			start=1; // 开始复制 
 		    *subs=*s;
 		    s++;
			subs++;
		}
	}
	*subs='\0'; // 不要忘记结尾符 
	return s;
 }
 
 // 解析s, 以空格为分隔符, 分解s为3个字符串 
 void parse(char *s,char result[][N])
 {
 	char *p;
 	p=getSubs(s,result[0]);
 	p=getSubs(p,result[1]);
 	p=getSubs(p,result[2]);
 } 
 
 // 如果s是操作符，返回1, 参数op返回该操作符
 // 否则, 返回0 
 int isOp(char *s, char *op)
 {
 	if(*s >= '0' && *s <= '9') return 0;
 	else
 	{
 		*op=*s;
 		return 1;
	}
 } 
  
 int main1()
 {
 	char *s="123";
 	printf("%d\n",strToInt(s)); // 123
 	
 	char s1[N]="    abcd   456  +", s2[50], *s3;
	s3= getSubs(s1,s2);
    printf("%s,%d\n",s2,*s3); // abcd,32(空格的ASCII码) 
    s3= getSubs(s3,s2);
    printf("%s,%d\n",s2,*s3);// 456,0('\0'的ASCII码) 
    
    char result[3][N];
    parse(s1,result);
    puts(result[0]); // abcd
    puts(result[1]); // 456
    puts(result[2]); // +
 	return 0;
 }
 
 int main()
 {
	char s[N],op;
	char s3[3][N];   
	int x,y;
	gets(s); // 不能使用scanf("%s",s); 空格将会终止
	
	parse(s,s3); // s被分解为3个字符串 
	if(isOp(s3[0],&op)) // op x y
	{
		x=strToInt(s3[1]);
		y=strToInt(s3[2]);
	}
	else if(isOp(s3[1],&op)) // x op y
	{
		x=strToInt(s3[0]);
		y=strToInt(s3[2]);
	}
	else if(isOp(s3[2],&op)) // x y op
	{
		x=strToInt(s3[0]);
		y=strToInt(s3[1]);
	}
	
    printf("%d\n",compute(op,x,y)); 
 	return 0;
 }
