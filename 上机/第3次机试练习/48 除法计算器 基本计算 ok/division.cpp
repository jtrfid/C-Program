
#include <stdio.h>

int main()
{
	int m,n,q,r;
	scanf("%d%d%d%d",&m,&n,&q,&r);
	if(m==q*n+r) printf("yes\n");
	else printf("%d %d\n",m/n,m%n); 
	return 0;
} 
