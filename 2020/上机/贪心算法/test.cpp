/************************************************************************
最大子序和
给定一个整数数组nums，找到一个具有最大和的连续子数组(子数组最少包含一个元素)，返回其最大和。
示例：
输入: [-2,1,-3,4,-1,2,1,-5,4] 
输出: 6
解释: 连续子数组[4,-1,2,1]的和最大, 为6. 
 ************************************************************************/
 
 #include <stdio.h>
 
 // 暴力求解,时间复杂度: O(n^2), 空间复杂度: O(1) 
 int main1()
 {
 	int nums[100]={-2,1,-3,4,-1,2,1,-5,4},n=9; 
 	int result=nums[0],count,i,j, start=0,end=0;
 	// 从i开始，到j累加count: nums[i] + num[i+1] + ... + num[j]
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
 
 // 贪心算法,时间复杂度: O(n^2), 空间复杂度: O(1)
 // 局部最优: 当count累加为负数时，即放弃本轮的累加，调整区间起始位置，开始下一轮迭代。 
 // 因为继续累加只能使count累加变小。 
 int main2()
 {
 	int nums[100]={-2,1,-3,4,-1,2,1,-5,4},n=9; 
 	int result=nums[0],count,i,j, start=0,end=0;
 	// nums[i] + num[i+1] + ... + num[j]
	for(i=0;i<n;i++)
	{
		count=nums[i];
		if (count<0) continue; // 继续下轮迭代 -->调整区间开始位置 
		for(j=i+1;j<n;j++)
		{
			count += nums[j];
			if (count<0) break; // 没有必要计算了 
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
 
 // 优化贪心算法,时间复杂度: O(n), 空间复杂度: O(1)
 // 局部最优: 当nums[i]<0为负数时，即放弃本轮的累加，调整区间起始位置，开始下一轮迭代。 
 // 因为继续累加只能使count累加变小。 
 int main()
 {
 	int nums[100]={-2,1,-3,4,-1,2,1,-5,4},n=9; 
 	int result=nums[0],count=0,i, start=0,end=0;
 	// nums[i] + num[i+1] + ... + num[j]
	for(i=0;i<n;i++)
	{
		count += nums[i];
		if (count<0) // 继续下轮迭代 -->调整区间开始位置
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
