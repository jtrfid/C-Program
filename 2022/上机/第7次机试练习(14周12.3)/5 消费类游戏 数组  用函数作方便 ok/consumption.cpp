#include <stdio.h>
#include <math.h>
#define M 30 

/* ɨ����: ��һ����������������������ͬ��ɫ������ʱ����Щ���Ӷ���������
    checkerÿ���з���ɾ���������������Ӧ��F�����е�Ԫ����1. 
	checker����, F: ��־����, n: ����, m: ����
 ***********************************************/ 
void scanRow1(int checker[][M], int F[][M], int n, int m)
{
	int i,j; 
	for(i=0;i<n;i++) // ��ɨ�� 
	{
		for(j=1;j<m-1;j++) // �У�ע���±�  
		{
			// 3������ͬ����������ͬɫ����Fɾ����־ 
			if(checker[i][j-1] == checker[i][j] && checker[i][j] == checker[i][j+1]) 
			{
				F[i][j-1]=F[i][j]=F[i][j+1]=1;
			}
		}
	}	
}

/* ɨ����: ��һ����������������������ͬ��ɫ������ʱ����Щ���Ӷ���������
    checkerÿ���з���ɾ���������������Ӧ��F�����е�Ԫ����1. 
	checker����, F: ��־����, n: ����, m: ����
 ***********************************************/ 
void scanCol1(int checker[][M], int F[][M], int n, int m)
{
	int i,j; 
	for(j=0;j<m;j++) // ��ɨ�� 
	{
		for(i=1;i<n-1;i++) // �У�ע���±� 
		{
			// 3������ͬ����������ͬɫ����Fɾ����־ 
			if(checker[i-1][j] == checker[i][j] && checker[i][j] == checker[i+1][j]) 
			{
				F[i-1][j]=F[i][j]=F[i+1][j]=1;
			}
		}
	}		
}

/* ɨ����: ��һ����������������������ͬ��ɫ������ʱ����Щ���Ӷ���������
    checkerÿ���з���ɾ���������������Ӧ��F�����е�Ԫ����1. 
	checker����, F: ��־����, n: ����, m: ����
 ***********************************************/ 
void scanRow(int checker[][M], int F[][M], int n, int m)
{
	int i,j,k,last,count; // last��������������ɫ, count������ͬɫ���Ӹ��� 
	for(i=0;i<n;i++) // ��ɨ�� 
	{
		last=checker[i][0]; // ÿ���е�һ��Ԫ�س�ʼΪlast
		count=0; 
		for(j=1;j<m;j++) // �� 
		{
			if(last == checker[i][j]) count++;
			else // ��ͬɫ
			{
				if(count>=2) // ����ͬɫ���ӵ�ɾ����־ 
				{
					for(k=j-1;count>=0; k--,count--) F[i][k]=1; // ��ɾ����־ 
				}
				last=checker[i][j]; count=0;  
			} 
		}
		// ֱ�����һ�У���ͬɫ 
		if(count>=2) // ����ͬɫ���ӵ�ɾ����־ 
		{
			for(k=j-1;count>=0; k--,count--) F[i][k]=1; // ��ɾ����־ 
		} 
	}	
}

/* ɨ����: ��һ����������������������ͬ��ɫ������ʱ����Щ���Ӷ���������
    checkerÿ���з���ɾ���������������Ӧ��F�����е�Ԫ����1. 
	checker����, F: ��־����, n: ����, m: ����
 ***********************************************/ 
void scanCol(int checker[][M], int F[][M], int n, int m)
{
	int i,j,k,last,count; // last��������������ɫ, count������ͬɫ���Ӹ��� 
	for(j=0;j<m;j++) // ��ɨ�� 
	{
		last=checker[0][j]; // ÿ���е�һ��Ԫ�س�ʼΪlast
		count=0; 
		for(i=1;i<n;i++) // �� 
		{
			if(last == checker[i][j]) count++;
			else // ��ͬɫ
			{
				if(count>=2) // ����ͬɫ���ӵ�ɾ����־ 
				{
					for(k=i-1;count>=0; k--,count--) F[k][j]=1; // ��ɾ����־ 
				}
				last=checker[i][j]; count=0;  
			} 
		}
		// ֱ�����һ�У���ͬɫ 
		if(count>=2) // ����ͬɫ���ӵ�ɾ����־ 
		{
			for(k=i-1;count>=0; k--,count--) F[k][j]=1; // ��ɾ����־ 
		} 
	}	
}

// ������, n: ����, m: ����
void Read(int checker[][M],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&checker[i][j]);
		}
	}
}

// �������, n: ����, m: ����
void output(int checker[][M],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++) // �� 
	{
		for(j=0;j<m;j++) // �� 
		{
			printf("%d ",checker[i][j]); 
		}
		printf("\n");
	} 
}

// ������п�ɾ����Ԫ��, F: ɾ����־����, n: ����, m: ���� 
void del(int checker[][M], int F[][M],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(F[i][j]==1) checker[i][j]=0;
		}
	}
}

int main()
{
	// ���̣���ʼ����Ϊ�˱��ڲ��� 
	int checker[M][M]={{2,2,3,1,2},
	                   {3,4,5,1,4},
					   {2,3,2,1,3},
					   {2,2,2,4,4}};
	int n=4,m=5,i,j; // n�У�m�� 
	/************
    int checker[M][M]={{2,2,3,1,2},
	                   {3,1,1,1,1},
					   {2,3,2,1,3},
					   {2,2,3,3,3}};
	int n=4,m=5,i,j; // n�У�m�� 
	*************/
	// ��־���� 
    int F[M][M]; // ��ӦԪ��Ϊ1,���ʾɾ�� 
	
	//scanf("%d%d",&n,&m);
	// ������ 
	//Read(checker,n,m);
	
	// ��ʼ��F 
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	    F[i][j]=0;
		 
	// ɨ���� 
	scanRow(checker, F, n, m);
	
	// ɨ���� 
	scanCol(checker, F, n, m);
	
	// ����F   
	//output(F,n,m);
	
	// ��� 
	del(checker, F, n, m);
	 
	// ������� 
	output(checker,n,m);
	
	return 0;
} 
