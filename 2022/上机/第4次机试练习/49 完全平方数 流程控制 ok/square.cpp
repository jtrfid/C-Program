
#include <stdio.h>
#include <math.h>
 
int main()
{
	int n,m;
	scanf("%d",&n);
	// m=(int)sqrt((double)n); // Visual C++
	//m=sqrt((double)n); // Visual C++
	//m=(int)sqrt(n); // Visual C++ �������, GNU C++ ok 
	m=sqrt(n); // GNU C++, �Զ��������ת��, ok, Visual C++ �������,  
	if(n==m*m) printf("%d\n",m);
	else printf("no");
	return 0;
} 
