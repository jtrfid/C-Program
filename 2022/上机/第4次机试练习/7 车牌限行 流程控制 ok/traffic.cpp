#include <stdio.h>
 
int main()
{
    int  week, hazeIndex, No; // ���ڼ�, ����ָ��, ���ƺ���
	int LastNo; // ���ƺ����һλ����
	int control[2][5][10]={{ // hazeIndex>=200 && hazeIndex<400
	                        {0,1,0,0,0,1,0,0,0,0}, // ��һ 
	                        {0,0,1,0,0,0,0,1,0,0}, // �ܶ� 
	                        {0,0,0,1,0,0,0,0,1,0}, // ����
							{0,0,0,0,1,0,0,0,0,1}, // ���� 
							{1,0,0,0,1,0,0,0,0,0}, // ���� 
	                       }, // hazeIndex>=400
						   { {0,1,0,1,0,1,0,1,0,1}, // ��һ 
						     {1,0,1,0,1,0,1,0,1,0}, // �ܶ� 
						     {0,1,0,1,0,1,0,1,0,1}, // ���� 
						     {1,0,1,0,1,0,1,0,1,0}, // ���� 
						     {0,1,0,1,0,1,0,1,0,1}, // ����  
					       }
	                      }; 
    
	scanf("%d%d%d",&week,&hazeIndex,&No);
    LastNo=No%10; 
	if(hazeIndex>=200 && hazeIndex<400)
	{
		if(control[0][week-1][LastNo]) printf("%d yes",LastNo);
		else printf("%d no",LastNo);
	} 
	else if(hazeIndex>=400)
	{
		if(control[1][week-1][LastNo]) printf("%d yes",LastNo);
		else printf("%d no",LastNo);
	}
	else
	{
		printf("%d no",LastNo);
	}
	return 0;
} 

int main1()
{
    int  week, hazeIndex, No; // ���ڼ�, ����ָ��, ���ƺ���
	int LastNo; // ���ƺ����һλ����
	int control=0; // 0��������; 1: ���� 
    
    scanf("%d%d%d",&week,&hazeIndex,&No);
    LastNo=No%10; 
	switch(week)
	{
		case 1: if(hazeIndex>=200 && hazeIndex<400 && (LastNo==1 || LastNo==6)) 
		        	control=1;
				if(hazeIndex>=400 && (LastNo%2 != 0)) 
				    control=1;  
		        break; 
		case 2: if(hazeIndex>=200 && hazeIndex<400 && (LastNo==2 || LastNo==7)) 
		            control=1;
		        if(hazeIndex>=400 && (LastNo%2 == 0)) 
				    control=1; 
		        break;
		case 3: if(hazeIndex>=200 && hazeIndex<400 && (LastNo==3 || LastNo==8)) 
		            control=1;
		        if(hazeIndex>=400 && (LastNo%2 != 0)) 
				    control=1; 
		        break; 
		case 4: if(hazeIndex>=200 && hazeIndex<400 && (LastNo==4 || LastNo==9))
		            control=1;
		        if(hazeIndex>=400 && (LastNo%2 == 0)) 
				    control=1; 
		        break;
		case 5: if(hazeIndex>=200 && hazeIndex<400 && (LastNo==5 || LastNo==0))
		            control=1;
		        if(hazeIndex>=400 && (LastNo%2 != 0)) 
				    control=1; 
		        break;
		case 6:
		case 7: break;
	} 
	if(control==1) printf("%d yes",LastNo);
	else printf("%d no",LastNo);
	return 0;
} 
