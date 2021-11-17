/***********************************/
/* 功能：求统计整数的各位数字      */ 
/* 方法：循环取模法                */
/***********************************/
 
#include <stdio.h>

int main(void)
{
	long num = 0, Num = 0, temp = 0;
	int n = 0, i = 0, sum = 0;
	
//	printf("请输入一个整数：\n");
	scanf("%ld", &num);
	
	Num = num;
	
	if(num == 0)
	{
		n++;
//		printf("输入的整数是%ld, 有%d位, 各位的数字之和为：%d\n", Num, n, sum);
	}
	else
	{		
		while(num > 0)
		{
			n++;
			temp = num % 10;
			sum = sum + temp;
			num = num / 10;
		}
		
//		printf("输入的整数是%ld, 有%d位, 各位的数字之和为：%d\n", Num, n, sum);
	}

//	printf("输入的整数是%ld, 有%d位, 各位的数字之和为：%d\n", Num, n, sum);
	printf("%d %d\n", n, sum);
	
	return 0;		
}

