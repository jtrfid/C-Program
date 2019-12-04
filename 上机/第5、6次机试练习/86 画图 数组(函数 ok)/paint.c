#include <stdio.h>
#include <math.h>

/***********************************************************
	试题编号	88
	试题名称	期末测试2-题目4-画图
	时间限制:	1 秒
	内存限制:	256MB
	问题描述	
	问题描述
	在一个定义了直角坐标系的纸上，画一个(x1,y1)到(x2,y2)的矩形，指将横坐标范围从x1到x2，纵坐标范围从y1到y2之间的区域涂上颜色。 
	下图给出了一个画了两个矩形的例子。第一个矩形是(1,1) 到(4, 4)，用绿色和紫色表示。第二个矩形是(2, 3)到(6, 5)，用蓝色和紫色表示。图中，一共有15个单位的面积被涂上颜色，其中紫色部分被涂了两次，但在计算面积时只计算一次。在实际的涂色过程中，所有的矩形 都涂成统一的颜色，图中显示不同颜色仅为说明方便。给出所有要画的矩形，请问总共有多少个单位的面积被涂上颜色。 
	
	输入说明
	输入的第一行包含一个整数n，表示要画的矩形的个数，1<=n<=100 
	接下来n行，每行4个非负整数，分别表示要画的矩形的左下角的横坐标与纵坐标，以及右上角的横坐标与纵坐标。0<=横坐标、纵坐标<=100。 
	输出说明
	输出一个整数，表示有多少个单位的面积被涂上颜色。
	输入样例
	2 
	1 1 4 4 
	2 3 6 5 
	输出样例
	15
	提示信息
 ***********************************************************/
#define N 100
struct Rec
{
	int leftBottomX;
	int leftBottomY;
	int rightTopX;
	int rightTopY;
};

// 返回最大矩形
struct Rec Largest(struct Rec res[], int n)
{
	struct Rec largest=res[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(res[i].leftBottomX < largest.leftBottomX) largest.leftBottomX=res[i].leftBottomX;
		if(res[i].leftBottomY < largest.leftBottomY) largest.leftBottomY=res[i].leftBottomY;
		if(res[i].rightTopX > largest.rightTopX) largest.rightTopX=res[i].rightTopX;
		if(res[i].rightTopY > largest.rightTopY) largest.rightTopY=res[i].rightTopY;
	}
	return largest; 
} 

// rec区域, grid数组元素置1 
void grid1(struct Rec rec, int grid[][N])
{
   	int i,j;
	for(i=rec.leftBottomY;i<rec.rightTopY;i++)
	{
		for(j=rec.leftBottomX;j<rec.rightTopX;j++)
		{
			grid[i][j]=1;
		}
	} 
}

// largest区域, grid数组元素初始化为0 
void grid0(struct Rec largest, int grid[][N])
{
   	int i,j;
	for(i=largest.leftBottomY;i<largest.rightTopY;i++)
	{
		for(j=largest.leftBottomX;j<largest.rightTopX;j++)
		{
			grid[i][j]=0;
		}
	} 
}

// largest区域, 返回grid数组元素为1的单元数量，即被覆盖的单位面积数 
int gridNum(struct Rec largest, int grid[][N])
{
   	int i,j,num=0;
	for(i=largest.leftBottomY;i<largest.rightTopY;i++)
	{
		for(j=largest.leftBottomX;j<largest.rightTopX;j++)
		{
			if(grid[i][j]) num++;
		}
	} 
	return num;
}

void print(struct Rec rec)
{
	printf("%d,%d,%d,%d\n",rec.leftBottomX,rec.leftBottomY,rec.rightTopX,rec.rightTopY);
} 
 
int main()
{
	int grid[N][N],n,i,num;
	struct Rec recs[N],largest;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&recs[i].leftBottomX,&recs[i].leftBottomY,&recs[i].rightTopX,&recs[i].rightTopY);
	}
	largest=Largest(recs,n); 
	//print(largest);
	grid0(largest,grid); // 初始化 
	for(i=0;i<n;i++)
	{
		grid1(recs[i],grid); // 置1 
	}
	printf("%d\n",gridNum(largest,grid)); // 统计输出 
	return 0;
}

