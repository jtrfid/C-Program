#include<bits/stdc++.h>
using namespace std;
int judge(char c)
{
	if(c>='0'&&c<='9') return 1;
	else return 0;
 } 
int main()
{
	int a[2];
	char c;
	string s;
	int i=0,m=0,k=0;
	getline(cin,s);
	while(s[i])
	{
		if(judge(s[i]))
		{
			m=m*10+s[i]-'0';
			i++;
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%')
		{
			c=s[i];
			i++;
		}
		else
		{
			if(judge(s[i-1])) a[k++]=m;
			m=0;
			i++;
		}
	}
	if(k==1) a[k]=m;
	switch(c)
	{
		case '+':cout<<a[0]+a[1];break;
		case '-':cout<<a[0]-a[1];break;
		case '*':cout<<a[0]*a[1];break;
		case '/':cout<<a[0]/a[1];break;
		case '%':cout<<a[0]%a[1];break; 
	}
	return 0;
}
