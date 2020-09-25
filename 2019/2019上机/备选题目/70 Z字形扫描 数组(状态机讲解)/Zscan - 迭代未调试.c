#include <stdio.h>
// ȥ����ע������� assert()
// #define NDEBUG
#include <assert.h>

/***********************************************************
	������	66
	��������	��ĩ����2-��Ŀ3-Z����ɨ��
	ʱ������:	1 ��
	�ڴ�����:	256MB
	��������	
	��������
	��ͼ�������㷨�У���Ҫ��һ�������ķ��ξ������Z����ɨ��(Zigzag Scan)������һ��n��n�ľ���Z����ɨ��Ĺ�������ͼ��ʾ�� 
	�������������4��4�ľ��� 
	����1 5 3 9 
	����3 7 5 6 
	����9 4 6 4 
	����7 3 1 3 
	�����������Z����ɨ���õ�����Ϊ16�����У� 
	����1 5 3 9 7 3 9 5 4 7 3 6 6 4 1 3 
	������ʵ��һ��Z����ɨ��ĳ��򣬸���һ��n��n�ľ������������������Z����ɨ��Ľ���� 
	
	����˵��
	����ĵ�һ�а���һ������n����ʾ����Ĵ�С�� 
	��������ĵڶ��е���n+1��ÿ�а���n�����������ɿո�ָ�����ʾ�����ľ��� 
	1��n��100������Ԫ��Ϊ������1000�������� 
	���˵��
	���һ�У�����n��n���������ɿո�ָ�����ʾ����ľ��󾭹�Z����ɨ���Ľ����
	��������
	4 
	1 5 3 9 
	3 7 5 6 
	9 4 6 4 
	7 3 1 3 
	�������
	1 5 3 9 7 3 9 5 4 7 3 6 6 4 1 3
	��ʾ��Ϣ
 ***********************************************************/

// ˼·: ������һ���ĵ�Ԫ��ȷ����һ����Ŀ�굥Ԫ�񡣵����ľ��衣 
 
#define N 100;

// �������� 
void go1(int a[][N],int n)
{
	int lastRow=0, lastCol=0, up;
	while(1)
	{
		if(lastRow==0) // ������
		{
			// ����index��, to leftDown 
			if(lastCol%2) { lastRow--; lastCol++; up=0;} 
			//ż��index��
			else if(lastCol==n-1) lastRow++; // ���Ͻ�, to down
			else lastCol++; // to right 
		} 
		else if(lastCol==0) // ������
		{
			// ������
			if(lastRow%2)
			{
				if(lastRow==n-1) { lastRow--;lastCol++; up=1; }   // ���½�, to right up 
				else lastRow++; // to down
			}
			// ż����
			else
			{
				// to right 
			} 
		} 
    } 
}

void go(int a[][N],int n)
{
	int lastRow=0, lastCol=0, up;
	while(1)
	{   
	    printf("%d ",a[lastRow][lastCol]);
	    if(n==1) break;
		if(lastRow==0 && lastCol==0) lastCol++;
		else if(n%2) // �������� 
		{
			
		} 
		else // ż������ 
		{
		} 
	} 
}

void go1(int a[][N],int n)
{
	int lastRow=0, lastCol=0;
	while(1)
	{
		printf("%d ",a[lastRow][lastCol]);
		if(lastRow==0 && lastCol==n-1) // ���Ͻ�
		{
			if(n%2) lastRow++;              // ����, ��ֱ�� 
			else  { lastRow++; lastCol--; }	// ż��, ���� 
		} 
		else if(lastRow==n-1 && lastCol==0) // ���½�
		{
			if(n%2) { lastRow++; lastCol++; }  // ���������� 
			else  lastCol--; 	               // ż��, ˮƽ�� 
		} 
		// ����, ������ 
		else if(lastRow==0)
		{
			if(lastCol%2) { lastRow++; lastCol--; } // ����, ���� 
			else lastCol++;                         // ż��, ˮƽ�� 
		}
		// ����, ������ 
		else if(lastCol==0)
		{
			if(lastRow%2) lastRow++;       // ����, ��ֱ�� 
			else { lastRow--; lastCol++; } // ż��, ����  
		} 
		// ����, ������ 
		else if(lastRow==n-1)
		{
			if(last%2) lastRow++; // to down 
			else { lastRow--; lastCol--; } // to rightUp
		} 
		// ������ 
	} 
}

int main()
{
	int a[N][N]= { {1,5,3,9},{3,7,5,6},{9,4,6,4},{7,3,1,3} },n=4,i,j;
	/***
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    scanf("%d",&a[i][j]); ***/
	go(a,n);    
	return 0;
}
 
int main1()
{
	int n, a[100][100];
	//int n = 4, a[4][4] = { {1,5,3,9},{3,7,5,6},{9,4,6,4},{7,3,1,3} };
	
	// Finite State Machine
	// last,next = 1,ˮƽ(��-->��)��2��ֱ(��-->��)��3б��(����-->����)��4б��(����-->����)
	int i = 0, j = 0, last = 1, next = 1;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d",&a[i][j]);
	
	i = 0; j = 0; 
	printf("%d ", a[i][j]);
	while (1)
	{
		if (i == n - 1 && j == n - 1) break;
		last = next;
		switch (last)
		{
		case 1: // ˮƽ 
			j++;
			if (i == 0) next = 3; // תб�� 
			else if (i == n - 1) next = 4; // תб�� 
			break;
		case 2: // ��ֱ 
			i++;
			if (j == 0) next = 4; // תб�� 
			else if (j == n - 1) next = 3; // תб�� 
			break;
		case 3: // б�� 
			i++; j--;
			if (i > n - 1) i = n - 1;
			if (j < 0) j = 0;

			if (j == 0)
			{
				if (i == n - 1) next = 1; // תˮƽ 
				if (i < n - 1) next = 2; // ת��ֱ
			}
			else if (i == n - 1) next = 1; // תˮƽ 
			break;
		case 4:	// б�� 
			i--; j++;
			if (i < 0) i = 0;
			if (j > n - 1) j = n - 1;
			if (i == 0)
			{
				if (j == n - 1) next = 2; // ת��ֱ 
				if (j < n - 1) next = 1; // תˮƽ	
			}
			else if(j == n-1) next = 2; // ת��ֱ 
			break;
		}
		printf("%d ", a[i][j]);  // ���last״̬�µ�a[i][j] 
	}

	return 0;
}

int main2()
{
	//int n, a[100][100];
	int n = 4, a[4][4] = { {1,5,3,9},{3,7,5,6},{9,4,6,4},{7,3,1,3} };
	
	// Finite State Machine
	// last,next = 1,ˮƽ(��-->��)��2��ֱ(��-->��)��3б��(����-->����)��4б��(����-->����)
	int i = 0, j = 0, last = 1, next = 1; 
	printf("%d ", a[0][0]);
	while (1)
	{
		if (i == n - 1 && j == n - 1) break;
		last = next;
		switch (last)
		{
		case 1: // ˮƽ 
			assert(i == 0 || i == n - 1);
			assert(j < n - 1);
			j++;
			if (i == 0) next = 3; // תб�� 
			else if (i == n - 1) next = 4; // תб�� 
			break;
		case 2: // ��ֱ 
			assert(j == 0 || j == n - 1);
			assert(i < n - 1);
			i++;
			if (j == 0) next = 4; // תб�� 
			else if (j == n - 1) next = 3; // תб�� 
			break;
		case 3: // б�� 
			i++; j--;
			if (i > n - 1) i = n - 1;
			if (j < 0) j = 0;

			if (j == 0)
			{
				if (i == n - 1) next = 1; // תˮƽ 
				if (i < n - 1) next = 2; // ת��ֱ
			}
			else if (i == n - 1) next = 1; // תˮƽ 
			break;
		case 4:	// б�� 
			i--; j++;
			if (i < 0) i = 0;
			if (j > n - 1) j = n - 1;
			if (i == 0)
			{
				if (j == n - 1) next = 2; // ת��ֱ 
				if (j < n - 1) next = 1; // תˮƽ	
			}
			else if(j == n-1) next = 2; // ת��ֱ 
			break;
		}
		printf("%d ", a[i][j]);  // ���last״̬�µ�a[i][j] 
	}

	return 0;
}


