#include<stdio.h>

// break,continue
int main1()
{
	int i=0;
	while(i<4)
	{
		if(i==2) 
		{
			i++;
			continue; // 终止本轮循环, 开始下轮循环 
		}
		printf("i=%d,",i); // i=0,i=1,i=3,
		i++;
	}
	printf("\nend i=%d\n",i); // end i=4
	return 0;
}

// break,continue
int main2()
{
	int i=0;
	while(i<4)
	{
		if(i==2) 
		{
			i++;
			break; // 终止整个循环 
		}
		printf("i=%d,",i); // i=0, i=1, 
		i++;
	}
	printf("\nend i=%d\n",i); // end i=3 
	return 0;
}

// break,continue
int main()
{
	int i=0;
	for(i=0;i<4;i++) // 对于continue语句, 表达式3是本轮循环的一部分 
	{
		if(i==2) 
		{
			continue; // 终止本轮循环,但会执行for语句的表达式3 (i++), 开始下轮循环 
		}
		printf("i=%d,",i); // i=0,i=1,i=3,
	}
	printf("\nend i=%d\n",i); // end i=4
	return 0;
}

// break,continue
int main4()
{
	int i=0;
	for(i=0;i<4;i++) // 对于break语句, 终止整个循环, 表达式3也不会执行 
	{
		if(i==2) 
		{
			break; // 终止整个循环,也不会执行for语句的表达式3 (i++)
		}
		printf("i=%d,",i); // i=0,i=1, 
	}
	printf("\nend i=%d\n",i); // end i=2, 此处根据循环变量i的值可以判断上述循环是否正常结束 
	return 0;
}
