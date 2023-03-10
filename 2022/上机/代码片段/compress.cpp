#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *compress(char *src);

// 整数转字符串，要求p以'\0'结尾. 
// 参考课件递归函数部分的"例: 生成正整数对应的二进制字符串" 
// 完成同样功能stdlib.h中库函数char *itoa(int i,char *s,int radix);  
void IntStr(int count,char *p)
{
	char r[2];
	// 如果多于两位数，递归，未计算的count压入栈中 
	if (count>=10) IntStr(count/10,p); 
	// pop栈中的count 
	r[0]=count%10+'0'; 
	r[1]='\0'; // 确保字符串以'\0'结尾  
	strcat(p,r); 
}

// 用break 
char *compress1(char *src)
{
	// p1,p2指向每次读取src的区间，dest存储压缩字符串。 
	char *p1=src,*p2=src,dest[100]={'\0'};
	int count; // 连续相同字符计数 
	char tmp[100];
	
	// 读取p1,p2指向的src中的区间，如果相同字符, p2++; 
	while(*p2!='\0')
	{
		count=1; // 至少一个字符 
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
			tmp[0]='\0'; // 确保字符串以'\0'结尾  
			IntStr(count,tmp);
			strcat(dest,tmp);
		}
		p1=p2; // 准备下轮读取 
	}
	strcpy(src,dest); // src存储的地址与主函数共享 
	return src;  // 返回来自参数的指针变量传输的地址.
	// 不能返回dest. 因为指针变量dest是局部变量，所以dest中存储的地址, 离开函数后会失效。 
	// return dest;  
}

// 不用break 
char *compress2(char *src)
{
	// p1,p2指向每次读取src的区间，dest存储压缩字符串。 
	char *p1=src,*p2=src,dest[100]={'\0'};
	int count; // 连续相同字符计数 
	char tmp[100];
	
	// 读取p1,p2指向的src中的区间，如果相同字符, p2++; 
	while(*p2!='\0')
	{
		count=0;
		while(*p1==*p2)
		{
			p2++; count++;
		}
		if(count==1) { tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp); }  // 追加字符本身 
		else if(count==2) // 追加2个字符本身 
		{ tmp[0]=*p1; tmp[1]=*p1; tmp[2]='\0'; strcat(dest,tmp); }
		else // count>=3 
		{
			tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp); // 追加字符本身
			tmp[0]='\0'; // 确保字符串以'\0'结尾  
			IntStr(count,tmp);
			strcat(dest,tmp); // 追加count字符串 
		}
		p1=p2; // 准备下轮读取 
	}
	strcpy(src,dest); // src存储的地址与主函数共享 
	return src;  // 返回来自参数的指针变量传输的地址.
	// 不能返回dest. 因为指针变量dest是局部变量，dest中存储的地址, 离开函数后会失效。 
	// return dest;  
}

// 使用库函数count转为字符串 
char *compress(char *src)
{
	// p1,p2指向每次读取src的区间，dest存储压缩字符串。 
	char *p1=src,*p2=src,dest[100]={'\0'};
	int count; // 连续相同字符计数 
	char tmp[100];
	
	// 读取p1,p2指向的src中的区间，如果相同字符, p2++; 
	while(*p2!='\0')
	{
		count=0;
		while(*p1==*p2)
		{
			p2++; count++;
		}
		if(count==1) { tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp); } // 追加字符本身 
		else if(count==2) // 追加2个字符本身 
		{ tmp[0]=*p1; tmp[1]=*p1; tmp[2]='\0'; strcat(dest,tmp); }
		else // count>=3 
		{
			tmp[0]=*p1; tmp[1]='\0'; strcat(dest,tmp); // 追加字符本身 
			tmp[0]='\0'; // 确保字符串以'\0'结尾  
			itoa(count,tmp,10); // 转换count为数字字符串, 10表示转为十进制数字 
			strcat(dest,tmp); // 追加count字符串 
		}
		p1=p2; // 准备下轮读取 
	}
	strcpy(src,dest); // src存储的地址与主函数共享 
	return src;  // 返回来自参数的指针变量传输的地址.
	// 不能返回dest. 因为指针变量dest是局部变量，dest中存储的地址, 离开函数后会失效。 
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

// 测试 
int main1()
{
	char p[100];
	
	p[0]='\0'; // 确保字符串以'\0'结尾  
	IntStr(19,p);
	puts(p);
	
	// 整数转字符串函数，char *itoa(int i,char *s,int radix); stdlib.h 
	//itoa(0,p,10);
	//puts(p);
	
	return 0;
}
