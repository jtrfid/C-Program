#include<stdio.h>
#include<string.h>
int m[200000];
int main()
{
    char s[100];
    int a[2],m=0,q=0;
    a[0]=0;
    a[1]=0;
    char t;
    gets(s);
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
    	if(s[i]>='0'&&s[i]<='9')
    	{  q=1;
    		a[m]=a[m]*10+s[i]-'0';
		}
		else
		{
			if(q) m=1;
			if(s[i]!=' ')
			{
				t=s[i];
			}
		}
	}
	int sum;
	if(t=='+') sum=a[0]+a[1];
	else if(t=='-') sum=a[0]-a[1];
	else if(t=='*') sum=a[0]*a[1];
	else if(t=='/') sum=a[0]/a[1];
	else sum=a[0]%a[1];
	printf("%d",sum);
	return 0;
}
