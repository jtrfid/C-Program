#include <stdio.h>
int main()
 {void swap(int *p1,int *p2);
  int a,b;
  int*pointer_1,*pointer_2;
  printf("please enter a and b:");
  scanf("%d,%d",&a,&b);
  pointer_1=&a;
  pointer_2=&b;
  //if(a<b) swap(pointer_1,pointer_2);
  if(a<b) swap(&a,&b);  // 也可以这样调用函数，就不用指针变量了。 
  printf("max=%d,min=%d\n",a,b); // 交换后的a,b值 
  // printf("*pointer_1=%d,*pointer_2=%d\n",*pointer_1,*pointer_2); // 同交换后的a,b值
  return 0;
 }    

void swap(int *p1,int *p2)
 {int temp; // 交换p1,p2指向的内容，会引起实参的变化 
  temp=*p1;
  *p1=*p2;
  *p2=temp;
}
