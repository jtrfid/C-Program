
#include <stdio.h>
#include <math.h>

#define N 100
int main()
{
	int S,T,A;
	float tax=0.0;
	scanf("%d",&S);
	A=S-3500;
	if(A<=0) tax=0;
	else
	{
		if(A<=1500)  tax=A*0.03;	
		else if(A>1500 && A<=4500) tax=1500*0.03+(A-1500)*0.1;
		else if(A>4500 && A<=9000) tax=1500*0.03+(4500-1500)*0.1+(A-4500)*0.2;
		else if(A>9000 && A<=35000) tax=1500*0.03+(4500-1500)*0.1+(9000-4500)*0.2+(A-9000)*0.25;
		else tax=1500*0.03+(4500-1500)*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(A-35000)*0.3;
	} 
	T=S-tax;
	printf("%d\n",T);
	return 0;
} 
