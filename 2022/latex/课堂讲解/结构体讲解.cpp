// ����׼���� Dev C++, ���ڿδ��һ��ͬ���ô��롣 
#include<stdio.h>  // ��׼�������ͷ�ļ� 
#include<math.h>   // ��ѧ�⺯��ͷ�ļ�
#include<string.h> // �ַ�������ͷ�ļ� 

struct Student
{
	int num;
	char name[20];
	float score[5];
	float aver; 
};

// ����ƽ���ɼ���������ƽ���ɼ������(�ٶ���Ψһ��) 
struct Student input(struct Student stu[],int n)
//void input(struct Student *stu,int n)  
{
	int i,j, maxIndex=0; 
	float sum; 
	for(i=0;i<n;i++)
	{
		scanf("%d%s",&(stu[i].num),stu[i].name); 
		sum = 0;
		for(j=0;j<5;j++) 
		{
			scanf("%f",&(stu[i].score[j]));
			sum=sum+stu[i].score[j];
		}
		stu[i].aver=sum/5.0;
		if (stu[i].aver > stu[maxIndex].aver) maxIndex=i;
	}
	return stu[maxIndex];
}

// ��ַ���� 
void print(struct Student stu[],int n)
//void print(struct Student *stu,int n)
{
	int i,j; 
	for(i=0;i<n;i++)
	{
		printf("%d %s",stu[i].num,stu[i].name);
		for(j=0;j<5;j++) 
		{
			printf(" %f",stu[i].score[j]);
		}
		printf(" %.2f\n",stu[i].aver);
	}
}

// ð��, ѡ�񷨣� 
// ����: ��ƽ���ɼ����������ͬ������ǰ���ſαȽϵ��Ƴɼ��� 
void sort(struct Student stu[],int n) 
{
	
}

int main()                   
{  
	struct Student stu[100], maxstu; // �ṹ������ 
	maxstu=input(stu,2);
	print(stu,2); // ��ַ���� 
	print(&maxstu,1); // ���ƽ���ɼ������ 
	
   	return 0;           
}              

int main1()                   
{  
	int i;
	struct Student stu; // �ṹ�����ͱ���
	
	scanf("%d%s",&stu.num,stu.name); 
	// scanf("%d%s",&(stu.num),stu.name); 
	for(i=0;i<5;i++) scanf("%f",&stu.score[i]);
	//for(i=0;i<5;i++) scanf("%f",&(stu.score[i]));
	
	printf("%d %s",stu.num,stu.name);
	for(i=0;i<5;i++) printf(" %f",stu.score[i]);
	
   	return 0;           
}                                  

