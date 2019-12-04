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
 
 // 定义结构体类型 
 struct bracket
 {
 	char left;    // 左括号'(','[','{' 
	char right;   // 右括号')',']','}'
	char matching; // left,right是否匹配。'Y'表示匹配，'N'表示不匹配 
 };
 
  // 输出结构体数组 
 void print(struct bracket statcks[],int n)
 {
 	int i = 0;
 	printf("n = %d\n",n); 
 	while(i < n)
 	{
 		printf("left = %c,right = %c,matching = %c\n",statcks[i].left,statcks[i].right,statcks[i].matching);
		i++;
	}
 }

 // 入栈 
 void push(struct bracket stacks[],char left,int *n)
 {
 	stacks[*n].left = left;
	stacks[*n].right = '\0';
	stacks[*n].matching = 'N'; 
	(*n)++; // 栈中元素个数+1 
 }
 
 // 栈顶元素出栈，成功返回：1；否则返回：0 
 int pop(struct bracket stacks[], struct bracket *top,int *n)
 {
 	(*n)--; // 栈中元素个数-1 
	 if(*n < 0) return 0;  
 	*top = stacks[*n];
 	return 1;
 }
 
 // 检查括号匹配情况，匹配返回：1，否则返回：0 
 int check(struct bracket stacks[], char s[])
 {
 	int n = 0, matching = 1; // 栈中无元素，不需要匹配，视为匹配 
 	struct bracket top;
 	char left;
 	while(*s)
 	{
 		if(*s == '(' || *s == '[' || *s == '{') push(stacks,*s,&n);
 		//printf("===%c\n",*s);
 		//print(stacks,n);
 		switch(*s)
 		{
 			case ')': left = '('; break;
			case ']': left = '['; break;
			case '}': left = '{'; break;
			default: left = '\0';
		}
 		if(left != '\0') // 需要检查匹配 
 		{
 			int ret = pop(stacks,&top,&n);
 			//printf("---%c\n",*s);
 		    //print(stacks,n);
 		    //printf("ret = %d,top = %c,left = %c\n",ret,top.left,left);
 			if(ret == 0) {matching = 0; break; } // 无匹配
			else if(top.left != left) { matching = 0; break; } // 不匹配 
		} 
		s++;	
	}
	if(n > 0) matching = 0; // 此时栈不空，还有未匹配的left 
	return matching; 
 } 
 
 int main()
 {
 	struct bracket stacks[N];
	char s[N];
	
	while(1)
	{
		gets(s);
		if(s[0] == '\0') break;
		if (check(stacks,s)) printf("yes\n");
		else printf("no\n"); 
	}
 	return 0;
 }
