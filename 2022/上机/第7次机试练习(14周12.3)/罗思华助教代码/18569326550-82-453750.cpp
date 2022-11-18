#include<stdio.h>
#include<string.h>
int main() {
	int score = 0, i, j,num=0,b=0,c=0,d=0,e=0;
	char a[50];
	gets(a);
	i=strlen(a); 
	if(a[0]=='\n')
	score=0;
	else
	score=score+1;
	if (i>8)
	score = score + 1;
	if(a[0]!='\n')
	{
		for(j=0;j<i;j++)
	{
		if(a[j]>='a'&&a[j]<='z')
		b++;
		else if(a[j]>='A'&&a[j]<='Z')
		c++;
		else if(a[j]>='0'&&a[j]<='9')
		d++;
		else
		e++;
	}
	if(b!=0)
	num++;
	if(c!=0)
	num++;
	if(d!=0)
	num++;
	if(e!=0)
	num++;
	score=score+num-1;
	}
	printf("%d",score);
	return 0;
}
