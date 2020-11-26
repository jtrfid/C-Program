/************************************************************************
��������
����һ����������nums���ҵ�һ���������͵�����������(���������ٰ���һ��Ԫ��)�����������͡�
ʾ����
����: [-2,1,-3,4,-1,2,1,-5,4] 
���: 6
����: ����������[4,-1,2,1]�ĺ����, Ϊ6. 
 ************************************************************************/
 
 #include <stdio.h>
 
 // �������,ʱ�临�Ӷ�: O(n^2), �ռ临�Ӷ�: O(1) 
 int main1()
 {
 	int nums[100]={-2,1,-3,4,-1,2,1,-5,4},n=9; 
 	int result=nums[0],count,i,j, start=0,end=0;
 	// ��i��ʼ����j�ۼ�count: nums[i] + num[i+1] + ... + num[j]
	for(i=0;i<n;i++)
	{
		count=nums[i];  
		for(j=i+1;j<n;j++)
		{
			count += nums[j];
			if (count>result) 
			{
				result=count;
				start=i; end=j;
			}
		}
	}
	for(i=start;i<=end;i++) printf("%d ",nums[i]);
	
	printf("\n%d\n",result);	
 	return 0;
 }
 
 // ̰���㷨,ʱ�临�Ӷ�: O(n^2), �ռ临�Ӷ�: O(1)
 // �ֲ�����: ��count�ۼ�Ϊ����ʱ�����������ֵ��ۼӣ�����������ʼλ�ã���ʼ��һ�ֵ����� 
 // ��Ϊ�����ۼ�ֻ��ʹcount�ۼӱ�С�� 
 int main2()
 {
 	int nums[100]={-2,1,-3,4,-1,2,1,-5,4},n=9; 
 	int result=nums[0],count,i,j, start=0,end=0;
 	// nums[i] + num[i+1] + ... + num[j]
	for(i=0;i<n;i++)
	{
		count=nums[i];
		if (count<0) continue; // �������ֵ��� -->�������俪ʼλ�� 
		for(j=i+1;j<n;j++)
		{
			count += nums[j];
			if (count<0) break; // û�б�Ҫ������ 
			if (count>result) 
			{
				result=count;
				start=i; end=j;
			}
		}
	}
	
	for(i=start;i<=end;i++) printf("%d ",nums[i]);
	
	printf("\n%d\n",result);	
 	return 0;
 }
 
 // �Ż�̰���㷨,ʱ�临�Ӷ�: O(n), �ռ临�Ӷ�: O(1)
 // �ֲ�����: ��nums[i]<0Ϊ����ʱ�����������ֵ��ۼӣ�����������ʼλ�ã���ʼ��һ�ֵ����� 
 // ��Ϊ�����ۼ�ֻ��ʹcount�ۼӱ�С�� 
 int main()
 {
 	int nums[100]={-2,1,-3,4,-1,2,1,-5,4},n=9; 
 	int result=nums[0],count=0,i, start=0,end=0;
 	// nums[i] + num[i+1] + ... + num[j]
	for(i=0;i<n;i++)
	{
		count += nums[i];
		if (count<0) // �������ֵ��� -->�������俪ʼλ��
		{
			count =0; 
			if(i<n-1)start=i+1;
			else start=n-1; 
			continue; 
		}  
		else if (count>result) 
		{
				result=count;
				end=i;
		}
	}
	
	for(i=start;i<=end;i++) printf("%d ",nums[i]);
	
	printf("\n%d\n",result);	
 	return 0;
 }
