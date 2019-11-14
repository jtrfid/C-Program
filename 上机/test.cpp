#include<stdio.h>
#include<math.h>   // 数学库函数 
#include<string.h>

#define N 100
void sort(char name[][81],int n);
int main()
{
   char name[100][81]={"Zhang 3","Li 4","Wang 5"};
   int i=0,n=3;
   while(i<n)
{
  //gets(name[i]); // 输入n个字符串
  i++;
}
   sort(name,n);
   for(i=0;i<n;i++)
   {
   		puts(name[i]);
   }
   return 0;
}  

void sort(char name[][81],int n) //定义sort函数
{	
    char tmp[81];
	int i,j,k;
	for(i=0;i<n-1;i++)	//用选择法排序
	{	k=i;
		for(j=i+1;j<n;j++)
			if(strcmp(name[k],name[j])>0) k=j;
		if(k!=i)
		{	strcpy(tmp,name[i]); strcpy(name[i],name[k]); strcpy(name[k],tmp);}
	}
}
