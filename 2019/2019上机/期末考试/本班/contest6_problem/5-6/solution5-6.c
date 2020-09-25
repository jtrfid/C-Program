#include <stdio.h>
#define N 101
typedef struct {
	int id;
	int score;
}InfoType; 

void sort(int a[],int n)
{
	int i,j;
	int tmp;
	
	for(i=0;i<n-1;i++)
	  for(j=0;j<n-1-i;j++)
	     if (a[j]>a[j+1]) {
	     	tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp; 
		 }
}

int main()
{
	  int i,n,k,cnt=0;
	  int rmax = 0;
	  int d[4];
	  InfoType player[N]; 
	  int winner[N];
	  
	 // freopen("in5.txt","r",stdin);
	//  freopen("out5.txt","w",stdout);
	   
	  scanf("%d",&n);
	  i=0; 
	  while(i<n) {
	  	  scanf("%d",&player[i].id);
	  	  for(k=0;k<4;k++) {
	  	  	  scanf("%d",&d[k]);
		  }
	  	  sort(d,4);
		  player[i].score = d[1] + d[2];
		  if (player[i].score>rmax) 
		     rmax = player[i].score;
		
		  i++;	 	   	  	
	  }
	  
	  for(i=0; i<n; i++) {
	  	 if (player[i].score==rmax) {	  	 	
	  	 	printf("%d\n",player[i].id);
		 }	  	     
	  } 
	      
	  return 0;   
}
