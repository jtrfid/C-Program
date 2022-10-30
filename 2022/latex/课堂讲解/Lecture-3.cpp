#include<stdio.h> //预处理 
int main1() // 主函数，程序开始 
{
	int a=0x20; //整型变量
	float f=5.2; // 单精度浮点数
	double d=2.1; // 双精度浮点数 
	char c=' ';
	
	printf("%d,0x%X,%d,%cHHHHH\n",c,c,a,a);
	printf("%c,%d;%c,%d,%d",'a','a','A','A','a'-'A');
	/*********
	//scanf("%d,%f,%lf,%c",&a,&f,&d,&c);// 输入变量的值，&取地址符 
	scanf("%d%f%lf%c",&a,&f,&d,&c);
	// 数据类型占用存储单元的大小，1字节是最小存储单元 
	//printf("size=%d,%d,%d\n",sizeof(int),sizeof(float),sizeof(double));
	printf("%d,%.2f,%.3lf,%c,%d",a,f,d,c,c); // 输出变量的值 
	*********/
	return 0;
}

int main2() // 主函数，程序开始 
{
	int a=10; //整型变量
	float f=5.2; // 单精度浮点数
	double d=2.1; // 双精度浮点数 
	char c1,c2; // 字符类型 
	
	scanf("%c",&c1);
	// ............
	getchar(); // 消费回车健，getchar()接收一个字符 
	//scanf("%c",&c2);

    c2=getchar();
    
    printf("output============\n");
    
    putchar(c2);
    putchar('\n');
		
	printf("c1=%c,%d,====c2=%c,%d\n",c1,c1,c2,c2); // 输出变量的值 
	return 0;
}

int main() // 主函数，程序开始 
{
	int a,b;
	char op; // 字符类型 
	
	scanf("%d%c%d",&a,&op,&b);
	printf("%d %c %d=?\n",a,op,b);
		
	//printf("c1=%c,%d,====c2=%c,%d\n",c1,c1,c2,c2); // 输出变量的值 
	return 0;
}

int main4()
{
    int a=-25,b=102;
    printf("a=%d,b=%d,a=%x,b=%x\n",a,b,a,b);
    printf("%d,%d,%x,%x\n",-25,102,-25,102);
    printf("%d,%d,%x,%x,%X\n",77,-77,77,-77,-77);
	return 0;
} 
