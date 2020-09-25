 #include <stdio.h>
 // 最大行数或列数 
 #define N 20 
 void gridInit(int grid[][N], int n, int m);
 //int go(char command[], int *startRow, int *startCol, int grid[][N], int n, int m, int *steps);
 int go();
 char command[100];
 int startRow, startCol; // 开始行,列数索引 
 
 // 表示网格，初始化各元素为0,表示机器人未走过该网格，根据指令，填充网格元素为1，表示机器人已经走过该网格。
 // loop判断：0-1(loop_one)-1-1-...-1(loop_one)==>loop. 
 // out判断: 跳出数组上下左右边界 
 int grid[N][N];   

 int n, m, steps=1; // 实际的行数列数, 步数 
 int out=-1; // 0: loop; 1: out 
 
 int loop_FirstRow=-1, loop_FirstCol=-1; // loop的第一个网格
 int beforeSteps=0; // 进入loop之前的步数 
 
 int row,col; // 当前行列索引 
 
 int main()
 {
	int i=0;
	scanf("%d%d%d",&n,&m,&col);
	gets(command); // 消费回车键
	col--;
	row=0; 
	// 初始化grid
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
 
 // 初始化grid; n,m: 行数,列数 
 void gridInit(int grid[][N], int n, int m)
 {
 	int i,j;
 	for(i=0;i<n;i++)
 		for(j=0;j<m;j++)
 			grid[i][j]=0;
 } 
 
 // 按照指令行走, 
 // 返回0, 表示loop, 1表示out, -1表示正常行走 
 int go() 
 {
 	grid[row][col] = 1; // 开始网格置1 
 	char *p=command;
 	while(*p!='\0')
 	{
 		switch(*p) // 是否 go out 
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
		if(grid[row][col]==1) // 0->1: 可能进入循环 
		{
			if(loop_FirstRow==-1) 
			{ 
				loop_FirstRow=row; 
				loop_FirstCol=col; 
				beforeSteps=steps; 
			}
			else if(loop_FirstRow==row && loop_FirstCol==col) 
			{
				steps=beforeSteps; // 参数输出进入循环前的步数
				return 0; // loop 
			}
		}
		else // 有可能从loop跳出 
		{
			loop_FirstRow==-1;
		} 
		// 正常行走 
		grid[row][col]=1;
		steps++;
		p++;
	}
	return -1; 
 } 
