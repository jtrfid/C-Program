 #include <stdio.h>
 #include <string.h>
// 估计字符串最大长度，存储有效字符(N-1)个，预留最后一个字符'\0' 
 #define N 201 
 
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
 
 // cd .. 命令, 参数pwd返回当前目录的上一级目录
 // pwd="/a/b/c" 或 "/a" 
 void dotdot(char *pwd)
 {
 	int i,len;
 	if(strcmp(pwd,"/")==0) return; // 如果已经是根目录, 无动作 
 	len=strlen(pwd); 
	for(i=len-1;i>=0;i--)
	{
		if(pwd[i] == '/')
		{
			if(i==0) strcpy(pwd,"/"); // "/a" --> pwd="/"  
			else pwd[i]='\0'; // "/a/b/c"  --> pwd="/a/b" 
			break;
		}
	} 
 }
 
 // 解析command, 参数pwd返回当前目录 
 void parse(char *command, char *pwd)
 {
	char *p, str[N]; // str是cd后的字符串(不含空格) 
 	p=getSubs(command, str); // 获得"cd" 
 	getSubs(p,str); // cd后的字符串 
 	// cd / 或 cd /a/b/c 或 cd a/b/c 
 	if(strcmp(str,"/")==0) strcpy(pwd,"/");            // cd /
	else if(strcmp(str,"..")==0)  dotdot(pwd); // cd ..
	else if(str[0]=='/') strcpy(pwd,str);       // cd /a/b/c
	else // cd a/b/c, pwd为pwd/str 
	{
		if(pwd[strlen(pwd)-1]!='/') strcat(pwd,"/"); // 如果pwd最后一个字符是非'/' 
		strcat(pwd,str);
	}
 } 
 
  
 int main()
 {
 	char pwd[N]; // 当前目录
	char command[N]; // cd ..  或 cd / 或 cd /a/b/c
	
	gets(pwd); // 第一行 
	while(1)
	{ 
	   gets(command); 
	   if(strcmp(command,"pwd")==0) break;
	   parse(command,pwd);
	} 
	puts(pwd);
 	return 0;
 }
 
