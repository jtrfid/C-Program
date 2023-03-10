#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *compress(char *src);

// ����ת�ַ�����Ҫ��p��'\0'��β. 
// �ο��μ��ݹ麯�����ֵ�"��: ������������Ӧ�Ķ������ַ���" 
// ���ͬ������stdlib.h�п⺯��char *itoa(int i,char *s,int radix);  
void IntStr(int count,char *p)
{
	char r[2];
	// ���������λ�����ݹ飬δ�����countѹ��ջ�� 
	if (count>=10) IntStr(count/10,p); 
	// popջ�е�count 
	r[0]=count%10+'0'; 
	r[1]='\0'; // ȷ���ַ�����'\0'��β  
	strcat(p,r); 
}

// ��break 
char *compress1(char *src)
{
	// p1,p2ָ��ÿ�ζ�ȡsrc�����䣬dest�洢ѹ���ַ����� 
	char *p1=src,*p2=src,dest[100]={'\0'};
	int count; // ������ͬ�ַ����� 
	char tmp[100];
	
	// ��ȡp1,p2ָ���src�е����䣬�����ͬ�ַ�, p2++; 
	while(*p2!='\0')
	{
		count=1; // ����һ���ַ� 
		while(1)
		{
			p2++;
			if(*p1==*p2) count++;
			else break;
		}
		if(count==1) { tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp); }
		else if(count==2) { tmp[0]=*p1; tmp[1]=*p1; tmp[2]='\0'; strcat(dest,tmp); }
		else // count>=3 
		{
			tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp);
			tmp[0]='\0'; // ȷ���ַ�����'\0'��β  
			IntStr(count,tmp);
			strcat(dest,tmp);
		}
		p1=p2; // ׼�����ֶ�ȡ 
	}
	strcpy(src,dest); // src�洢�ĵ�ַ������������ 
	return src;  // �������Բ�����ָ���������ĵ�ַ.
	// ���ܷ���dest. ��Ϊָ�����dest�Ǿֲ�����������dest�д洢�ĵ�ַ, �뿪�������ʧЧ�� 
	// return dest;  
}

// ����break 
char *compress2(char *src)
{
	// p1,p2ָ��ÿ�ζ�ȡsrc�����䣬dest�洢ѹ���ַ����� 
	char *p1=src,*p2=src,dest[100]={'\0'};
	int count; // ������ͬ�ַ����� 
	char tmp[100];
	
	// ��ȡp1,p2ָ���src�е����䣬�����ͬ�ַ�, p2++; 
	while(*p2!='\0')
	{
		count=0;
		while(*p1==*p2)
		{
			p2++; count++;
		}
		if(count==1) { tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp); }  // ׷���ַ����� 
		else if(count==2) // ׷��2���ַ����� 
		{ tmp[0]=*p1; tmp[1]=*p1; tmp[2]='\0'; strcat(dest,tmp); }
		else // count>=3 
		{
			tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp); // ׷���ַ�����
			tmp[0]='\0'; // ȷ���ַ�����'\0'��β  
			IntStr(count,tmp);
			strcat(dest,tmp); // ׷��count�ַ��� 
		}
		p1=p2; // ׼�����ֶ�ȡ 
	}
	strcpy(src,dest); // src�洢�ĵ�ַ������������ 
	return src;  // �������Բ�����ָ���������ĵ�ַ.
	// ���ܷ���dest. ��Ϊָ�����dest�Ǿֲ�������dest�д洢�ĵ�ַ, �뿪�������ʧЧ�� 
	// return dest;  
}

// ʹ�ÿ⺯��countתΪ�ַ��� 
char *compress(char *src)
{
	// p1,p2ָ��ÿ�ζ�ȡsrc�����䣬dest�洢ѹ���ַ����� 
	char *p1=src,*p2=src,dest[100]={'\0'};
	int count; // ������ͬ�ַ����� 
	char tmp[100];
	
	// ��ȡp1,p2ָ���src�е����䣬�����ͬ�ַ�, p2++; 
	while(*p2!='\0')
	{
		count=0;
		while(*p1==*p2)
		{
			p2++; count++;
		}
		if(count==1) { tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp); } // ׷���ַ����� 
		else if(count==2) // ׷��2���ַ����� 
		{ tmp[0]=*p1; tmp[1]=*p1; tmp[2]='\0'; strcat(dest,tmp); }
		else // count>=3 
		{
			tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp); // ׷���ַ����� 
			tmp[0]='\0'; // ȷ���ַ�����'\0'��β  
			itoa(count,tmp,10); // ת��countΪ�����ַ���, 10��ʾתΪʮ�������� 
			strcat(dest,tmp); // ׷��count�ַ��� 
		}
		p1=p2; // ׼�����ֶ�ȡ 
	}
	strcpy(src,dest); // src�洢�ĵ�ַ������������ 
	return src;  // �������Բ�����ָ���������ĵ�ַ.
	// ���ܷ���dest. ��Ϊָ�����dest�Ǿֲ�������dest�д洢�ĵ�ַ, �뿪�������ʧЧ�� 
	// return dest;  
}

int main()
{
	char src[100];
	scanf("%s",src);

	char *ps = compress(src);
	
	//printf("ddd=%p,%p\n",ps,src);
	puts(ps);
	return 0;
}

// ���� 
int main1()
{
	char p[100];
	
	p[0]='\0'; // ȷ���ַ�����'\0'��β  
	IntStr(19,p);
	puts(p);
	
	// ����ת�ַ���������char *itoa(int i,char *s,int radix); stdlib.h 
	//itoa(0,p,10);
	//puts(p);
	
	return 0;
}
