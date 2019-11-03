#include <stdio.h>
#include <math.h>
#define M 30 

// ɨ��curRow���п�ɾ����Ԫ��, F: ɾ����־����, m: ���� 
void delRow(int curRow, int checker[][M], int F[][M],int m)
{
	int i,j, current,count;
	for(i=0;i<m;i++) 
	{
		// if(F[curRow][i]==1) continue; // �����ɨ���У���Ͳ������� 
		count=1; 
		current=checker[curRow][i];
		for(j=i+1;j<m;j++)
		{
			if(current==checker[curRow][j]) count++;
			else break;
		}
		if(count>=3)
		{
			for(j=i;j<m;j++)
			{
				if(checker[curRow][j]==current) F[curRow][j]=1; // ��ɾ����־
				else break; 
			}
		}
	} 
}

// ɨ��curCol���п�ɾ����Ԫ��, F: ɾ����־����, n: ���� 
void delCol(int curCol, int checker[][M], int F[][M],int n)
{
	int i,j, current,count;
	for(i=0;i<n;i++) 
	{
		count=1; 
		current=checker[i][curCol];
		for(j=i+1;j<n;j++)
		{
			if(current==checker[j][curCol]) count++;
			else break;
		}
		if(count>=3)
		{
			for(j=i;j<n;j++)
			{
				if(checker[j][curCol]==current) F[j][curCol]=1; // ��ɾ����־
				else break; 
			}
		}
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
	//**********
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
	
    int F[M][M]; // ��ӦԪ��Ϊ1,���ʾɾ�� 
	
	//scanf("%d%d",&n,&m);
	
	// ��ʼ��F 
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	    F[i][j]=0;
		 
	// ɨ���� 
	for(i=0;i<n;i++) // �� 
	   delRow(i, checker, F, m);
	
	// ɨ���� 
	for(j=0;j<m;j++) // �� 
	   delCol(j, checker, F, n);
	   
	// ��� 
	del(checker, F, n, m);
	 
	// ������� 
	for(i=0;i<n;i++) // �� 
	{
		for(j=0;j<m;j++) // �� 
		{
			printf("%d ",checker[i][j]); 
		}
		printf("\n");
	} 
	return 0;
} 
