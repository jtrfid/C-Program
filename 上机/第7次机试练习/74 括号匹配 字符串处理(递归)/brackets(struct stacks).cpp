/************************************************************************** 
������	25
��������	����ƥ��
ʱ������:	2 ��
�ڴ�����:	10000MB
��������	
��������
��дһ�������жϸ������ʽ�е������Ƿ�ƥ�䡣���ʽ�еĺϷ�����Ϊ��(������)������[������]������{������}�������������ſ��԰�������Ĵ���Ƕ��ʹ�á�
����˵��
�ж�����ʽ��ÿ�����ʽռһ�С�������ı��ʽΪ���ַ���������Ϊ0��ʱ��ʾ�������
���˵��
��ÿ�����ʽ�������е�������ƥ��ģ��������yes�������������no����
��������
[(d+f)*{}2] 
[(2+3)) 
()} 
[4(6]7)9 

�������
yes 
no 
no 
no
��ʾ��Ϣ
 ************************************************************************/
 #include <stdio.h>
 #include <string.h>
 #define N 100
 
 // ����ṹ������ 
 struct bracket
 {
 	char left;    // ������'(','[','{' 
	char right;   // ������')',']','}'
	char matching; // left,right�Ƿ�ƥ�䡣'Y'��ʾƥ�䣬'N'��ʾ��ƥ�� 
 };
 
  // ����ṹ������ 
 void print(struct bracket statcks[],int n)
 {
 	int i = 0;
 	printf("n = %d\n",n); 
 	while(i < n)
 	{
 		printf("left = %c,right = %c,matching = %c\n",statcks[i].left,statcks[i].right,statcks[i].matching);
		i++;
	}
 }

 // ��ջ 
 void push(struct bracket stacks[],char left,int *n)
 {
 	stacks[*n].left = left;
	stacks[*n].right = '\0';
	stacks[*n].matching = 'N'; 
	(*n)++; // ջ��Ԫ�ظ���+1 
 }
 
 // ջ��Ԫ�س�ջ���ɹ����أ�1�����򷵻أ�0 
 int pop(struct bracket stacks[], struct bracket *top,int *n)
 {
 	(*n)--; // ջ��Ԫ�ظ���-1 
	 if(*n < 0) return 0;  
 	*top = stacks[*n];
 	return 1;
 }
 
 // �������ƥ�������ƥ�䷵�أ�1�����򷵻أ�0 
 int check(struct bracket stacks[], char s[])
 {
 	int n = 0, matching = 1; // ջ����Ԫ�أ�����Ҫƥ�䣬��Ϊƥ�� 
 	struct bracket top;
 	char left;
 	while(*s)
 	{
 		if(*s == '(' || *s == '[' || *s == '{') push(stacks,*s,&n);
 		//printf("===%c\n",*s);
 		//print(stacks,n);
 		switch(*s)
 		{
 			case ')': left = '('; break;
			case ']': left = '['; break;
			case '}': left = '{'; break;
			default: left = '\0';
		}
 		if(left != '\0') // ��Ҫ���ƥ�� 
 		{
 			int ret = pop(stacks,&top,&n);
 			//printf("---%c\n",*s);
 		    //print(stacks,n);
 		    //printf("ret = %d,top = %c,left = %c\n",ret,top.left,left);
 			if(ret == 0) {matching = 0; break; } // ��ƥ��
			else if(top.left != left) { matching = 0; break; } // ��ƥ�� 
		} 
		s++;	
	}
	if(n > 0) matching = 0; // ��ʱջ���գ�����δƥ���left 
	return matching; 
 } 
 
 int main()
 {
 	struct bracket stacks[N];
	char s[N];
	
	while(1)
	{
		gets(s);
		if(s[0] == '\0') break;
		if (check(stacks,s)) printf("yes\n");
		else printf("no\n"); 
	}
 	return 0;
 }
