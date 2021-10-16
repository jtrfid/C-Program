/***************************************
 标题:	
最大公约数

类别:
	
时间限制:	
2 S

内存限制:	
10000 Kb

问题描述:	
最大公约数（GCD）指某几个整数共有因子中最大的一个，最大公约数具有如下性质，
gcd(a,0)=a
gcd(a,1)=1
因此当两个数中有一个为0时，gcd是不为0的那个整数，
当两个整数互质时最大公约数为1。
输入两个整数a和b，求最大公约数

输入说明：
输入为两个正整数a和b（0<=a,b<10000），a和b之间用空格分隔，

输出说明：
输出其最大公约数

输入样例：
样例1输入	
2 4
样例2输入：
12 6
样例3输入：
3 5


输出样例：
样例1输出	
2
样例2输出
6
样例3输出
1
 ****************************************/
/****************************************
定理：两个整数的最大公约数等于其中较小的那个数和两数相除余数的最大公约数。
a(大),b(小)的最大公约数: 因为: a=mb+r, m=a/b; r=a%b, a,b的公约数能整除b和r.
r=a%b,r为0, 则b就是最大公约数。否则迭代循环, a=b，b=r, 直到余数为零, 则分母就是最
大公约数。
 ****************************************/ 
#include <stdio.h>
int main1()
{
    int a,b,r,t;
    scanf("%d%d",&a,&b); // 机试系统不要想当然给提示语句, 除非题目要求
    if(a<b) { t=a; a=b; b=t; } // 交换a,b,使a是较大者
	while(1)
    {
	   if(b==0) { t=a; break; }  // 分母为0时, a就是最大公约数 
	   r = a%b; // 排除了分母为0时不能求余数的情况 
	   if(r==0) {t=b; break;} // b就是最大公约数
	   // 不必，以下语句 
	   //else if(r==1) {t=1; break;} // a,b互质, 已经包含在上一句 
	   //else if(b%r==0) {t=r; break;} // r就是最大公约数，因为: n=b/r; r=nb; a=mb+nb=(m+n)b;
	   a=b; b=r; // 准备下一轮迭代   
    }
	
    printf("%d\n",t);
	return 0;	
}

// 或 
int main()
{
    int a,b,r,t;
    scanf("%d%d",&a,&b); // 机试系统不要想当然给提示语句, 除非题目要求
    if(a<b) { t=a; a=b; b=t; } // 交换a,b,使a是较大者
    if (b==0) // 考虑分母为0的情况，比如：5,0的最大公约数为5 
	{
		printf("%d\n",a);
		return 0;  // 主函数结束 
	}
	// 排除了分母为0时不能求余数的情况 
	while((r=a%b)!=0) // a/b的余数赋值给r,r不等于0时执行循环体 
    {
	   a=b; b=r; // 准备下一轮迭代   
    }
    printf("%d\n",b);
	return 0;	// 主函数结束 
}

// 或 
int main()
{
    int a,b,r,t;
    scanf("%d%d",&a,&b); // 机试系统不要想当然给提示语句, 除非题目要求
    if(a<b) { t=a; a=b; b=t; } // 交换a,b,使a是较大者
    if (b==0) // 考虑分母为0的情况，比如：5,0的最大公约数为5 
	{
		printf("%d\n",a);
	}
	else 
	{
		// 排除了分母为0时不能求余数的情况 
		while((r=a%b)!=0) // a/b的余数赋值给r,r不等于0时执行循环体 
    	{
	   		a=b; b=r; // 准备下一轮迭代   
   		}
   		printf("%d\n",b);
	}
	return 0;	// 主函数结束 
}
