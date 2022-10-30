
#include <stdio.h>
#include <math.h>
 
int main()
{
	int n,m;
	scanf("%d",&n);
	// m=(int)sqrt((double)n); // Visual C++
	//m=sqrt((double)n); // Visual C++
	//m=(int)sqrt(n); // Visual C++ 编译错误, GNU C++ ok 
	m=sqrt(n); // GNU C++, 自动完成类型转换, ok, Visual C++ 编译错误,  
	if(n==m*m) printf("%d\n",m);
	else printf("no");
	return 0;
} 
