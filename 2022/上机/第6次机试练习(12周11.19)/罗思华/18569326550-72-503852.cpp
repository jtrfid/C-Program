#include<stdio.h>
#include<string.h>
int m[200000];
int main()
{
	char p[102];
	int maxl=0;
	char t[102];
	while(1)
	{
		gets(p);
		if(!strcmp(p,"***end***")) break;
		int l=strlen(p);
		if(l>maxl)
		{
			maxl=l;
			strcpy(t,p);
		}
		
	}
    printf("%d\n",maxl);
    puts(t);
	return 0;
}
