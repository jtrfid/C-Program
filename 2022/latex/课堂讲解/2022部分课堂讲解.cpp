#include<stdio.h>  // ��׼�������ͷ�ļ� 
#include<math.h>   // ��ѧ�⺯��ͷ�ļ�
#include<cstdio>   // C++��Ӧ��io�� 
#include<stack> 
#include<string.h> 

#define N 5  //һ����main����֮ǰ���� 

int max(int *x,int *y) // ��ʽ����
{  
   // x,y,z�ֲ�����,������: ������
   int z; 
   z=*x>*y ? *x : *y;
   printf("%X,%X\n",x,y); // 63FE18,63FE14
   return z; 
}

void fun(int x[],int n,int *f)
{
	printf("%X,%X,%X\n",x,&n,f); // 63FE10,63FDE8,63FE0C
	x[1]=30;
	n=50;
	*f=60;
}

// ���ַ�c�������ַ���s, Ҫ��s��'\0'��β.  
void catC1(char s[], char c)
{
	int len=0;
	for(; s[len]!='\0';len++) ;
	s[len]=c;
	s[len+1]='\0'; // ע��, ���Ӻ��s, ҲҪ����'\0'��β��
	return; 
}

// ���ַ�c�������ַ���s, Ҫ��s��'\0'��β.  
void catC(char s[], char c)
{
	for(; *s!='\0';s++);
	*s++=c; // *s=c; s++; 
	*s='\0'; // ע��, ���Ӻ��s, ҲҪ����'\0'��β��
	return; 
}

// ���ַ�c�������ַ���s, Ҫ��s��'\0'��β.  
void catC11(char s[], char c)
{
	int i,len=0;
	for(i=0; s[i]!='\0';i++) len++;
	s[len]=c;
	s[len+1]='\0'; // ע��, ���Ӻ��s, ҲҪ����'\0'��β��
	return; 
}

// ���ַ�c�������ַ���s, Ҫ��s��'\0'��β.  
void catC2(char s[], char c)
{
	char str[2];
	// ������'\0'��β��str�ַ��� 
	str[0]=c;
	str[1]='\0';
	strcat(s,str); // ����s,str 
	return; 
}

// ���ַ�c�������ַ���s, Ҫ��s��'\0'��β.  
void catC3(char s[], char c)
{
	int len;
	len=strlen(s);
	s[len]=c;
	s[len+1]='\0'; // ע��, ���Ӻ��s, ҲҪ����'\0'��β��
	return; 
}

// s���n��Ӧ�Ķ������ַ�������'\0'��β. 
int to_binary(unsigned long n, char s[])
{
	int r;
	r=n%2;
	// push(�ȼ���Ķ�����λr)
	if(n>=2) to_binary(n/2, s); 
	// pop(����ȳ�FILO=�Ƚ����FILO) 
	catC(s,'0'+r);  // ���� 
	printf("sss=%s\n",s);
	return strlen(s);
} 

int main()
{
  //char s[81]={'\0'}; // �ɴ洢80����Ч�ַ�, ��ʼ��Ϊ��'\0'��β�Ŀ��ַ��� 
  char s[81]=""; // �ɴ洢80����Ч�ַ�, ��ʼ��Ϊ��'\0'��β�Ŀ��ַ��� 
  catC(s,'1');  // ���� 
  printf("s=%s\n",s);
  catC(s,'2');  // ���� 
  printf("s=%s\n",s);
  return 0;
}

int main21()
{
  // �޷��ų�����, �ɸ�ֵ10������
  unsigned long x=0XD2; //11010010
  //char s[81]={'\0'}; // �ɴ洢80����Ч�ַ�, ��ʼ��Ϊ��'\0'��β�Ŀ��ַ��� 
  char s[81]=""; // �ɴ洢80����Ч�ַ�, ��ʼ��Ϊ��'\0'��β�Ŀ��ַ��� 
  //����10�����޷��ų����� 
  scanf("%uld",&x);  
  printf("%d",to_binary(x,s));
  
  return 0;
}

int main20()
{
	std::stack<int> s;
	printf("%d\n",s.empty());
	s.push(10);
	s.push(20);
	printf("%d\n",s.top());
	s.pop();
	printf("%d\n",s.top());
	
	return 0;
}

int main19() // ������
{
   // a,b,c�ֲ�����, ������: ������
   int a=10,b=20,c; 
   scanf("%d%d",&a,&b);
   // �Ѵ˴���a,bֵ������������ʽ����x,y
   c=max(&a,&b); // ʵ�ʲ���a,b 
   printf("�ϴ���=%d\n",c);//����һ���Ч
   printf("�ϴ���=%d\n",max(&a,&b));
   
   printf("%X,%X\n",&a,&b); //63FE18,63FE14
   return 0; 
}

int main18()
{
	int a[2]={10,20},m=40;
	
	fun(a,m,&m);
	
	printf("%X,%X\n",a,&m); // 63FE10,63FE0C
	
	printf("%d,%d,%d\n",a[0],a[1],m); // 10,30,60

	return 0;
} 

int main17()
{
	int x=2,y=3;
	
	printf("%d,%d\n",(int)pow(0,0),(int)pow(0,9)); // 1,0 
		
	// ��Щ�����������99,124, ��Ϊת��ǰ��99.999, 124.999 
	printf("%d,%d\n",(int)pow(10,x),(int)pow(5,y)); 	
	// ��ֵ������е����������������п��ܻ������һ�µĽ�� 
	printf("%d,%d\n",(int)pow(10,0),(int)pow(5,9)); 
	return 0;
} 

int main16()                   
{  
    char a[81]="abcd";
    char b[]="abcd";

	printf("%d,%d\n",sizeof(a)/sizeof(char),sizeof(b)/sizeof(char)); // 81,5
	
	printf("%d\n",'\0'); // 0
	
   	return 0;           
}    

int main15()                   
{  
    /*
	   �� C89 �У�����ʹ�ó������ʽָ�����鳤�ȣ�
	   Ҳ����˵�����鳤���в��ܰ������������ܸñ�����û�г�ʼ����
       ���� C99 �У�����ʹ�ñ���ָ�����鳤�ȡ� �䳤����(VLA, Variable Length Array)��
       ��ͨ���飨�̶����ȵ����飩���ڱ����ڼ�����ڴ�ģ����䳤�������������ڼ�����ڴ�ġ�
	 */ 
	int m=10,n;
	scanf("%d",&n);
	int a[m],b[n]; // �䳤���飬������[�������ʽ]������ĳ��ȱ������ȸ�ֵ�� 

	printf("%d,%d\n",sizeof(a)/sizeof(int),sizeof(b)/sizeof(int)); //10,n��ֵ 
	
   	return 0;           
}    

int main14()                   
{  
	int a[N],i;
	
	
	printf("%db\n",N);
	
	scanf("%d ",&a[0]);
	printf("aaaa%dbbbb\n",a[0]);
	scanf("%d",&a[1]);
	
	printf("====%d,%d",a[0],a[1]);
	
   	return 0;           
}    

int main13()                   
{  
	int a[N],i;
	
	scanf("%d ",&a[0]);
	printf("aaaa%dbbbb\n",a[0]);
	scanf("%d ",&a[1]);
	
	printf("====%d,%d",a[0],a[1]);
	
   	return 0;           
}    

int main12()                   
{  
	int a[N],i;
	
	scanf("%d %d",&a[0],&a[1]);
	
	printf("%d,%d",a[0],a[1]);
	
   	return 0;           
}    

int main11()                   
{  
	int a[N],i;
	
	for(i=0;i<5;i++)
	{
		scanf("%d ",&a[i]);
		//printf("====%d+++",a[i]);
	}
	
	for(i=0;i<5;i++)
		printf("%d\t",a[i]);
   	return 0;           
}    


int main10()                   
{  
	int a[30],n=5;
	for(int i=0;i<n;i++)
	{
		a[i]=n*n-n+1+i*2;
		printf("%d ",a[i]);	
	} 
   	return 0;           
}    

int main9()                   
{  
	char c='A';
	for(int i=1; i<=26;i++)
	{
		printf("%c ",c+(i-1)); 
	}
	printf("\n");
	for(int i=1; i<=26;i++)
	{
		c='A'+(i-1);
		char c1='A'+(c-'A'+4)%26;
		printf("%c ",c1); 
	}
   	return 0;           
}    

int main8()                   
{  
	for(int i=1; i<=10;i++)
	{
		if(i==3) continue;
		printf("%d ",i); 
	}
   	return 0;           
}    

int main7()                   
{  
	for(int i=1; i<=10;i++)
	{
		// -1 -1.0,1 1.0,-1 -1.0,1 1.0,-1 -1.0,1 1.0,-1 -1.0,1 1.0,-1 -1.0,1 1.0,
		printf("%d %.1f,",(int)pow(-1,i),pow(-1,i));
	}
	printf("\n");
	int a;
	for(int i=1; i<=100;i++)
	{
		a=pow(-1,i);
		printf("%d,",a);
	}
   	return 0;           
}    

int main6()
{
 int a,b,c,m=378;
 //printf("������m\n");
 //scanf("%d",&m);
 //printf("%d\n",m);  
 a=m/10/10%10;  //a=m/100;
 printf("a����%d\n",a);
 b=m/10%10; //b=(m-100*a)/10;
 printf("b����%d\n",b); 
 c=m%10;    //c=m-100*a-10*b;
 printf("c����%d\n",c);
 printf("\n��һ�ʵĴ���%d\n",100*b+10*a+c);
 // һ���ֽ���8bit������, 2λ16������ 
 printf("%d,%X\n",m,m); //  123,7B.  7B ===> 7*16+11;  // 378,17A ==>0X01 7A
 printf("%X\n",(m/16%16)*16+m%16); // 7A
 printf("%X\n",m%256); // m%10,(0 --- 9, 10����) 8bit���������ɱ�ʾ256���� (00 -- FF) 2^8 
}

int main5()
{
 int a,b,c,m=123;
 //printf("������m\n");
 //scanf("%d",&m);
 //printf("%d\n",m);  
 a=m/100;
 printf("a����%d\n",a);
 b=(m-100*a)/10;
 printf("b����%d\n",b); 
 c=m-100*a-10*b;
 printf("c����%d\n",c);
 printf("\n��һ�ʵĴ���%d",100*b+10*a+c);
}

int main4()                   
{  
    float c,f;
    c=5/9*(f-32);  // c=0,error
    c=(f-32)*5.0/9.0; // ok
    c=(f-32)*5/9; // ok
    c=5.0/9*(f-32); // ok
    c=(float)5/9*(f-32); // ok
   	return 0;           
}   

int main3()                   
{  
    // ����ԭ�ͣ� double sqrt(double x); 
    float a=4.0;
    printf("%f\n",sqrt(a)); 
   	return 0;           
}    
  
int main2()                   
{  
    // ����ԭ�ͣ� double sqrt(double x); 
    float a=4.0,b;
    b=sqrt(a); // ��������
    //b=(float)sqrt((double)a); // ǿ��ת��, ��������ֵ���߾��� --> �;���ת�� 
    printf("%f\n",b); 
   	return 0;           
}    

int main1()                   
{  
    // ����ԭ�ͣ� double sqrt(double x); 
    double a=4.0,b;
    b=sqrt(a); // �������� 
    printf("%lf\n",b); 
   	return 0;           
}                                  

