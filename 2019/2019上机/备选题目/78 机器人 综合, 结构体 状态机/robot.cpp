 #include <stdio.h>
 // ������������� 
 #define N 20 
 void gridInit(int grid[][N], int n, int m);
 //int go(char command[], int *startRow, int *startCol, int grid[][N], int n, int m, int *steps);
 int go();
 char command[100];
 int startRow, startCol; // ��ʼ��,�������� 
 
 // ��ʾ���񣬳�ʼ����Ԫ��Ϊ0,��ʾ������δ�߹������񣬸���ָ��������Ԫ��Ϊ1����ʾ�������Ѿ��߹�������
 // loop�жϣ�0-1(loop_one)-1-1-...-1(loop_one)==>loop. 
 // out�ж�: ���������������ұ߽� 
 int grid[N][N];   

 int n, m, steps=1; // ʵ�ʵ���������, ���� 
 int out=-1; // 0: loop; 1: out 
 
 int loop_FirstRow=-1, loop_FirstCol=-1; // loop�ĵ�һ������
 int beforeSteps=0; // ����loop֮ǰ�Ĳ��� 
 
 int row,col; // ��ǰ�������� 
 
 int main()
 {
	int i=0;
	scanf("%d%d%d",&n,&m,&col);
	gets(command); // ���ѻس���
	col--;
	row=0; 
	// ��ʼ��grid
	gridInit(grid,n,m); 
	// go
	for(i=0;i<n;i++)
	{
		gets(command);
		puts(command);
		out=go();
		if(out!=-1) break;  
    }
	if(out==1) printf("out %d\n",steps);
	else printf("loop %d\n",steps);
 	return 0;
 }
 
 // ��ʼ��grid; n,m: ����,���� 
 void gridInit(int grid[][N], int n, int m)
 {
 	int i,j;
 	for(i=0;i<n;i++)
 		for(j=0;j<m;j++)
 			grid[i][j]=0;
 } 
 
 // ����ָ������, 
 // ����0, ��ʾloop, 1��ʾout, -1��ʾ�������� 
 int go() 
 {
 	grid[row][col] = 1; // ��ʼ������1 
 	char *p=command;
 	while(*p!='\0')
 	{
 		switch(*p) // �Ƿ� go out 
 		{
 			case 'N': row--; 
			          if(row<0) return 1; // out 
					  break;
 			case 'S': row++; 
			          if(row>n-1) return 1; // out
					  break;
 			case 'E': col++; 
			          if(col>m-1) return 1; // out
					  break;
 			case 'W': col--; 
			          if(col<0) return 1; // out
					  break;
		}
		if(grid[row][col]==1) // 0->1: ���ܽ���ѭ�� 
		{
			if(loop_FirstRow==-1) 
			{ 
				loop_FirstRow=row; 
				loop_FirstCol=col; 
				beforeSteps=steps; 
			}
			else if(loop_FirstRow==row && loop_FirstCol==col) 
			{
				steps=beforeSteps; // �����������ѭ��ǰ�Ĳ���
				return 0; // loop 
			}
		}
		else // �п��ܴ�loop���� 
		{
			loop_FirstRow==-1;
		} 
		// �������� 
		grid[row][col]=1;
		steps++;
		p++;
	}
	return -1; 
 } 
