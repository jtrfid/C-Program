#include<stdio.h>
#include<math.h>   // 数学库函数 
#define PI 3.1415926       
int main1()                   
{  
   int x=50;
   
   if(10<=x<=100) // 1<=100
   {
   	printf("aaaaa\n");
   }
   
   //if(10<=x && x<=100)
   if(x>=10 && x<=100)
   {
   	printf("bbbb\n");
   }
   
   return 0;           
}      

int main2()                   
{  
   int x=1,y=0;
   
   switch(x+y) // x必须是整数表达式 
   {
   	case 0: 
   		printf("x=0\n");
   	case 1:
   		printf("x=1\n");
   	
   }
   return 0;           
}       

int main3()                   
{  
   char a='B';
   
   switch(a) // x必须是整数表达式 
   {
   	case 'A': 
   		printf("x=0\n");
   	case 'B':
   		printf("x=1\n");
   	
   }
   return 0;           
}       

int main4()                   
{  
   unsigned char a=100; // 在一个字节中能表达的整数 
   
   switch(a) // x必须是整数表达式 
   {
   	case 0: 
   		printf("x=0\n");
   		printf("x is 0\n"); 
   		break; // 无此句，继续往下执行 
   	case 1:
   		printf("x=1\n");
   		break;
   	case 10:
   		printf("x=10\n");
   		break;
   	default:
   		printf("others\n");
   		//break;
   	
   }
   return 0;           
} 

int main5()                   
{  
   int total=2,i=1; 
   float s,sum=0.0;
   while(i<=total)  // i循环变量 
   { // 循环体，由一系列的语句组成---复合语句 
   	scanf("%f",&s);
   	sum=sum+s; // sum+=s;
   	i++; // i=i+1; // 必须要有改变循环变量的语句 
   }
   printf("%f\n",sum/total);
   return 0;           
}   

int main6()                   
{  
   int total=2,i=1; 
   float s,sum=0.0;
   do 
   { // 循环体，由一系列的语句组成---复合语句 
   	scanf("%f",&s);
   	sum=sum+s; // sum+=s;
   	i++; // i=i+1; // 必须要有改变循环变量的语句 
   }while(i<=total);
   printf("%f\n",sum/total);
   return 0;           
}

int main()                   
{  
   int total=2,i; 
   float s,sum=0.0;
   for(i=1;i<=total;i++) // 初始化表达式;条件表达式;改变循环变量 
   { // 循环体，由一系列的语句组成---复合语句 
   	scanf("%f",&s);
   	sum=sum+s; // sum+=s;
   }
   printf("%f\n",sum/total);
   return 0;           
}       

int main()                   
{  
   int total=2,i; 
   float s,sum=0.0;
   for(i=1;i<=total;i++) // 初始化表达式;条件表达式;改变循环变量 
   { // 循环体，由一系列的语句组成---复合语句 
   	scanf("%f",&s);
   	if(s<60) 
	{
		continue; // 不执行循环体的后续部分 
    }
	sum=sum+s; // sum+=s;
   }
   printf("i=%d\n",i);
   printf("%f\n",sum/total);
   return 0;           
}                                                                                                                           
