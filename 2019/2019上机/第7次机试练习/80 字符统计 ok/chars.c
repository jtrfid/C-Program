/******************************************************
给出一个字符C和一行文字S，统计在这行文字S中字符C出现的次数。
程序还需要支持大小写敏感选项：
  当选项打开时，表示同一个字母的大写和小写看作不同的字符；
  当选项关闭时，表示同一个字母的大写和小写看作相同的字符。

输入说明	
输入数据由两行构成。
第一行包含一个字符C和一个数字n。字符C为大小或小写英文字母。数字n表示大小写敏感选项，当数字n为0时表示大小写不敏感，当数字n为1时表示大小写敏感。字符C和数字n之间用空格分隔。
第二行为一个字符串S，字符串由大小写英文字母组成，不含空格和其他字符。字符串S长度不超过100。

输出说明	
输出字符C在字符串S中出现的次数。

输入样例
样例1输入
L 1
HELLOWorld
样例2输入
L 0
HELLOWorld

输出样例
样例1输出	
2
样例2输出
3

 ******************************************************/ 
#include <stdio.h>
// 估计字符串长度，实际容纳(N-1)个有效字符，预留最后一个字符'\0'
#define N 101 

int main()
{
    char S[N],C,n, i, count=0;
    
    // printf("%d,%d\n",'a','A'); // 97,65 测试大小写字母转换关系 
    
    /************ 测试, 这样的输入得不到正确的值 
    scanf("%c%d",&C,&n);
    gets(S);
    printf("===%c,%d,%s\n",C,n,S); // 测试输入, 错误 
	*************/ 
	
	/************ 测试, 这样的输入得不到正确的值
    scanf("%c%d%s",&C,&n,S);
    printf("===%c,%d,%s\n",C,n,S); // 测试输入, 错误 
	*************/ 
	
	// 测试以下输入正确 
    C=getchar(); // 读取C 
    scanf("%d",&n); // 读取n 
    getchar(); // 消费回车键 
    gets(S); // 读取S 
    //printf("===%c,%d,%s\n",C,n,S); // 测试输入, 正确 
    
    
    if(n==0 && C>='a' && C<='z') // 大小写不敏感, 统一转为大写比较 
	{
		C = C-32; // 小写转大写 
	} 
    
    for(i=0; S[i]!='\0'; i++) 
    {
		if(n==0) // 大小写不敏感, 统一转为大写比较 
    	{
    		if(S[i]>='a' && S[i]<='z') S[i] = S[i] - 32;  // 小写转大写 
		}
		if(S[i] == C) count++; // 计数 
	}
    printf("%d\n",count);
    return 0;
} 

