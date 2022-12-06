/************************************************************************** 
������	56
��������	��Ԫ����2-��Ŀ2-���ʽ��ֵ
ʱ������:	1 ��
�ڴ�����:	256MB
��������	
��������
��һ�����ʽ��ֵ�����ʽ�������Ǹ�����x��y��һ�������op���ɡ�
�������������������˳��������ģ������ǡ�x op y���� ��op x y������ ��x y op����
���磬��25 + 3����ʾ25��3����5 30 *�� ��ʾ5����30����/ 600 15����ʾ600����15��
����˵��
����Ϊһ�����ʽ�����ʽ�������Ǹ�����x��y��һ�������op���ɣ�x��y��op֮���Կո�ָ�����˳��ȷ����
x��y��������10000000��op������+��-,*��/��%�е�����һ�֣��ֱ��ʾ�ӷ����������˷������������ࡣ
����������������ֵ���������ݱ�֤���������������yֵ��Ϊ0��
���˵��
������ʽ��ֵ��
��������
5 20 *
�������
100
��ʾ��Ϣ
 ************************************************************************/
 
 /**********************************
  ˼·: 
  gets������ȡ�ַ����������ַ���������op�ַ���"�������ַ�"���ص㣬�жϱ��ʽ��������ʽ��\\
  ע��: ��Ϊ�ַ����к��пո�, ����ʹ��\lstinline|scanf("%s",-);|��ȡ�ַ�����
  ��Ƹ����Ӻ���, ����ģ�黯������ơ�
  ��д����parse, ���������ַ���, ����3�����ַ���, �ֱ����op,x,y
  ��д����strToInt, �������ַ���תΪ������
  ��д����compute, ����op,x,y������ʽ��ֵ��
  ��д��������������
  ������, ������������, ��ɳ����ܡ�
  **********************************/ 
  
 #include <stdio.h>
// �����ַ�����󳤶ȣ��洢��Ч�ַ�(N-1)����Ԥ�����һ���ַ�'\0' 
 #define N 20 
 
 // ���ݲ�����������ʽ��ֵ 
 int compute(char op,int x,int y)
 {
 	int result = -1;
 	switch(op)
 	{
 		case '+': result = x+y; break;
 		case '-': result = x-y; break;
 		case '*': result = x*y; break;
 		case '/': if(y != 0) result = x/y; break;
 		case '%': if(y != 0) result = x%y; break;
	}
	return result;
 }
 
 // �����ַ���sתΪint, Ҫ��s��'\0'��β 
 int strToInt(char *s)// int toInt(char s[]) 
 {
 	int result=0;
	while(*s) // *s != '\0'
	{
		result=result*10+ (*s-'0');
		s++; //������һ�ַ� 
	}
	return result;
 } 
 
 /******************************************************
  ��ȡ�Ӵ����� 
  ����s�пո�ǰ׺������s�е��ַ�����subs�У����ո��'\0'����
  ����subs�����ո� ���ظ��ƺ�sָ��ָ��(��ַ) 
  Ҫ��s��subs��'\0'��β��
 *******************************************************/ 
 char* getSubs(char *s, char *subs) 
 {
 	int start=0; 
	while(*s)
 	{
		if(*s==' ') 
		{
			if(start==0) s++; // ����s��ǰ׺�ո� 
			else break; // ����Ч�ַ������һ���ո� 
		}
		else
		{
			start=1; // ��ʼ���� 
 		    *subs=*s;
 		    s++;
			subs++;
		}
	}
	*subs='\0'; // ��Ҫ���ǽ�β�� 
	return s;
 }
 
 // ����s, �Կո�Ϊ�ָ���, �ֽ�sΪ3���ַ��� 
 void parse(char *s,char result[][N])
 {
 	char *p;
 	p=getSubs(s,result[0]);
 	p=getSubs(p,result[1]);
 	p=getSubs(p,result[2]);
 } 
 
 // ���s�ǲ�����������1, ����op���ظò�����
 // ����, ����0 
 int isOp(char *s, char *op)
 {
 	if(*s >= '0' && *s <= '9') return 0;
 	else
 	{
 		*op=*s;
 		return 1;
	}
 } 
  
 int main1()
 {
 	char *s="123";
 	printf("%d\n",strToInt(s)); // 123
 	
 	char s1[N]="    abcd   456  +", s2[50], *s3;
	s3= getSubs(s1,s2);
    printf("%s,%d\n",s2,*s3); // abcd,32(�ո��ASCII��) 
    s3= getSubs(s3,s2);
    printf("%s,%d\n",s2,*s3);// 456,0('\0'��ASCII��) 
    
    char result[3][N];
    parse(s1,result);
    puts(result[0]); // abcd
    puts(result[1]); // 456
    puts(result[2]); // +
 	return 0;
 }
 
 int main()
 {
	char s[N],op;
	char s3[3][N];   
	int x,y;
	gets(s); // ����ʹ��scanf("%s",s); �ո񽫻���ֹ
	
	parse(s,s3); // s���ֽ�Ϊ3���ַ��� 
	if(isOp(s3[0],&op)) // op x y
	{
		x=strToInt(s3[1]);
		y=strToInt(s3[2]);
	}
	else if(isOp(s3[1],&op)) // x op y
	{
		x=strToInt(s3[0]);
		y=strToInt(s3[2]);
	}
	else if(isOp(s3[2],&op)) // x y op
	{
		x=strToInt(s3[0]);
		y=strToInt(s3[1]);
	}
	
    printf("%d\n",compute(op,x,y)); 
 	return 0;
 }
