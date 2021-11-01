/*****************************************************************
	德巴赫猜想：
任意一个大偶数都能分解为两个素数的和,
对与输入的一个正偶数，写一个程序来验证歌德巴赫猜想。
由于每个正偶数可能分解成多组素数和，仅输出分解值分别是最小和最大素数的一组，按从小到大顺序输出。

输入说明	
输入一个正偶数n，1<n<1000。

输出说明	
输出分解出的两个最小和最大素数。

输入样例	
10

输出样例	
3 7

**********************************************************************/
#include <stdio.h>
#include <math.h>

// 判断参数n是否素数, 如果是返回1, 否则返回0 
int isPrime(int n)
{
	int i;
	if(n < 2) return 0; // 最小素数是2, 1不是素数也不是合数, 题意(1<n<1000)不包含1,因此此语句不是必须的 
	//for(i = 2; i <= sqrt((double)n); i++) // vs2013编译器要求数学函数严格按原型解释
	//for(i = 2; i <= sqrt(n); i++) // 或条件表达式：i*i<=n 
	for(i = 2; i*i <= n; i++) 
	{
		if (n%i == 0) return 0; // n不是素数 
    }
    return 1; // n是素数 
}

// 二重循环, 从最小素数开始迭代计算，获取符合题意的两个素数 
int main1()
{
	int j,k,num; // num大偶数 
	int flag; // 标志变量：用于标识是否找到符合要求的素数对
	scanf("%d",&num);
	// 对于大偶数num，分解为两个素数 
    for(j = 2; j < num; j++)  //  找出第一个素数(最小的) for #1 
    {
      if(!isPrime(j)) continue; // 如果j不是素数, 继续下一轮迭代 
      
	  flag = 0; // 初始化，未找出素数对 
	  for(k = j + 1; k < num; k++) // //  找出第二个素数 for #2
      {
      	if(isPrime(k) && j+k == num) // j是最小素数, k必然是最大素数
		{
		  	printf("%d %d\n",j,k);
		  	flag = 1; // 找出素数对, 如果没有此设置, 将会输出多组, 例如num=2020时会有多组素数 
			break; // break for #2
		}
	  }
	  if(flag) break; // break for #1 
	}
	return 0;
}

// 不用标志变量版本 
int main2()
{
	int j,k,num; // num大偶数 
	scanf("%d",&num);
	// 对于大偶数num，分解为两个素数 
    for(j = 2; j < num; j++)  //  找出第一个素数(最小的)  for #1 
    {
	  if(!isPrime(j)) continue; // 如果j不是素数, 继续下一轮迭代 
	  
	  for(k = j + 1; k < num; k++) //  找出第二个素数 for #2
      {
      	if(isPrime(k) && j+k == num) // j是最小素数, k必然是最大素数 
		{
		  	printf("%d %d\n",j,k);
		  	return 0; // 找出素数对，结束主函数。 如果不结束, 将会输出多组 
		}
	  }
	}
	return 0;
}

// 优化，根据题意找出一组：最小素数+最大素数=偶数 
int main3()
{
	int j,k,num; // num大偶数 
	scanf("%d",&num);
	// 对于大偶数num，分解为两个素数 
    for(j = 2; j < num; j++)  //  找出第一个素数(最小的)  for #1 
    {
	  if(!isPrime(j)) continue; // 如果j不是素数, 继续下一轮迭代 
	  
	  for(k = num-1; k>=2; k--) //  找出第二个素数(最大的) for #2
      {
      	// j是最小素数, 判断k是否是最大素数并且二者之和=num 
      	if(isPrime(k) && j+k == num) 
		{
		  	printf("%d %d\n",j,k);
		  	return 0; // 找出素数对，结束主函数。如果不结束, 将会输出多组 
		}
	  }
	}
	return 0;
}

// 一重循环, 从最小素数开始迭代计算，获取符合题意的两个素数 
int main4() 
{ 
    int num,i;
	scanf("%d",&num);
	
	for(i = 2;i < num;i++)
	{
		if(isPrime(i)) // i是素数 
		{
			if(isPrime(num-i)) // 如果num-i也是素数, 即满足题意num=i+j 
			{
				printf("%d %d\n",i,num-i); 
				break;
			} 
		}
	}
	return 0; 
} 

// 如果要找出最接近的两个素数，如10=3+7，10=5+5，解法一 
int main5()
{
	int big_even;
	scanf("%d",&big_even);
	
	int a,b;
	for(a=2;a<big_even;a++)
	{
		if(isPrime(a))
		{
			b = big_even-a;
			if(isPrime(b) && b<=a) // 无后者，a,b将不是最接近的两个素数，如10=3+7，10=5+5 
			//if(isPrime(b))
			{
				printf("%d %d\n",b,a);
				break;
			} 
		}
	}
	return 0;
}

