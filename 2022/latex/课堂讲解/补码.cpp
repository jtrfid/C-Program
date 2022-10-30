#include<stdio.h> // 标准输入输出的头文件 

int main() // 补码 
{
	printf("%d,%d\n",sizeof(int),sizeof(char)); // 4,1
	
	char c=0xFF;  // 当作整数-1的补码 
	
	printf("%X,%d,%X,%d\n",c,c,-1,-1); // FFFFFFFF,-1,FFFFFFFF,-1
	
	c=255; // 当作整数-1的补码 
	printf("%X,%d,%X,%d\n",c,c,-1,-1); // 7F,127,FFFFFFFF,-1
	
	c=0x7F; // 当作整数127的补码(同原码) 
	printf("%X,%d\n",c,c); // 7F,127
	
	// unsigned c=0XFF;
	printf("%X,%d\n",0XFF,0XFF); // FF,255
	
	// -0表示为-128 
	printf("%X,%d\n",-128,-128); // FFFFFF80,-128 
	printf("%X,%d\n",-127,-127); // FFFFFF81,-127
	
	return 0;	// 函数的返回值是整数0 
} 
