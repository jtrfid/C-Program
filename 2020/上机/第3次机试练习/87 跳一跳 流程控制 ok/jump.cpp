#include <stdio.h>
int main()
{
	int score=0, a, i, last=0, num=0;
	while(1)
	{
		scanf("%d",&a);
		if(a==1) score++; 
		if((last==1 || last==0) && a==2) {score=score+2; num=0; } // ��һ�� 1->2 
		if(last==2 && a==2) {score=score+2; num++; } // ����2 
		if(last==2 && (a==1 || a==0)) // 2->1 
		{ 
		   for(i=1;i<=num;i++) // ���������� 
		       score=score+i*2;
		   num=0;
		} 
		if(a==0) break;
		last=a; 
	}
	printf("%d\n",score);	
	return 0;
} 
