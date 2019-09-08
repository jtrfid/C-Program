/*************************************************
 输入样例 
 4
 100 zhang 100 91 80
 101 wang 40 90 50
 102 li 101 90 80
 103 zhao 80 70 100
 *************************************************/ 
#include <stdio.h>
#define N 100                                   // 常数，估计最大学生数 
struct student                                  // 建立结构体类型struct student  
{
  int num;                                      // 学号  
  char name[20];                                // 姓名   
  float score[3];                               // 3门课成绩  
  float aver;                                   // 平均成绩  
};
 
void input(struct student stu[],int n);             // 函数声明  
int max(struct student stu[],struct student maxStu[], int n);    
void print(struct student stu);                     
void prints(struct student stu[],int n);            
void swap(struct student *stu1, struct student *stu2); 
void sort(struct student stu[],int n);
 
int main()
{   
  struct student stu[N],*p=stu;                 // 定义结构体数组和指针
  int n;                                        // 实际学生数
  int i,maxNum;  // 平均成绩最高者学生数 
  struct student maxStu[N];  
  
  scanf("%d",&n);  
  input(p,n);                                   // 调用input函数，同时计算平均值 
  
  printf("平均成绩最高者：\n"); 
  maxNum = max(stu,maxStu,n);   
  for(i = 0; i < maxNum; i++)  print(maxStu[i]);
                     
  printf("\n排序前：\n");
  prints(p,n);  
  printf("\n排序后：\n");
  sort(stu,n);
  prints(p,n);
  return 0;
}

// 在输入时，同时计算了平均值 
void input(struct student stu[],int n)   // 定义input 函数  
{
   int i;
   for(i=0;i<n;i++)
   {
   		scanf("%d%s%f%f%f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);   // 输入数据  
    	stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/n;                                  // 求各人平均成绩  
   }
}

// 平均成绩最高者，考虑最高者不仅一个，返回平均成绩最高者学生数 
int max(struct student stu[],struct student maxStu[], int n)    // 定义max 函数  
{
  //也可以先降序排序，然后取前几名平均成绩一样的最高者。
  // 这里，首先计算最大的平均成绩，然后再提取最大成绩一样的学生。 
  int i, m = 0, maxNum = 0;
  for(i = 0; i < n; i++)
  {
  	if (stu[i].aver>stu[m].aver) m=i;  
  } 
  for(i = 0; i < n; i++)
  {
  	if (stu[i].aver == stu[m].aver)
  	{
  		maxStu[maxNum++] = stu[i];
	}
  } 
  return maxNum; 
}

void print(struct student stud)                   // 定义print函数  
{ 
	printf("学号:%d\n姓名:%s\n三门课成绩:%5.1f,%5.1f,%5.1f\n平均成绩:%6.2f\n",stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);
}

void prints(struct student stu[],int n)           // 定义prints函数  
{ 
	int i;
	for(i = 0; i < n; i++)
	{
		print(stu[i]);
	}
}

// 交换两个学生顺序 
void swap(struct student *stu1, struct student *stu2)
{
	struct student tmp;
	tmp = *stu1; *stu1 = *stu2; *stu2 = tmp;
}

// 定义排序函数(选择法，降序): 按平均值排序，如果平均值相同，按照课程顺序依次比较单科成绩 
void sort(struct student stu[],int n)            
{
	int i,j,k;
	for(i = 0; i < n-1; i++)
	{
		k = i;
		for(j = i + 1; j < n; j++)
		{
			// 善用&& || 关系 
			if(stu[j].aver > stu[k].aver || 
			  (stu[j].aver == stu[k].aver && stu[j].score[0] > stu[k].score[0]) ||
			  (stu[j].aver == stu[k].aver && stu[j].score[1] > stu[k].score[1]) ||
			  (stu[j].aver == stu[k].aver && stu[j].score[2] > stu[k].score[2]))
			{
				k = j;
			} 
		}
		if(k != i) swap(&stu[i],&stu[k]); 
	} 
}
