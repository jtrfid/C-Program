#include<stdio.h>
#include<math.h>   // 数学库函数        
int main()                   
{  
   int n=0; //计数 
   int a,b; // a,b 区间
   int i,t;   // 循环变量，代表a,b区间的每个数
   int sum; // i的各位立方和 
   scanf("%d%d",&a,&b);
   for(i=a;i<=b;i++) 
   { 
	  // 考察i是否水仙数 
	  sum = 0; t=i;
	  while(t!=0) // 累加各位立方 
	  {
	  	sum+=pow(t%10,3);
	  	t=t/10;
      }
      if(sum==i) n++; // i是水仙数 
   }
   printf("%d\n",n);
   return 0;           
}                   
