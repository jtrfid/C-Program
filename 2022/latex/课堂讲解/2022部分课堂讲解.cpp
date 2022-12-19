#include<stdio.h>  // 标准输入输出头文件 
#include<math.h>   // 数学库函数头文件
#include<cstdio>   // C++对应的io库 
#include<stack> 
#include<string.h> 

#define N 5  //一般在main函数之前定义 

int max(int *x,int *y) // 形式参数
{  
   // x,y,z局部变量,作用域: 本函数
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

// 把字符c连接至字符串s, 要求s以'\0'结尾.  
void catC1(char s[], char c)
{
	int len=0;
	for(; s[len]!='\0';len++) ;
	s[len]=c;
	s[len+1]='\0'; // 注意, 连接后的s, 也要求以'\0'结尾。
	return; 
}

// 把字符c连接至字符串s, 要求s以'\0'结尾.  
void catC(char s[], char c)
{
	for(; *s!='\0';s++);
	*s++=c; // *s=c; s++; 
	*s='\0'; // 注意, 连接后的s, 也要求以'\0'结尾。
	return; 
}

// 把字符c连接至字符串s, 要求s以'\0'结尾.  
void catC11(char s[], char c)
{
	int i,len=0;
	for(i=0; s[i]!='\0';i++) len++;
	s[len]=c;
	s[len+1]='\0'; // 注意, 连接后的s, 也要求以'\0'结尾。
	return; 
}

// 把字符c连接至字符串s, 要求s以'\0'结尾.  
void catC2(char s[], char c)
{
	char str[2];
	// 构造以'\0'结尾的str字符串 
	str[0]=c;
	str[1]='\0';
	strcat(s,str); // 连接s,str 
	return; 
}

// 把字符c连接至字符串s, 要求s以'\0'结尾.  
void catC3(char s[], char c)
{
	int len;
	len=strlen(s);
	s[len]=c;
	s[len+1]='\0'; // 注意, 连接后的s, 也要求以'\0'结尾。
	return; 
}

// s存放n对应的二进制字符串，以'\0'结尾. 
int to_binary(unsigned long n, char s[])
{
	int r;
	r=n%2;
	// push(先计算的二进制位r)
	if(n>=2) to_binary(n/2, s); 
	// pop(后进先出FILO=先进后出FILO) 
	catC(s,'0'+r);  // 连接 
	printf("sss=%s\n",s);
	return strlen(s);
} 

int main()
{
  //char s[81]={'\0'}; // 可存储80个有效字符, 初始化为以'\0'结尾的空字符串 
  char s[81]=""; // 可存储80个有效字符, 初始化为以'\0'结尾的空字符串 
  catC(s,'1');  // 连接 
  printf("s=%s\n",s);
  catC(s,'2');  // 连接 
  printf("s=%s\n",s);
  return 0;
}

int main21()
{
  // 无符号长整型, 可赋值10进制数
  unsigned long x=0XD2; //11010010
  //char s[81]={'\0'}; // 可存储80个有效字符, 初始化为以'\0'结尾的空字符串 
  char s[81]=""; // 可存储80个有效字符, 初始化为以'\0'结尾的空字符串 
  //输入10进制无符号长整型 
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

int main19() // 主函数
{
   // a,b,c局部变量, 作用域: 本函数
   int a=10,b=20,c; 
   scanf("%d%d",&a,&b);
   // 把此处的a,b值拷贝给函数形式参数x,y
   c=max(&a,&b); // 实际参数a,b 
   printf("较大者=%d\n",c);//与下一句等效
   printf("较大者=%d\n",max(&a,&b));
   
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
		
	// 有些编译器会输出99,124, 因为转换前是99.999, 124.999 
	printf("%d,%d\n",(int)pow(10,x),(int)pow(5,y)); 	
	// 奇怪的是下列调用输出结果与上面有可能会输出不一致的结果 
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
	   在 C89 中，必须使用常量表达式指明数组长度；
	   也就是说，数组长度中不能包含变量，不管该变量有没有初始化。
       而在 C99 中，可以使用变量指明数组长度。 变长数组(VLA, Variable Length Array)。
       普通数组（固定长度的数组）是在编译期间分配内存的，而变长数组是在运行期间分配内存的。
	 */ 
	int m=10,n;
	scanf("%d",&n);
	int a[m],b[n]; // 变长数组，数组名[变量表达式]。数组的长度必须事先赋值。 

	printf("%d,%d\n",sizeof(a)/sizeof(int),sizeof(b)/sizeof(int)); //10,n的值 
	
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
 //printf("请输入m\n");
 //scanf("%d",&m);
 //printf("%d\n",m);  
 a=m/10/10%10;  //a=m/100;
 printf("a等于%d\n",a);
 b=m/10%10; //b=(m-100*a)/10;
 printf("b等于%d\n",b); 
 c=m%10;    //c=m-100*a-10*b;
 printf("c等于%d\n",c);
 printf("\n第一问的答案是%d\n",100*b+10*a+c);
 // 一个字节是8bit二进制, 2位16进制数 
 printf("%d,%X\n",m,m); //  123,7B.  7B ===> 7*16+11;  // 378,17A ==>0X01 7A
 printf("%X\n",(m/16%16)*16+m%16); // 7A
 printf("%X\n",m%256); // m%10,(0 --- 9, 10个数) 8bit二进制数可表示256个数 (00 -- FF) 2^8 
}

int main5()
{
 int a,b,c,m=123;
 //printf("请输入m\n");
 //scanf("%d",&m);
 //printf("%d\n",m);  
 a=m/100;
 printf("a等于%d\n",a);
 b=(m-100*a)/10;
 printf("b等于%d\n",b); 
 c=m-100*a-10*b;
 printf("c等于%d\n",c);
 printf("\n第一问的答案是%d",100*b+10*a+c);
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
    // 函数原型： double sqrt(double x); 
    float a=4.0;
    printf("%f\n",sqrt(a)); 
   	return 0;           
}    
  
int main2()                   
{  
    // 函数原型： double sqrt(double x); 
    float a=4.0,b;
    b=sqrt(a); // 函数调用
    //b=(float)sqrt((double)a); // 强制转换, 函数返回值：高精度 --> 低精度转换 
    printf("%f\n",b); 
   	return 0;           
}    

int main1()                   
{  
    // 函数原型： double sqrt(double x); 
    double a=4.0,b;
    b=sqrt(a); // 函数调用 
    printf("%lf\n",b); 
   	return 0;           
}                                  

