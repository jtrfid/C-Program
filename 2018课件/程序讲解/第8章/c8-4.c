#include <stdio.h>
int main()
 {void swap(int *p1,int *p2);
  int a,b;
  int*pointer_1,*pointer_2;
  printf("please enter two integer numbers:");
  scanf("%d,%d",&a,&b);
  pointer_1=&a;
  pointer_2=&b;
  if(a<b) swap(pointer_1,pointer_2);
  printf("max=%d,min=%d\n",a,b); // 没有交换a,b 
  printf("*pointer_1=%d,*pointer_2=%d\n",*pointer_1,*pointer_2); // 没有交换a,b 
  int *p1 = &a;
  float *p2 = &b;
  p1 = p2;
  return 0;
 }    

void swap(int *p1,int *p2)
 {int *p;   // 交换p1,p2指针变量，不会引起实参的改变 
  p=p1;
  p1=p2;
  p2=p;
 }
