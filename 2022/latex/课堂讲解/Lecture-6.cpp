#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 
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
   
   switch(x+y) // x�������������ʽ 
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
   
   switch(a) // x�������������ʽ 
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
   unsigned char a=100; // ��һ���ֽ����ܱ������� 
   
   switch(a) // x�������������ʽ 
   {
   	case 0: 
   		printf("x=0\n");
   		printf("x is 0\n"); 
   		break; // �޴˾䣬��������ִ�� 
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
   while(i<=total)  // iѭ������ 
   { // ѭ���壬��һϵ�е�������---������� 
   	scanf("%f",&s);
   	sum=sum+s; // sum+=s;
   	i++; // i=i+1; // ����Ҫ�иı�ѭ����������� 
   }
   printf("%f\n",sum/total);
   return 0;           
}   

int main6()                   
{  
   int total=2,i=1; 
   float s,sum=0.0;
   do 
   { // ѭ���壬��һϵ�е�������---������� 
   	scanf("%f",&s);
   	sum=sum+s; // sum+=s;
   	i++; // i=i+1; // ����Ҫ�иı�ѭ����������� 
   }while(i<=total);
   printf("%f\n",sum/total);
   return 0;           
}

int main()                   
{  
   int total=2,i; 
   float s,sum=0.0;
   for(i=1;i<=total;i++) // ��ʼ�����ʽ;�������ʽ;�ı�ѭ������ 
   { // ѭ���壬��һϵ�е�������---������� 
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
   for(i=1;i<=total;i++) // ��ʼ�����ʽ;�������ʽ;�ı�ѭ������ 
   { // ѭ���壬��һϵ�е�������---������� 
   	scanf("%f",&s);
   	if(s<60) 
	{
		continue; // ��ִ��ѭ����ĺ������� 
    }
	sum=sum+s; // sum+=s;
   }
   printf("i=%d\n",i);
   printf("%f\n",sum/total);
   return 0;           
}                                                                                                                           
