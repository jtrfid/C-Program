#include <stdio.h>
#include <math.h>

/***********************************************************
	������	88
	��������	��ĩ����2-��Ŀ4-��ͼ
	ʱ������:	1 ��
	�ڴ�����:	256MB
	��������	
	��������
	��һ��������ֱ������ϵ��ֽ�ϣ���һ��(x1,y1)��(x2,y2)�ľ��Σ�ָ�������귶Χ��x1��x2�������귶Χ��y1��y2֮�������Ϳ����ɫ�� 
	��ͼ������һ�������������ε����ӡ���һ��������(1,1) ��(4, 4)������ɫ����ɫ��ʾ���ڶ���������(2, 3)��(6, 5)������ɫ����ɫ��ʾ��ͼ�У�һ����15����λ�������Ϳ����ɫ��������ɫ���ֱ�Ϳ�����Σ����ڼ������ʱֻ����һ�Ρ���ʵ�ʵ�Ϳɫ�����У����еľ��� ��Ϳ��ͳһ����ɫ��ͼ����ʾ��ͬ��ɫ��Ϊ˵�����㡣��������Ҫ���ľ��Σ������ܹ��ж��ٸ���λ�������Ϳ����ɫ�� 
	
	����˵��
	����ĵ�һ�а���һ������n����ʾҪ���ľ��εĸ�����1<=n<=100 
	������n�У�ÿ��4���Ǹ��������ֱ��ʾҪ���ľ��ε����½ǵĺ������������꣬�Լ����Ͻǵĺ������������ꡣ0<=�����ꡢ������<=100�� 
	���˵��
	���һ����������ʾ�ж��ٸ���λ�������Ϳ����ɫ��
	��������
	2 
	1 1 4 4 
	2 3 6 5 
	�������
	15
	��ʾ��Ϣ
 ***********************************************************/
#define N 100
struct Rec
{
	int leftBottomX;
	int leftBottomY;
	int rightTopX;
	int rightTopY;
};

// ����������
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

// rec����, grid����Ԫ����1 
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

// largest����, grid����Ԫ�س�ʼ��Ϊ0 
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

// largest����, ����grid����Ԫ��Ϊ1�ĵ�Ԫ�������������ǵĵ�λ����� 
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
	grid0(largest,grid); // ��ʼ�� 
	for(i=0;i<n;i++)
	{
		grid1(recs[i],grid); // ��1 
	}
	printf("%d\n",gridNum(largest,grid)); // ͳ����� 
	return 0;
}

