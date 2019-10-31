#include <stdio.h>
#include <string.h>

/***********************************************************
	试题编号	83
	试题名称	2017期末考试-题目3-目录操作
	时间限制:	1 秒
	内存限制:	256MB
	问题描述	
	问题描述
	在操作系统中，文件系统一般采用层次化的组织形式，由目录（或者文件夹）和文件构成，形成一棵树的形状。有一个特殊的目录被称为根目录，是整个文件系统形成的这棵树的根节点，在类Linux系统中用一个单独的 “/”符号表示。因此一个目录的绝对路径可以表示为“/d2/d3”这样的形式。当前目录表示用户目前正在工作的目录。为了切换到文件系统中的某个目录，可以使用“cd”命令。假设当前目录为“/d2/d3”，下图给出了cd命令的几种形式，以及执行命令之后的当前目录。现在给出初始时的当前目录和一系列目录操作指令，请给出操作完成后的当前目录。
	
	输入说明
	第一行包含一个字符串，表示当前目录。 
	后续若干行，每行包含一个字符串，表示需要进行的目录切换命令。 
	最后一行为pwd命令，表示输出当前目录 
	注意： 
	1.	所有目录的名字只包含小写字母和数字，cd命令和pwd命令也都是小写。最长目录长度不超过200个字符。 
	2.	当前目录已经是根目录时，cd .. 和cd /不会产生任何作用 
	输出说明
	输出一个字符串，表示经过一系列目录操作后的当前目录
	输入样例
	/d2/d3/d7 
	cd .. 
	cd / 
	cd /d1/d6 
	cd d4/d5 
	pwd 
	输出样例
	/d1/d6/d4/d5
	提示信息
 ***********************************************************/

// 去除前缀和后缀空格，结果在dest和返回值中。 
char *trim(char *dest,const char *source)
{
	const char *p1, *p2;
	
	// 去前缀空格 
	p1 = source;
	while(*p1 != '\0' && (*p1 == ' ' || *p1 == '\t')) p1++;
	// p1指向'\0'或非空格字符，
	if(*p1 == '\0')  // 空字符串，或全为空格的字符串 
	{
		*dest = '\0';
		return dest;
	}
		
	// 去后缀空格 
	p2 = p1;
	while(*p2 != '\0') p2++;  // 最后，p2指向'\0'
	// 使p2指向最后一个字符 
	p2--;
	// 使p2指向最后非空格一个字符 
	while(*p2 == ' ' || *p2 == '\t') p2--;
	
	// from p1 copy to dest
	char *d = dest;
	while(*p1 != '\0' && p1 <= p2) 
	{
		*d = *p1; 
		p1++;
		d++;
	}
	*d = '\0';
	return dest;
}

// 存在'/', 返回 >=0整数，表示最后一个'/'的index; 否则，返回-1。 
int lastSlashIndex(const char *s)
{
	int len = 0;
	const char *p = s;
	while(*p != '\0') 
	{
		p++;
		len++;
	}
	if(len == 0) return -1;
	
	while(*p != '/' && len >= 0) 
	{
		p--;
		len--;
	}
	return(p - s);
} 

// copy source to dest: [0, lastSlashIndex)
// lastSlashIndex <= 0, ruturn "\0" 
char *my_strncpy(char *dest, const char *source, int lastSlashIndex)
{
	char *d = dest;
	int i = 0; 
	if(lastSlashIndex <= 0) 
	{
		*d = '\0';
		return dest;
	}
	
	while(*source != '\0' && i < lastSlashIndex)
	{
		*d = *source;
		source++;
		d++;
		i++;
	}
	*d = '\0';
	
	return dest; 
} 

int main()
{
	char current[200] = "/d2/d3/d7888";
	char command[100][200];  // cd command
	char tmp[200],nospace[200]; 
	int i, commandNum = 0;
	
    // 当前目录 
	gets(tmp);
	trim(current,tmp); // 去除前后缀空格 
	while(1)
	{
		gets(tmp);
		trim(nospace,tmp); // 去除前后缀空格 
		if(strcmp(nospace,"pwd") == 0) break; 
		trim(command[commandNum],&nospace[3]); // 从cd 后开始取命令，如..,或/, 或/d1/d6 
		commandNum++;
	}
	
	puts("=============");
	printf("%d\n",commandNum);
	for(i = 0; i < commandNum; i++)
	{	
		puts(command[i]);
		if(strcmp(command[i],"..") == 0)
		{
			if (strcmp(current,"/")) break;
			
			int index = lastSlashIndex(current);
			if (index > 0) 
			{	
			   my_strncpy(tmp, current, index);
			   strcpy(current,tmp); 
			} 
		} 
		else if(strcmp(command[i],"/") == 0) strcpy(current,"/");
		else
		{
			if (command[i][0] == '/') strcpy(current,command[i]);
			else 
			{
				if (current[strlen(current)-1] != '/') strcat(current,"/");
				strcat(current,command[i]);
			}
		}
		puts(current);		  
	}
	
	puts(current);
	
	return 0;
}

int main1()
{
	char s1[100] = "   av12 c 34   ";
	//char s1[100] = " 2 ";
	// char s1[100] = "3 ";
	//char s1[100] = " 3";
	//char s1[100] = "  ";
	char *p,dest[100];
	p = trim(dest,s1);
	printf("%d,%d,%s,%s,\n",strlen(s1),strlen(p),s1,p);
	printf("%d,%s,\n",strlen(dest),dest);
	return 0;
}

int main2()
{
	char s1[100] = "/d1/d2/d3";
	char s2[100] = "/";
	char s3[100] = "abc";
	char s4[100] = "a/b";
	char dest[100];
	printf("%d,%d,%d,%d\n",lastSlashIndex(s1),lastSlashIndex(s2),lastSlashIndex(s3),lastSlashIndex(s4));
	
	my_strncpy(dest, s1, lastSlashIndex(s1));
	printf("%s\n",dest); 
	my_strncpy(dest, s2, lastSlashIndex(s2));
	printf("%s\n",dest); 
	my_strncpy(dest, s3, lastSlashIndex(s3));
	printf("%s\n",dest); 
	my_strncpy(dest, s4, lastSlashIndex(s4));
	printf("%s\n",dest); 
	return 0;
}

