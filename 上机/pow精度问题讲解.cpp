#include<stdio.h>
#include<math.h>   // ��ѧ�⺯�� 

int intpow(int x, int y)
{
	int i,p=1;
	for(i=0;i<y;i++) p=p*x;
	return p;
} 

int main()
{
   int x=2,y=3;
   // pow������������, �������㾡����Ҫ�ô˺����� 
    
   // ��Щ�����������99,124, Ϊת��ǰ99.999, 124.999 
   printf("%d,%d\n",(int)pow(10,x),(int)pow(5,y)); 
   // ��ֵ�������д��������� 
   printf("%d,%d\n",(int)pow(10,2),(int)pow(5,3)); 
   
   printf("%lf,%lf\n",pow(10,x),pow(5,y)); 
   printf("%lf,%lf\n",pow(10,2),pow(5,3)); 
   
   printf("%lf,%lf\n",pow(0,2),pow(0,0)); 
   
   printf("%d,%d\n",intpow(10,x),intpow(5,y)); 
   printf("%d,%d\n",intpow(10,2),intpow(5,3)); 
    
   printf("%d,%d\n",intpow(0,2),intpow(0,0)); 
  
   
   return 0;
}  

