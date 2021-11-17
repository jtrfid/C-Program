#include <stdio.h>

int main() 
{
	long num = 0, Num = 0, temp = 0;
	int seed = 0, m = 0, n = 0;
	
//	printf("请输入一个整数a（0<=n<=999999)和一个整数b（0<=n<=9):\n");
	scanf("%ld %d", &num, &seed);
	
	Num = num;
	
	if(num == 0)
	{
		n++;
		if(seed==0)  m++;
//		printf("输入的整数是%ld, 有%d位, %d出现的次数是：%d\n", Num, n, seed, m);
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
		
//		printf("输入的整数是%ld, 有%d位, %d出现的次数是：%d\n", Num, n, seed, m);
	}
	
	printf("%d %d\n", n, m);
	
	return 0;
}
