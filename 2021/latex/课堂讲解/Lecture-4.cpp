#include<stdio.h>
#include<math.h>
 
int main1()
{
	double x;
	char c2=-5,c3=0xFB;
	int a=-5,b,c,d;
	float y;
	unsigned char c1=-5;
	unsigned int a1=0XFFFFFFFB, a2=0xFB, a3=-5;
	
	printf("%X,%X,%X\n",a1,a2,a3); // FFFFFFFB,FB,FFFFFFFB
	
	printf("%c,%d,%X,%c,%c\n",'?','?','?',0X3F,0XFB);
	
	printf("%X,%d,%c\n",c3,c3,c3); // FFFFFFFB,-5,?
	
	printf("%d,%d\n",15*16+11,a);	
	
	printf("%X,%d,%X,%d,%d\n",c1,c1,c2,c2); // FB,251,FFFFFFFB,-5
	
	//scanf("%d%c%d%d%lf%f",&a,&z,&b,&c,&x,&y);
	//scanf("%d",&b);
	//scanf("%d",&c); 
	//printf("%d,%d,%d,%c,%.3lf,%.2f\n",a,b,c,z,x,y);
	return 0;
}

// 算术表达式，+，-，*，/ 
int main2()
{
	double x=10.0;
	char c2=-5,c3='s';
	int a=-5,b,c,d;
	float y=10.5,y1;
	unsigned char c1=-5;
	unsigned int a1=0XFFFFFFFB, a2=0xFB, a3=-5;
	
	c=a*(y+10); // 结果是整数,不四舍五入 
	y1=a*y+10;
	y1=x*c3; // double -> float
	
	printf("%d,%f,%d\n",c,y1,c3); // -42,1150.000000,115
	
	c=a/10; // 整数/整数--->结果是整数
	
	y1=a/10;  // 0.0
	
	y1=a/10.0; // 0.5 
	
    y1=(float)a/10; // 在表达式内，转换a为float 
	
	printf("%d,%d\n",c,a);
	
	return 0;
}

// i++,++i; i--,--i
int main3()
{
	int i=0,a;
	
	a=i++; // i: 先使用，后加1 
	
	printf("%d,%d\n",a,i); // 0,1
	
	a=++i; // i: 先加1，后使用 
	
	printf("%d,%d\n",a,i); // 2,2
	
	i++; // i=i+1 
	
	return 0;
}

// 数学函数 
// int abs(int x); double fabs(double x)
int main()
{
	int a=-10;
	float x=10.0;
	
	printf("%d,%f\n",abs(a),fabs(x));
	
	return 0;
}
