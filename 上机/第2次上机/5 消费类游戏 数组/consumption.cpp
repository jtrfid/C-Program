#include <stdio.h>
#include <math.h>
#define M 30 
int main()
{
	int checker[M][M]={{2,2,3,1,2},
	                   {3,4,5,1,4},
					   {2,3,2,1,3},
					   {2,2,2,4,4}};
	int m=5,n=4,i,j,k; // n�У�m�� 
	int countCol,countRow; // ����
	int current; // ��ǰ������ 
	
	//scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++) // �� 
	{
		for(j=0;j<m;j++) // �� 
		{
		   if(checker[i][j]==0) continue; // �Ѿ��������� 
		   current=checker[i][j];
		   // ���currentͬ���� 
		   countRow=0;
		   for(k=0;k<m;k++) // �м�� 
		   {
		   	    if(k==j) continue; // �����ظ����� 
				if(checker[i][k]==current) countRow++;
		   }
		   // ���currentͬ���� 
		   countCol=0;
		   for(k=0;k<n;k++) // �м�� 
		   {
		   	    if(k==i) continue; // �����ظ����� 
				if(checker[k][j]==current) countCol++;
		   }
		   
		   if(countRow>=3) // �������currentͬ���� 
		   {
		   		for(k=0;k<m;k++) if(checker[i][k]==current) checker[i][k]=0;
		   } 
		   
		   if(countCol>=3) // �������currentͬ���� 
		   {
		   		for(k=0;k<n;k++) if(checker[k][j]==current) checker[k][j]=0;
		   } 
		}
	} 
	
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
