#include <stdio.h>
#include <string.h>
int main()
 {char c[15]={'I',' ','a','m',' ','a',' ','s','t','u','d','e','n','t','.'};
  int i;
  for(i=0;i<15;i++)
    printf("%c",c[i]);
  printf("\n");
  
  printf("%s\n",c);
  printf("%x\n",c);  // c����ʼ��ַ��16���ƣ� 
  printf("%o\n",c);  // c����ʼ��ַ��8���ƣ�
  
  char s[] = "abCDeF123"; 
  printf("%s\n",strlwr(s)); 
  printf("%s\n",s); 
  printf("%s\n",strupr(s)); 
  printf("%s\n",s); 
  
  char a[10]={' ',' '};
  char aa = "";  // �˸�BS(backspace),8  
  //char b = ''; // [Error] empty character constant
  printf("%d,%d,%c,%d",a[0],a[1],aa,aa); 
  gets(a);
  puts(a);
  return 0;
}  
