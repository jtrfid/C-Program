/***********************************/
/* ���ܣ���ͳ�������ĸ�λ����      */ 
/* ������ѭ��ȡģ��                */
/***********************************/
 
#include <stdio.h>

int main(void)
{
	long num = 0, Num = 0, temp = 0;
	int n = 0, i = 0, sum = 0;
	
//	printf("������һ��������\n");
	scanf("%ld", &num);
	
	Num = num;
	
	if(num == 0)
	{
		n++;
//		printf("�����������%ld, ��%dλ, ��λ������֮��Ϊ��%d\n", Num, n, sum);
	}
	else
	{		
		while(num > 0)
		{
			n++;
			temp = num % 10;
			sum = sum + temp;
			num = num / 10;
		}
		
//		printf("�����������%ld, ��%dλ, ��λ������֮��Ϊ��%d\n", Num, n, sum);
	}

//	printf("�����������%ld, ��%dλ, ��λ������֮��Ϊ��%d\n", Num, n, sum);
	printf("%d %d\n", n, sum);
	
	return 0;		
}

