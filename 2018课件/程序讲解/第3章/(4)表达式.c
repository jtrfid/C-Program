/********************************************************************
 * 写出下列各算式的C语言表达式
 ********************************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
     float a,b,c,d,e,x,y;
     
     // (1) 
     y = sin(x)*sin(x)*(a+b)/(a-b);
     
     // (2)
     y = (x>20 && x<30) || x<-100;
     
     // (3)
     y = exp(0.5*x*x)/sqrt(2*3.14);
     
     // (4) 
     y = 0.5*(a*x+(a+x)/(4.0*a));
     
     // (5)
     y = sqrt(pow(sin(x),2.5));
     // 或
     y = pow(sin(x),1.25);
     
     // (6)
     y = x*x-exp(5.0);
     
     // (7)
     y = 3.0*a*e/(c*d); 
     
     // (8)
     y = sqrt(pow(x,y)+log10(y));
     
     // (9)
     y = fabs(pow(x,3.0)+log10(x));
     
     // (10) 对整型变量a右移4位
     a = 4.5; 
     printf("%d\n",((int)a)>>2);  // 1
     
     system("pause");
     return 0;
}
