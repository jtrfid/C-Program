#include<stdio.h>
int main()
{
int w,z,n,a;
scanf("%d %d %d",&w,&z,&n);
a=n%10;

if(w>=1&&w<=5)
{

if(z<200)
{
	printf("%d no",a);
	}	
if(z>=200&&a<400)
{
	if(w==1)
	{
		if(a==1||a==6) printf("%d yes",a);
		else printf("%d no",a);
	}
	if(w==2)
	{
		if(a==2||a==7) printf("%d yes",a);
		else printf("%d no",a);
	}
	if(w==3)
	{
		if(a==3||a==8) printf("%d yes",a);
		else printf("%d no",a);
	}
	if(w==4)
	{
		if(a==4||a==9) printf("%d yes",a);
		else printf("%d no",a);
		
	}
	if(w==5)
	{
		if(a==5||a==0)  printf("%d yes",a);
		else printf("%d no",a);
	}
	}
	if(z>=400)
	{
		if(w%2!=0)
		{
			if(a%2!=0) printf("%d yes",a);
			else printf("%d no",a);
		}
		else
		{
			if(a%2==0) printf("%d yes",a);
			else printf("%d no",a);
		}
		}	
}
else printf("%d no",a);
return 0;
}
