#include <stdio.h>
#include <math.h>
 
int main1()
{
	int n,m;
	scanf("%d",&n);
	// m=(int)sqrt((double)n); // Visual C++
	//m=sqrt((double)n); // Visual C++
	//m=(int)sqrt(n); // Visual C++ �������, GNU C++ ok 
	m=sqrt(n); // GNU C++, �Զ��������ת��, ok, Visual C++ �������,  
	if(n==m*m) printf("%d\n",m); // n����ȫƽ���� 
	else printf("no");
	return 0;
} 

// �����ⷨ 
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		if(n==i*i) break;  // n����ȫƽ���� 
    
	if(i<=n) printf("%d\n",i); // ��ǰ�˳�ѭ����n����ȫƽ���� 
	else printf("no");  // �����˳�ѭ�� 
	return 0;
} 
