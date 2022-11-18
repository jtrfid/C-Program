#include <stdio.h>
#include <math.h>
 
int main1()
{
	int n,m;
	scanf("%d",&n);
	// m=(int)sqrt((double)n); // Visual C++
	//m=sqrt((double)n); // Visual C++
	//m=(int)sqrt(n); // Visual C++ 编译错误, GNU C++ ok 
	m=sqrt(n); // GNU C++, 自动完成类型转换, ok, Visual C++ 编译错误,  
	if(n==m*m) printf("%d\n",m); // n是完全平方数 
	else printf("no");
	return 0;
} 

// 暴力解法 
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		if(n==i*i) break;  // n是完全平方数 
    
	if(i<=n) printf("%d\n",i); // 提前退出循环，n是完全平方数 
	else printf("no");  // 正常退出循环 
	return 0;
} 
