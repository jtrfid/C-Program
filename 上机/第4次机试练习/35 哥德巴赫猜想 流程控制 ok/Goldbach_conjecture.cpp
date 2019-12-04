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

int isPrime(int n)
{
	int i;
	for(i = 2; i <= sqrt((double)n); i++) // vs2013编译器要求数学函数严格按原型解释 
	{
		if (n%i == 0) return 0; // n不是素数 
    }
    return 1; // n是素数 
}

int main()
{
	int j,k,num; // num大偶数 
	int flag; 
	scanf("%d",&num);
	// 对于每个大偶数num，分解为两个素数 
    for(j = 3; j < num; j += 2)  //  for #1 
    {
      flag = 0; // 初始化，未找出素数对 
	  for(k = j + 2; k < num; k += 2) // for #2
      {
      	if(isPrime(j) && isPrime(k) && j+k == num) 
		  {
		  	  printf("%d %d\n",j,k);
		  	  flag = 1; // 找出素数对 
			  break; // break for #2
		  }
	  }
	  if(flag) break; // break for #1 
	}
	return 0;
}
