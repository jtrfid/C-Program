#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *compress(char *src);

int main()
{
	char src[100];
	scanf("%s",src);

	char *ps = compress(src);

	puts(ps);
	return 0;
}

///////////////////////// 这样的代码, 居然正确 
char *compress(char *src)
{
    char *pe=src;
	while(*src){
		while(*src==*pe){
			pe++;
		}
		int l=pe-src;
		if(l<3){
			for(int i=0;i<l;i++){
				printf("%c",src[i]);
			}
		}else{
			printf("%c%d",*src,l);
		}
		src=pe;
	}
	return '\0';
}


