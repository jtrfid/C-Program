#include <stdio.h>
#include<math.h>
int main1()
{
  int sign=1;  int num=1;            // sign������ʾ��ֵ�ķ���, ��������num��¼ѭ������ 
  double pi=0.0,n=1.0,term=1.0;      // pi�����,n�����ĸ��term����ǰ���ֵ
  while(fabs(term)>=1e-6)            // ��鵱ǰ��term�ľ���ֵ�Ƿ���ڻ����10��(-6)�η�
  {
     pi=pi+term;                     // �ѵ�ǰ��term�ۼӵ�pi��
     n=n+2;                          // n+2����һ��ķ�ĸ 
     sign=-sign;                     // sign������ţ���һ��ķ�������һ������෴
     term=sign/n;                    // �����һ���ֵterm
     num++;
  }
  printf("%d\n",num);  // 500001
  pi=pi*4;                           // ����ʽ�ĺ�pi����4�����ǦеĽ���ֵ
  printf("pi=%10.8f\n",pi);          // pi=3.14159065 ����еĽ���ֵ 
  
  // ����double���͵������"%f"��"%lf"��һ�µģ�����scanf�б���ʹ��%lf 
  int ret =  printf("pi=%10.8f\n",pi); // pi=3.14159065
  printf("%d\n",ret);  // 14 ���ɹ���Ϊд����ַ�����������������Ϊ��ֵ��
  ret =  printf("pi=%10.8lf\n",pi);  // pi=3.14159065
  printf("%d\n",ret); // 14 ���ɹ���Ϊд����ַ�����������������Ϊ��ֵ��
  return 0;
}

// while(n <= 1e+6) ��Ч while(fabs(term)>=1e-6) 
int main()
{
  int sign=1;     int num=1;         // sign������ʾ��ֵ�ķ���, ��������num��¼ѭ������
  double pi=0.0,n=1.0,term=1.0;      // pi�����,n�����ĸ��term����ǰ���ֵ
  while(n <= 1e+6)            // ��鵱ǰ��term�ľ���ֵ�Ƿ���ڻ����10��(-6)�η�
  {
     pi=pi+term;                     // �ѵ�ǰ��term�ۼӵ�pi��
     n=n+2;                          // n+2����һ��ķ�ĸ 
     sign=-sign;                     // sign������ţ���һ��ķ�������һ������෴
     term=sign/n;                    // �����һ���ֵterm
     num++;
  }
  printf("%d\n",num);  // 500001
  pi=pi*4;                           // ����ʽ�ĺ�pi����4�����ǦеĽ���ֵ
  printf("pi=%10.8f\n",pi);          // pi=3.14159065 ����еĽ���ֵ 
  
  // ����double���͵������"%f"��"%lf"��һ�µģ�����scanf�б���ʹ��%lf 
  int ret =  printf("pi=%10.8f\n",pi); // pi=3.14159065
  printf("%d\n",ret);  // 14 ���ɹ���Ϊд����ַ�����������������Ϊ��ֵ��
  ret =  printf("pi=%10.8lf\n",pi);  // pi=3.14159065
  printf("%d\n",ret); // 14 ���ɹ���Ϊд����ַ�����������������Ϊ��ֵ��
  return 0;
}
