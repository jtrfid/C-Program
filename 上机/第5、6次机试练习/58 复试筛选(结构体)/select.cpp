/************************************************************************
������	58
��������	��Ԫ����2-��Ŀ4-����ɸѡ
ʱ������:	1 ��
�ڴ�����:	256MB
��������	
��������
���г��Գɼ���������Ҫ��m��ѧ���ĳɼ���������ɸѡ�����Խ��븴�Ե�ǰn��ѧ����
�������Ϊ���Ȱ����ܷ������ܷ���ͬ��Ӣ�ﵥ�Ƴɼ������ָ�����m��ѧ���Ŀ��г��Գɼ���
��ɸѡ�����Խ��븴�Ե�n��ѧ�������������Ӹߵ��͵�˳�����������
����˵��
����Ϊm+1�У���һ��Ϊ��������m��n���ֱ��ʾ�������Ϳ��Խ��븴��������m��n֮���ÿո�ָ���0<n<m<200��������Ϊm�����ݣ�ÿ�а���������Ϣ���ֱ��ʾһ��ѧ���Ŀ��ţ��ַ��������ܳɼ�����������Ӣ�ﵥ�Ƴɼ�����������������֮���ÿո�ָ���
���˵��
�������Ӹߵ��͵�˳��������븴�Ե���n��ѧ������Ϣ��
��������
5 3 
XD20160001 330 65 
XD20160002 330 70 
XD20160003 340 60 
XD20160004 310 80 
XD20160005 360 75 
�������
XD20160005 360 75 
XD20160003 340 60 
XD20160002 330 70 
��ʾ��Ϣ
 ************************************************************************/
 // ˼·������ṹ�����ͺͽṹ�����飬�Խṹ������������� 
 
 #include <stdio.h>
 #include <string.h>
  
 // ���ƽṹ��������󳤶� 
 #define N 200
 
 struct Student 
 {
 	char no[20];   // ���� 
	int  total;    // �ܳɼ� 
	int  english;  // Ӣ��ɼ�  
 };
 
 // ����m��������Ϣ
void input(struct Student *stus, int m)
{
  int i;
  for(i=0;i<m;i++) 
    scanf("%s%d%d",
      stus[i].no,&stus[i].total,&stus[i].english); 
}

// ����n��������Ϣ
void print(struct Student *stus, int n)
{
  int i;
  for(i=0;i<n;i++) 
    printf("%s %d %d\n",
      stus[i].no,stus[i].total,stus[i].english); 
}
 
 // ���������ṹ����� 
 void swap(struct Student *p1, struct Student *p2)
 {
 	struct Student temp;
 	temp = *p1; *p1 = *p2; *p2 = temp;
 }
 
 /** 
  ѡ�����򣨽���
  �������Ϊ���Ȱ����ܷ������ܷ���ͬ��Ӣ�ﵥ�Ƴɼ�����
  **/ 
 void sorts(struct Student a[], int n)
 {
 	int i,j,k;
 	for(i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i+1; j < n; j++)
		{
			// �����ж���䣺����&&��||���㣬��if else�ṹ 
			if (a[j].total>a[k].total || (a[j].total==a[k].total &&  a[j].english>a[k].english)
			    || (a[j].total==a[k].total &&  a[j].english==a[k].english && strcmp(a[j].no,a[k].no)<0))  
				k = j;
		}
		if (k != i) swap(&a[i],&a[k]);
	} 
 }
 
 int main()
 {
 	struct Student stus[N]; 
	int m,n,i;
 	scanf("%d%d",&m,&n);
 	input(stus,m); 
 	sorts(stus,m);
 	print(stus,n);
 	return 0;
 }
