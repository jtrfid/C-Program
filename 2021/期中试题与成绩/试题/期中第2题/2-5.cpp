#include <stdio.h>

int main() 
{
	long num = 0, Num = 0, temp = 0;
	int seed = 0, m = 0, n = 0;
	
//	printf("������һ������a��0<=n<=999999)��һ������b��0<=n<=9):\n");
	scanf("%ld %d", &num, &seed);
	
	Num = num;
	
	if(num == 0)
	{
		n++;
		if(seed==0)  m++;
//		printf("�����������%ld, ��%dλ, %d���ֵĴ����ǣ�%d\n", Num, n, seed, m);
	}
	else
	{		
		while(num > 0)
		{
			n++;
			temp = num % 10;
			if(seed==temp)  m++;
			num = num / 10;
		}
		
//		printf("�����������%ld, ��%dλ, %d���ֵĴ����ǣ�%d\n", Num, n, seed, m);
	}
	
	printf("%d %d\n", n, m);
	
	return 0;
}
