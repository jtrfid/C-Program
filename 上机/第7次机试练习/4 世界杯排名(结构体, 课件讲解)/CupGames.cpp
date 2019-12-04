/************************************************************************
试题编号	4
试题名称	世界杯排名
时间限制:	1 秒
内存限制:	256MB
问题描述	
问题描述
给出世界杯一个小组的小组赛成绩，请找出最终进入淘汰赛的球队。 
小组赛积分规则：胜一场积3分、平一场积1分、负一场积0分。 
小组赛排名规则如下： 
1.首先按照积分排名，积分越高，排名越高 
2.积分相同的队按照净胜球（进球数减去失球数）排名，净胜球越多，排名越高 
输入说明
输入数据第一行为两个整数N和M，N表示小组中队伍数量(N<=32)，M表示出线名额(M<=16)。
接下来是N行数据，每一行表示一只队伍的小组赛比赛信息，
依次为队名(长度不超过20的字符串)、胜场数、平局数、负场数、进球数、失球数。
输入数据保证没有两个球队的积分和净胜球完全相同。
输出说明
根据题目给出的积分排名规则，按照排名从高到低顺序依次输出出线球队的排名（从1开始排名）、队名、积分和净胜球，
各个字段之间用空格分隔。
输入样例
4 2 
Germany 2	1	0	7	2 
Portuguesa 1	1	1	4	7 
America 1	1	1	4	4 
Ghana 0	1	2	4	6 
输出样例
1 Germany	7 5 
2 America 4 0 
提示信息
 ************************************************************************/
 // 思路：定义结构体类型和结构体数组，对结构体数组进行排序。 
  
 #include <stdio.h>
 // 估计最大数 
 #define N 32
 #define M 16
 
 // 定义结构体类型，存储球队相关信息 
 struct team
 {
 	char name[20];
 	int win,draw,lose; // 胜，平，负场数 
	int goalsNum,losesNum; // 进球数，失球数
	int grades; // 积分
	int goals;  // 净胜球  
 };
 
 // 交换两个结构体对象 
 void swap(struct team *p1, struct team *p2)
 {
 	struct team temp;
 	temp = *p1; *p1 = *p2; *p2 = temp;
 }
 
 /** 
  选择法排序（降序）
  1.首先按照积分排名，积分越高，排名越高 
  2.积分相同的队按照净胜球（进球数减去失球数）排名，净胜球越多，排名越高 
  **/ 
 void sorts(struct team a[], int n)
 {
 	int i,j,k;
 	for(i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i+1; j < n; j++)
		{
			// 条件判断语句：善用&&、||运算，简化if else结构 
			if (a[j].grades > a[k].grades || (a[j].grades == a[k].grades &&  a[j].goals > a[k].goals ))  
				k = j;
		}
		if (k != i) swap(&a[i],&a[k]);
	} 
 }
 
 int main()
 {
 	struct team teams[N]; // 以估计最大数，定义结构体数组 
	int n,m,i;
 	scanf("%d%d",&n,&m);
 	// 填充结构体成员 
 	for(i = 0; i < n; i++)
 	{
		scanf("%s%d%d%d%d%d",teams[i].name,&teams[i].win,&teams[i].draw,&teams[i].lose,
		     &teams[i].goalsNum,&teams[i].losesNum);
		teams[i].grades =  teams[i].win*3 + teams[i].draw*1;
		teams[i].goals = teams[i].goalsNum - teams[i].losesNum; 
	}
	// 排序 
 	sorts(teams,n);
 	// 输出前m个排序后的球队 
 	for(i = 0; i < m; i++)
 		printf("%d %s %d %d\n",i+1,teams[i].name,teams[i].grades,teams[i].goals);
 		
 	return 0;
 }
