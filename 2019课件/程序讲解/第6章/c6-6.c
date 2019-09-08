#include <stdio.h>
#include <string.h>
int main()
 {char c[15]={'I',' ','a','m',' ','a',' ','s','t','u','d','e','n','t','.'};
  int i;
  for(i=0;i<15;i++)
    printf("%c",c[i]);
  printf("\n");
  
  printf("%s\n",c);
  printf("%x\n",c);  // c的起始地址（16进制） 
  printf("%o\n",c);  // c的起始地址（8进制）
  
  char s[] = "abCDeF123"; 
  printf("%s\n",strlwr(s)); 
  printf("%s\n",s); 
  printf("%s\n",strupr(s)); 
  printf("%s\n",s); 
  
  char a[10]={' ',' '};
  char aa = "";  // 退格BS(backspace),8  
  //char b = ''; // [Error] empty character constant
  printf("%d,%d,%c,%d",a[0],a[1],aa,aa); 
  gets(a);
  puts(a);
  return 0;
}  
