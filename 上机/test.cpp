#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 
#include<string.h>

#define N 100
void sort(char name[][81],int n);
int main()
{
   char name[100][81]={"Zhang 3","Li 4","Wang 5"};
   int i=0,n=3;
   while(i<n)
{
  //gets(name[i]); // ����n���ַ���
  i++;
}
   sort(name,n);
   for(i=0;i<n;i++)
   {
   		puts(name[i]);
   }
   return 0;
}  

void sort(char name[][81],int n) //����sort����
{	
    char tmp[81];
	int i,j,k;
	for(i=0;i<n-1;i++)	//��ѡ������
	{	k=i;
		for(j=i+1;j<n;j++)
			if(strcmp(name[k],name[j])>0) k=j;
		if(k!=i)
		{	strcpy(tmp,name[i]); strcpy(name[i],name[k]); strcpy(name[k],tmp);}
	}
}
