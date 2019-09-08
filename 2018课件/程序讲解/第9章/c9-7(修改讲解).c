/*************************************************
 �������� 
 4
 100 zhang 100 91 80
 101 wang 40 90 50
 102 li 101 90 80
 103 zhao 80 70 100
 *************************************************/ 
#include <stdio.h>
#define N 100                                   // �������������ѧ���� 
struct student                                  // �����ṹ������struct student  
{
  int num;                                      // ѧ��  
  char name[20];                                // ����   
  float score[3];                               // 3�ſγɼ�  
  float aver;                                   // ƽ���ɼ�  
};
 
void input(struct student stu[],int n);             // ��������  
int max(struct student stu[],struct student maxStu[], int n);    
void print(struct student stu);                     
void prints(struct student stu[],int n);            
void swap(struct student *stu1, struct student *stu2); 
void sort(struct student stu[],int n);
 
int main()
{   
  struct student stu[N],*p=stu;                 // ����ṹ�������ָ��
  int n;                                        // ʵ��ѧ����
  int i,maxNum;  // ƽ���ɼ������ѧ���� 
  struct student maxStu[N];  
  
  scanf("%d",&n);  
  input(p,n);                                   // ����input������ͬʱ����ƽ��ֵ 
  
  printf("ƽ���ɼ�����ߣ�\n"); 
  maxNum = max(stu,maxStu,n);   
  for(i = 0; i < maxNum; i++)  print(maxStu[i]);
                     
  printf("\n����ǰ��\n");
  prints(p,n);  
  printf("\n�����\n");
  sort(stu,n);
  prints(p,n);
  return 0;
}

// ������ʱ��ͬʱ������ƽ��ֵ 
void input(struct student stu[],int n)   // ����input ����  
{
   int i;
   for(i=0;i<n;i++)
   {
   		scanf("%d%s%f%f%f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);   // ��������  
    	stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/n;                                  // �����ƽ���ɼ�  
   }
}

// ƽ���ɼ�����ߣ���������߲���һ��������ƽ���ɼ������ѧ���� 
int max(struct student stu[],struct student maxStu[], int n)    // ����max ����  
{
  //Ҳ�����Ƚ�������Ȼ��ȡǰ����ƽ���ɼ�һ��������ߡ�
  // ������ȼ�������ƽ���ɼ���Ȼ������ȡ���ɼ�һ����ѧ���� 
  int i, m = 0, maxNum = 0;
  for(i = 0; i < n; i++)
  {
  	if (stu[i].aver>stu[m].aver) m=i;  
  } 
  for(i = 0; i < n; i++)
  {
  	if (stu[i].aver == stu[m].aver)
  	{
  		maxStu[maxNum++] = stu[i];
	}
  } 
  return maxNum; 
}

void print(struct student stud)                   // ����print����  
{ 
	printf("ѧ��:%d\n����:%s\n���ſγɼ�:%5.1f,%5.1f,%5.1f\nƽ���ɼ�:%6.2f\n",stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);
}

void prints(struct student stu[],int n)           // ����prints����  
{ 
	int i;
	for(i = 0; i < n; i++)
	{
		print(stu[i]);
	}
}

// ��������ѧ��˳�� 
void swap(struct student *stu1, struct student *stu2)
{
	struct student tmp;
	tmp = *stu1; *stu1 = *stu2; *stu2 = tmp;
}

// ����������(ѡ�񷨣�����): ��ƽ��ֵ�������ƽ��ֵ��ͬ�����տγ�˳�����αȽϵ��Ƴɼ� 
void sort(struct student stu[],int n)            
{
	int i,j,k;
	for(i = 0; i < n-1; i++)
	{
		k = i;
		for(j = i + 1; j < n; j++)
		{
			// ����&& || ��ϵ 
			if(stu[j].aver > stu[k].aver || 
			  (stu[j].aver == stu[k].aver && stu[j].score[0] > stu[k].score[0]) ||
			  (stu[j].aver == stu[k].aver && stu[j].score[1] > stu[k].score[1]) ||
			  (stu[j].aver == stu[k].aver && stu[j].score[2] > stu[k].score[2]))
			{
				k = j;
			} 
		}
		if(k != i) swap(&stu[i],&stu[k]); 
	} 
}
