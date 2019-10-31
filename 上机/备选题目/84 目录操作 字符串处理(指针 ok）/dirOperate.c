#include <stdio.h>
#include <string.h>

/***********************************************************
	������	83
	��������	2017��ĩ����-��Ŀ3-Ŀ¼����
	ʱ������:	1 ��
	�ڴ�����:	256MB
	��������	
	��������
	�ڲ���ϵͳ�У��ļ�ϵͳһ����ò�λ�����֯��ʽ����Ŀ¼�������ļ��У����ļ����ɣ��γ�һ��������״����һ�������Ŀ¼����Ϊ��Ŀ¼���������ļ�ϵͳ�γɵ�������ĸ��ڵ㣬����Linuxϵͳ����һ�������� ��/�����ű�ʾ�����һ��Ŀ¼�ľ���·�����Ա�ʾΪ��/d2/d3����������ʽ����ǰĿ¼��ʾ�û�Ŀǰ���ڹ�����Ŀ¼��Ϊ���л����ļ�ϵͳ�е�ĳ��Ŀ¼������ʹ�á�cd��������赱ǰĿ¼Ϊ��/d2/d3������ͼ������cd����ļ�����ʽ���Լ�ִ������֮��ĵ�ǰĿ¼�����ڸ�����ʼʱ�ĵ�ǰĿ¼��һϵ��Ŀ¼����ָ������������ɺ�ĵ�ǰĿ¼��
	
	����˵��
	��һ�а���һ���ַ�������ʾ��ǰĿ¼�� 
	���������У�ÿ�а���һ���ַ�������ʾ��Ҫ���е�Ŀ¼�л���� 
	���һ��Ϊpwd�����ʾ�����ǰĿ¼ 
	ע�⣺ 
	1.	����Ŀ¼������ֻ����Сд��ĸ�����֣�cd�����pwd����Ҳ����Сд���Ŀ¼���Ȳ�����200���ַ��� 
	2.	��ǰĿ¼�Ѿ��Ǹ�Ŀ¼ʱ��cd .. ��cd /��������κ����� 
	���˵��
	���һ���ַ�������ʾ����һϵ��Ŀ¼������ĵ�ǰĿ¼
	��������
	/d2/d3/d7 
	cd .. 
	cd / 
	cd /d1/d6 
	cd d4/d5 
	pwd 
	�������
	/d1/d6/d4/d5
	��ʾ��Ϣ
 ***********************************************************/

// ȥ��ǰ׺�ͺ�׺�ո񣬽����dest�ͷ���ֵ�С� 
char *trim(char *dest,const char *source)
{
	const char *p1, *p2;
	
	// ȥǰ׺�ո� 
	p1 = source;
	while(*p1 != '\0' && (*p1 == ' ' || *p1 == '\t')) p1++;
	// p1ָ��'\0'��ǿո��ַ���
	if(*p1 == '\0')  // ���ַ�������ȫΪ�ո���ַ��� 
	{
		*dest = '\0';
		return dest;
	}
		
	// ȥ��׺�ո� 
	p2 = p1;
	while(*p2 != '\0') p2++;  // ���p2ָ��'\0'
	// ʹp2ָ�����һ���ַ� 
	p2--;
	// ʹp2ָ�����ǿո�һ���ַ� 
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

// ����'/', ���� >=0��������ʾ���һ��'/'��index; ���򣬷���-1�� 
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
	
    // ��ǰĿ¼ 
	gets(tmp);
	trim(current,tmp); // ȥ��ǰ��׺�ո� 
	while(1)
	{
		gets(tmp);
		trim(nospace,tmp); // ȥ��ǰ��׺�ո� 
		if(strcmp(nospace,"pwd") == 0) break; 
		trim(command[commandNum],&nospace[3]); // ��cd ��ʼȡ�����..,��/, ��/d1/d6 
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

