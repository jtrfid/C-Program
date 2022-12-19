// 请大家准备好 Dev C++, 本节课大家一起同步敲代码。 
#include<stdio.h>  // 标准输入输出头文件 
#include<math.h>   // 数学库函数头文件
#include<string.h> // 字符串处理头文件 

struct Student
{
	int num;
	char name[20];
	float score[5];
	float aver; 
};

// 计算平均成绩，并返回平均成绩最高者(假定是唯一的) 
struct Student input(struct Student stu[],int n)
//void input(struct Student *stu,int n)  
{
	int i,j, maxIndex=0; 
	float sum; 
	for(i=0;i<n;i++)
	{
		scanf("%d%s",&(stu[i].num),stu[i].name); 
		sum = 0;
		for(j=0;j<5;j++) 
		{
			scanf("%f",&(stu[i].score[j]));
			sum=sum+stu[i].score[j];
		}
		stu[i].aver=sum/5.0;
		if (stu[i].aver > stu[maxIndex].aver) maxIndex=i;
	}
	return stu[maxIndex];
}

// 地址传递 
void print(struct Student stu[],int n)
//void print(struct Student *stu,int n)
{
	int i,j; 
	for(i=0;i<n;i++)
	{
		printf("%d %s",stu[i].num,stu[i].name);
		for(j=0;j<5;j++) 
		{
			printf(" %f",stu[i].score[j]);
		}
		printf(" %.2f\n",stu[i].aver);
	}
}

// 冒泡, 选择法， 
// 规则: 按平均成绩排序，如果相同，则按照前两门课比较单科成绩。 
void sort(struct Student stu[],int n) 
{
	
}

int main()                   
{  
	struct Student stu[100], maxstu; // 结构体数组 
	maxstu=input(stu,2);
	print(stu,2); // 地址传递 
	print(&maxstu,1); // 输出平均成绩最大者 
	
   	return 0;           
}              

int main1()                   
{  
	int i;
	struct Student stu; // 结构体类型变量
	
	scanf("%d%s",&stu.num,stu.name); 
	// scanf("%d%s",&(stu.num),stu.name); 
	for(i=0;i<5;i++) scanf("%f",&stu.score[i]);
	//for(i=0;i<5;i++) scanf("%f",&(stu.score[i]));
	
	printf("%d %s",stu.num,stu.name);
	for(i=0;i<5;i++) printf(" %f",stu.score[i]);
	
   	return 0;           
}                                  

