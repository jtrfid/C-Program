#include<stdio.h> //Ԥ���� 
int main1() // ������������ʼ 
{
	int a=0x20; //���ͱ���
	float f=5.2; // �����ȸ�����
	double d=2.1; // ˫���ȸ����� 
	char c=' ';
	
	printf("%d,0x%X,%d,%cHHHHH\n",c,c,a,a);
	printf("%c,%d;%c,%d,%d",'a','a','A','A','a'-'A');
	/*********
	//scanf("%d,%f,%lf,%c",&a,&f,&d,&c);// ���������ֵ��&ȡ��ַ�� 
	scanf("%d%f%lf%c",&a,&f,&d,&c);
	// ��������ռ�ô洢��Ԫ�Ĵ�С��1�ֽ�����С�洢��Ԫ 
	//printf("size=%d,%d,%d\n",sizeof(int),sizeof(float),sizeof(double));
	printf("%d,%.2f,%.3lf,%c,%d",a,f,d,c,c); // ���������ֵ 
	*********/
	return 0;
}

int main2() // ������������ʼ 
{
	int a=10; //���ͱ���
	float f=5.2; // �����ȸ�����
	double d=2.1; // ˫���ȸ����� 
	char c1,c2; // �ַ����� 
	
	scanf("%c",&c1);
	// ............
	getchar(); // ���ѻس�����getchar()����һ���ַ� 
	//scanf("%c",&c2);

    c2=getchar();
    
    printf("output============\n");
    
    putchar(c2);
    putchar('\n');
		
	printf("c1=%c,%d,====c2=%c,%d\n",c1,c1,c2,c2); // ���������ֵ 
	return 0;
}

int main() // ������������ʼ 
{
	int a,b;
	char op; // �ַ����� 
	
	scanf("%d%c%d",&a,&op,&b);
	printf("%d %c %d=?\n",a,op,b);
		
	//printf("c1=%c,%d,====c2=%c,%d\n",c1,c1,c2,c2); // ���������ֵ 
	return 0;
}

int main4()
{
    int a=-25,b=102;
    printf("a=%d,b=%d,a=%x,b=%x\n",a,b,a,b);
    printf("%d,%d,%x,%x\n",-25,102,-25,102);
    printf("%d,%d,%x,%x,%X\n",77,-77,77,-77,-77);
	return 0;
} 
