#include <stdio.h>
#include <math.h>
#define N 100 // ����������鳤�� 

int main() // ���洢��ѡqq�ż����λ�� 
{ 
    // select_qq,select_sum��ʾ��ѡqq�����λ֮�ͣ�qq,sum��ʾ��ǰ��ȡ��qq�����λ�� 
	int i,n,select_qq,select_sum,qq,sum,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&qq);
		tmp=qq; // ���浽��ʱ�����У���Ϊ�����ѭ�����Ҫ���ġ� 
		sum=0;  // һ����ʼ�� 
		while(tmp) // �����λ֮�� 
		{
			sum+=tmp%10;
			tmp/=10;
		}
		// ��1�ֵ�������ǰ��ȡ��qq������ѡ; 
		// ||�� &&���������ִ�У�ȡ�ý������ִ�к���ı��ʽ��
		// ȡ�ý���ĺ�����: if (����1||����2||����3)������, ֻҪ��һ���������ʽΪ��(��0)������������()�����Ϊ�档 
		// if (����1&&����2&&����3)������, ֻҪ��һ���������ʽΪ��(0)������������()�����Ϊ�١�
		if(i==0 || sum>select_sum || (sum==select_sum && qq>select_qq))
        { 
			select_qq=qq;
			select_sum=sum;
		} 
	}
	printf("%d",select_qq);
	return 0;
} 

int main1() // ���(�洢����qq�ż����λ��) 
{
	// ��ά����No, ��һ�б�ʾqq��, �ڶ��б�ʾ��qq�ŵĸ�λ����֮�͡� 
	int i,n,No[N][2],tmp,sum,max=0,largest=0,select;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&No[i][0]);
		tmp=No[i][0];
		sum=0;  // һ����ʼ�� 
		while(tmp)
		{
			sum+=tmp%10;
			tmp/=10;
		}
		No[i][1]=sum;
		if(sum>=max) max=sum; 
	}
	for(i=0;i<n;i++)
	{
		if(No[i][1]==max) // ��ѡ����
		{
		   if(No[i][0]>=largest)
		   {
		   	  select=No[i][0];
		   	  largest=No[i][0];
		   }
		} 
	}
	printf("%d",select);
	return 0;
} 
