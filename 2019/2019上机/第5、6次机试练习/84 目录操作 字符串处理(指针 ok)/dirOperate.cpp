 #include <stdio.h>
 #include <string.h>
// �����ַ�����󳤶ȣ��洢��Ч�ַ�(N-1)����Ԥ�����һ���ַ�'\0' 
 #define N 201 
 
 /******************************************************
  ��ȡ�Ӵ����� 
  ����s�пո�ǰ׺������s�е��ַ�����subs�У����ո��'\0'����
  ����subs�����ո� ���ظ��ƺ�sָ��ָ��(��ַ) 
  Ҫ��s��subs��'\0'��β��
 *******************************************************/ 
 char* getSubs(char *s, char *subs) 
 {
 	int start=0; 
	while(*s)
 	{
		if(*s==' ') 
		{
			if(start==0) s++; // ����s��ǰ׺�ո� 
			else break; // ����Ч�ַ������һ���ո� 
		}
		else
		{
			start=1; // ��ʼ���� 
 		    *subs=*s;
 		    s++;
			subs++;
		}
	}
	*subs='\0'; // ��Ҫ���ǽ�β�� 
	return s;
 }
 
 // cd .. ����, ����pwd���ص�ǰĿ¼����һ��Ŀ¼
 // pwd="/a/b/c" �� "/a" 
 void dotdot(char *pwd)
 {
 	int i,len;
 	if(strcmp(pwd,"/")==0) return; // ����Ѿ��Ǹ�Ŀ¼, �޶��� 
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
 
 // ����command, ����pwd���ص�ǰĿ¼ 
 void parse(char *command, char *pwd)
 {
	char *p, str[N]; // str��cd����ַ���(�����ո�) 
 	p=getSubs(command, str); // ���"cd" 
 	getSubs(p,str); // cd����ַ��� 
 	// cd / �� cd /a/b/c �� cd a/b/c 
 	if(strcmp(str,"/")==0) strcpy(pwd,"/");            // cd /
	else if(strcmp(str,"..")==0)  dotdot(pwd); // cd ..
	else if(str[0]=='/') strcpy(pwd,str);       // cd /a/b/c
	else // cd a/b/c, pwdΪpwd/str 
	{
		if(pwd[strlen(pwd)-1]!='/') strcat(pwd,"/"); // ���pwd���һ���ַ��Ƿ�'/' 
		strcat(pwd,str);
	}
 } 
 
  
 int main()
 {
 	char pwd[N]; // ��ǰĿ¼
	char command[N]; // cd ..  �� cd / �� cd /a/b/c
	
	gets(pwd); // ��һ�� 
	while(1)
	{ 
	   gets(command); 
	   if(strcmp(command,"pwd")==0) break;
	   parse(command,pwd);
	} 
	puts(pwd);
 	return 0;
 }
 
