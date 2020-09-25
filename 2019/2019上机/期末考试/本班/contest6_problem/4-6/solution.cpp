#include<stdio.h>

int main()
{
    int a[60][60],b[60],c[60];
    int m,n,i,j,sum=0;
    
  
	
      scanf("%d %d", &m, &n);
	  for(i=0;i<m;i++){
		for (j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
		}
	  }


   
	for(i=0;i<m;i++)
    for(j=0;j<n;j++)
        if(a[i][j]==0)
        {
            b[i]=1;
            c[j]=1;
        }


	for(i=0;i<m;i++)
    for(j=0;j<n;j++)
        if(b[i]==1||c[j]==1)
            a[i][j]=0;
	

		
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    
	
	return 0;
}
