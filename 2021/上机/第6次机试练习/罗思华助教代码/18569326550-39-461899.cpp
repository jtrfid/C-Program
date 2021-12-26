#include <stdio.h>

int main() 
{
 int m, n, min = 9999, max = 0, line, hang, i, j, h,t = 0;
 int a[100][100];
 scanf("%d%d", &m, &n);
 for (i = 0; i < m; i++) 
 {
   for (j = 0; j < n; j++) 
   {
    scanf("%d", &a[i][j]);
   }
 }
 for (i = 0; i < m; i++) 
 {	
 	min = 9999;
	max=0; 
  	for (j = 0; j < n; j++) 
  	{
   		if (a[i][j] < min) 
   		{
    		min = a[i][j];
    		line = j;
   		}
  	}
  	for (h = 0; h < m; h++) 
  	{
   		if (a[h][line] > max) 
		{
    		max = a[h][line];
    		hang =  h;
   		}
  	}
  	if (max == min) 
	{
   		printf("%d %d %d\n", hang, line, min);
   		t = 1;
  	}
 }
 if (t == 0) 
  {
  printf("no");
 }
 return 0;
}
