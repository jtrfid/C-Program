#include <stdio.h>

int main()
{
	int f;
	float c;
	scanf("%d",&f);
	//c = (f-32)*5.0/9;
	c = (f-32)*5/9;
	printf("%.2f\n",c);
	return 0;
} 
