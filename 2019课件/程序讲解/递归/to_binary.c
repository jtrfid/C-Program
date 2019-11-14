#include <stdio.h>
void to_binary(unsigned long n);
int main()
{
  unsigned long  x=0XD2;
  //scanf("%x",&x); //十六进制输入 
  scanf("%uld",&x); //等效10进制无符号长整型
  //printf("%X,%ld\n",x,x);
  to_binary(x);
  putchar('\n'); 
  return 0;
}

void to_binary(unsigned long n)
{
	int r;
	r=n%2;
	//putchar('0'+r);
	if(n>=2) to_binary(n/2); // push(先计算的二进制位r)
	//printf("\n正序输出:\n");
	// pop 后进先出 
	putchar('0'+r); 
} 

