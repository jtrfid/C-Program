#include <stdio.h>
void to_binary(unsigned long n);
int main()
{
  unsigned long  x=0XD2;
  //scanf("%x",&x); //ʮ���������� 
  printf("%x\n",x);
  to_binary(x);
  putchar('\n'); 
  return 0;
}

void to_binary(unsigned long n)
{
	int r;
	r=n%2;
	//putchar('0'+r);
	if(n>=2) to_binary(n/2); // push(�ȼ���Ķ�����λr)
	//printf("\n�������:\n");
	// pop ����ȳ� 
	putchar('0'+r); 
} 

