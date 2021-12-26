/************************************************************************
试题编号	58
试题名称	单元测试2-题目4-复试筛选
时间限制:	1 秒
内存限制:	256MB
问题描述	
问题描述
考研初试成绩公布后需要对m个学生的成绩进行排序，筛选出可以进入复试的前n名学生。
排序规则为首先按照总分排序，总分相同则按英语单科成绩排序。现给出这m个学生的考研初试成绩，
请筛选出可以进入复试的n名学生并按照排名从高到低的顺序依次输出。
输入说明
输入为m+1行，第一行为两个整数m和n，分别表示总人数和可以进入复试人数，m和n之间用空格分隔，0<n<m<200。接下来为m行数据，每行包括三项信息，分别表示一个学生的考号（字符串）、总成绩（整数）和英语单科成绩（整数），这三项之间用空格分隔。
输出说明
按排名从高到低的顺序输出进入复试的这n名学生的信息。
输入样例
5 3 
XD20160001 330 65 
XD20160002 330 70 
XD20160003 340 60 
XD20160004 310 80 
XD20160005 360 75 
输出样例
XD20160005 360 75 
XD20160003 340 60 
XD20160002 330 70 
提示信息
 ************************************************************************/
 // 思路：定义结构体类型和结构体数组，对结构体数组进行排序。 
 
 #include <stdio.h>
 #include <string.h>
  
 // 估计结构体数组最大长度 
 #define N 200
 
 struct Student 
 {
 	char no[20];   // 考号 
	int  total;    // 总成绩 
	int  english;  // 英语成绩  
 };
 
 // 输入m个考生信息
void input(struct Student *stus, int m)
{
  int i;
  for(i=0;i<m;i++) 
    scanf("%s%d%d",
      stus[i].no,&stus[i].total,&stus[i].english); 
}

// 输入n个考生信息
void print(struct Student *stus, int n)
{
  int i;
  for(i=0;i<n;i++) 
    printf("%s %d %d\n",
      stus[i].no,stus[i].total,stus[i].english); 
}
 
 // 交换两个结构体对象 
 void swap(struct Student *p1, struct Student *p2)
 {
 	struct Student temp;
 	temp = *p1; *p1 = *p2; *p2 = temp;
 }
 
 /** 
  选择法排序（降序）
  排序规则为首先按照总分排序，总分相同则按英语单科成绩排序
  **/ 
 void sorts(struct Student a[], int n)
 {
 	int i,j,k;
 	for(i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i+1; j < n; j++)
		{
			// 条件判断语句：善用&&、||运算，简化if else结构 
			if (a[j].total>a[k].total || (a[j].total==a[k].total &&  a[j].english>a[k].english)
			    || (a[j].total==a[k].total &&  a[j].english==a[k].english && strcmp(a[j].no,a[k].no)<0))  
				k = j;
		}
		if (k != i) swap(&a[i],&a[k]);
	} 
 }
 
 int main()
 {
 	struct Student stus[N]; 
	int m,n,i;
 	scanf("%d%d",&m,&n);
 	input(stus,m); 
 	sorts(stus,m);
 	print(stus,n);
 	return 0;
 }
