
#include <stdio.h>
#include <math.h>
 
int main()
{
	int n,m;
	scanf("%d",&n);
	m=(int)sqrt(n); 
	if(n==m*m) printf("%d\n",m);
	else printf("no");
	return 0;
} 
