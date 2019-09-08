#include <stdio.h>
#include<math.h>
int main1()
{
  int sign=1;  int num=1;            // sign用来表示数值的符号, 辅助变量num记录循环次数 
  double pi=0.0,n=1.0,term=1.0;      // pi代表π,n代表分母，term代表当前项的值
  while(fabs(term)>=1e-6)            // 检查当前项term的绝对值是否大于或等于10的(-6)次方
  {
     pi=pi+term;                     // 把当前项term累加到pi中
     n=n+2;                          // n+2是下一项的分母 
     sign=-sign;                     // sign代表符号，下一项的符号与上一项符号相反
     term=sign/n;                    // 求出下一项的值term
     num++;
  }
  printf("%d\n",num);  // 500001
  pi=pi*4;                           // 多项式的和pi乘以4，才是π的近似值
  printf("pi=%10.8f\n",pi);          // pi=3.14159065 输出π的近似值 
  
  // 对于double类型的输出，"%f"和"%lf"是一致的，但是scanf中必须使用%lf 
  int ret =  printf("pi=%10.8f\n",pi); // pi=3.14159065
  printf("%d\n",ret);  // 14 若成功则为写入的字符数，若发生错误则为负值。
  ret =  printf("pi=%10.8lf\n",pi);  // pi=3.14159065
  printf("%d\n",ret); // 14 若成功则为写入的字符数，若发生错误则为负值。
  return 0;
}

// while(n <= 1e+6) 等效 while(fabs(term)>=1e-6) 
int main()
{
  int sign=1;     int num=1;         // sign用来表示数值的符号, 辅助变量num记录循环次数
  double pi=0.0,n=1.0,term=1.0;      // pi代表π,n代表分母，term代表当前项的值
  while(n <= 1e+6)            // 检查当前项term的绝对值是否大于或等于10的(-6)次方
  {
     pi=pi+term;                     // 把当前项term累加到pi中
     n=n+2;                          // n+2是下一项的分母 
     sign=-sign;                     // sign代表符号，下一项的符号与上一项符号相反
     term=sign/n;                    // 求出下一项的值term
     num++;
  }
  printf("%d\n",num);  // 500001
  pi=pi*4;                           // 多项式的和pi乘以4，才是π的近似值
  printf("pi=%10.8f\n",pi);          // pi=3.14159065 输出π的近似值 
  
  // 对于double类型的输出，"%f"和"%lf"是一致的，但是scanf中必须使用%lf 
  int ret =  printf("pi=%10.8f\n",pi); // pi=3.14159065
  printf("%d\n",ret);  // 14 若成功则为写入的字符数，若发生错误则为负值。
  ret =  printf("pi=%10.8lf\n",pi);  // pi=3.14159065
  printf("%d\n",ret); // 14 若成功则为写入的字符数，若发生错误则为负值。
  return 0;
}
