#include<stdio.h> // ��׼���������ͷ�ļ� 

int main() // ���� 
{
	printf("%d,%d\n",sizeof(int),sizeof(char)); // 4,1
	
	char c=0xFF;  // ��������-1�Ĳ��� 
	
	printf("%X,%d,%X,%d\n",c,c,-1,-1); // FFFFFFFF,-1,FFFFFFFF,-1
	
	c=255; // ��������-1�Ĳ��� 
	printf("%X,%d,%X,%d\n",c,c,-1,-1); // 7F,127,FFFFFFFF,-1
	
	c=0x7F; // ��������127�Ĳ���(ͬԭ��) 
	printf("%X,%d\n",c,c); // 7F,127
	
	// unsigned c=0XFF;
	printf("%X,%d\n",0XFF,0XFF); // FF,255
	
	// -0��ʾΪ-128 
	printf("%X,%d\n",-128,-128); // FFFFFF80,-128 
	printf("%X,%d\n",-127,-127); // FFFFFF81,-127
	
	return 0;	// �����ķ���ֵ������0 
} 
