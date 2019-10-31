/*****************************************************************
	试题编号	16
	试题名称	歌德巴赫猜想
	时间限制:	2 秒
	内存限制:	10000MB
	问题描述	
	问题描述
	编写函数isPrime(long n)，说明如下：函数的功能是判断给定的正整数n是否为素数，函数的返回值1/0表示n是/不是素数。 
	编写main()函数，调用isPrime()验证歌德巴赫猜想：任意一个大偶数都能分解为两个素数的和。 
	输入说明
	第一行1个整数m（100 > m >0），表示有多少组数据。 其后一行为m个正偶数，表示m个数据。
	输出说明
	每行输出2个数据表示分解的素数（每个正偶数可能分解成多组素数和，仅输出分解值分别是最小和最大素数的一组，从小到大输出），换行。
	输入样例
	2 
	10 20
	输出样例
	3 7 
	3 17
	提示信息
**********************************************************************/
#include <stdio.h>
#include <math.h>

int isPrime(long n)
{
	int i;
	for(i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0) return 0; // n不是素数 
    }
    return 1; // n是素数 
}

int main()
{
	int i,j,k,m,num; // num大偶数 
	int flag; 
	scanf("%d",&m);
    for(i = 0; i < m; i++) 
	{
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
	}
	return 0;
}
