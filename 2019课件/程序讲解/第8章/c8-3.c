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
  if(a<b) swap(&a,&b);  // Ҳ�����������ú������Ͳ���ָ������ˡ� 
  printf("max=%d,min=%d\n",a,b); // �������a,bֵ 
  // printf("*pointer_1=%d,*pointer_2=%d\n",*pointer_1,*pointer_2); // ͬ�������a,bֵ
  return 0;
 }    

void swap(int *p1,int *p2)
 {int temp; // ����p1,p2ָ������ݣ�������ʵ�εı仯 
  temp=*p1;
  *p1=*p2;
  *p2=temp;
}
