#include <stdio.h>

// ����10ȡ��, ����ѭ���������ֽ⼼�� 
int main1()
{
    int n,sum = 0; // ע���ʼ��sum
	scanf("%d",&n);
	while(n) // ��Ч��n!=0 
	{
		sum += n%10; // �ۼӱ���ѭ����ĩλ��
		n /= 10;     // ׼������ѭ���ķ���
	}
	printf("%d",sum);
	return 0;	
}

// ���: ����ݹ麯��, ��������n�ĸ�λ��֮�� 
int sum(int n)
{
	if(n!=0)
	{
		return (sum(n/10)+n%10);     // �ۼӱ���ѭ����ĩλ��, ׼������ѭ���ķ���
	}
	else return 0;	
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",sum(n)); // �������á� 
	return 0; 
}


