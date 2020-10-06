#include<stdio.h>
#include<math.h> 
int main1()
{
	int a=0x0123,b,sum;
	float c;
	double d;
	char e;
	unsigned int f=0xFFFFFFFB;
	unsigned char g=0xFB,g1=0xFF;
	printf("%X,%d,%u,%d\n",g,g,g,15*16+11);
	printf("%X,%d,%u,%d\n",g1,g1,g1,15*16+15);
	a=-5; 
	b=456;
	sum=a+b;
	//printf ("%X,%d,%d\n",a,a,sum);
	scanf("%f%c%lf",&c,&e,&d);
	// printf("%f,%lf,%c\n",c,d,e);
	return 0;

}

// +,-,*,/, a%b求a/b的余数 
// a++,++a;
// int abs(int x); 函数原型 
int main()
{
	int a=-11,b=21,sum;
	int i=5;
	float c=10.5;
	double d;
	char e='A';
	printf("%d\n",abs(a));
	d=a*(c+10)+e;
	b=a*c+10+e;
	d=a/b; // 整数/整数 ---- 结果是整数 
	printf("d=%lf,%d,%d,%d,%d\n",d,b,e,a%10,1/2);
	b=a++;  // a++先使用a, 本身再加1 
	printf("%d,%d\n",a,b); // 12,11
	b=++i; // 先加1, 再使用 
	printf("%d,%d\n",i,b); // 6,6
	return 0;

}
