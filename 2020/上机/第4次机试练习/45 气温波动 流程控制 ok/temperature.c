/***********************************************************
	������	59
	��������	��ĩ����-��Ŀ1-���²���
	ʱ������:	1 ��
	�ڴ�����:	256MB
	��������	
	��������
	���һ��ʱ�����²����ϴ���֪��������������£�������⼸�����µ���󲨶�ֵ�Ƕ��٣������⼸����ĳ��������ǰһ������֮��ľ���ֵ����Ƕ��١�
	����˵��
	�������ݷ�Ϊ���С� 
	��һ�а�����һ������n����ʾ����������n�������ֵ��2 �� n �� 30�� 
	�ڶ��а���n�����������α�ʾÿ������£�����Ϊ-20��40֮��������� 
	���˵��
	���һ����������ʾ��������n���е���󲨶�ֵ��
	��������
	6 
	2 5 5 7 -3 5 
	�������
	10
	��ʾ��Ϣ
 ***********************************************************/
#include <stdio.h>
#include <math.h>

// ��ʹ������洢����ֵ 
int main1()
{
	int i, n, last ,temperature, undulation = 0; // last��ǰһ�������ֵ, temperature: ���������ֵ,  undulation����ֵ 
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&temperature);
		if (i != 0 && fabs(temperature - last) > undulation) // ע��i==0ʱ, last��ֵ 
			undulation = fabs(temperature - last);
		last = temperature;
	} 
	printf("%d\n",undulation); 
	return 0;
} 

// ʹ������洢���30������ֵ 
int main()
{
	int i, n,temperature[30], undulation = 0; // temperature����: ����ֵ,  undulation����ֵ 
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&temperature[i]);
	} 
	
	undulation= fabs(temperature[0]-temperature[1]); // ��ʼ����ֵ
	 
	for(i = 2; i < n-1; i++) // ע������߽磬��֤���鲻Խ�� 
	{
		if (fabs(temperature[i] - temperature[i+1]) > undulation) 
			undulation = fabs(temperature[i] - temperature[i+1]);
	} 
	
	printf("%d\n",undulation); 
	return 0;
} 

