#include<stdio.h>

// break,continue
int main1()
{
	int i=0;
	while(i<4)
	{
		if(i==2) 
		{
			i++;
			continue; // ��ֹ����ѭ��, ��ʼ����ѭ�� 
		}
		printf("i=%d,",i); // i=0,i=1,i=3,
		i++;
	}
	printf("\nend i=%d\n",i); // end i=4
	return 0;
}

// break,continue
int main2()
{
	int i=0;
	while(i<4)
	{
		if(i==2) 
		{
			i++;
			break; // ��ֹ����ѭ�� 
		}
		printf("i=%d,",i); // i=0, i=1, 
		i++;
	}
	printf("\nend i=%d\n",i); // end i=3 
	return 0;
}

// break,continue
int main()
{
	int i=0;
	for(i=0;i<4;i++) // ����continue���, ���ʽ3�Ǳ���ѭ����һ���� 
	{
		if(i==2) 
		{
			continue; // ��ֹ����ѭ��,����ִ��for���ı��ʽ3 (i++), ��ʼ����ѭ�� 
		}
		printf("i=%d,",i); // i=0,i=1,i=3,
	}
	printf("\nend i=%d\n",i); // end i=4
	return 0;
}

// break,continue
int main4()
{
	int i=0;
	for(i=0;i<4;i++) // ����break���, ��ֹ����ѭ��, ���ʽ3Ҳ����ִ�� 
	{
		if(i==2) 
		{
			break; // ��ֹ����ѭ��,Ҳ����ִ��for���ı��ʽ3 (i++)
		}
		printf("i=%d,",i); // i=0,i=1, 
	}
	printf("\nend i=%d\n",i); // end i=2, �˴�����ѭ������i��ֵ�����ж�����ѭ���Ƿ��������� 
	return 0;
}
