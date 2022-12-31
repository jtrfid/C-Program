#include<iostream>
#include<cstdio>   // C++对应的C风格io库 
#include<stack> 
#include<string>  // C++ string 
#include<cstring> // C字符串处理 
#include<cmath> 
#include<map>

using namespace std;
map<string,string> mapState;
char input[101];
int pos=0; 
char currentState[21]="INIT";
char newState[21]="STOP";

char sigma,replace,move;

void run()
{
	char s[22];
	
	pos=strlen(input)-1;
	while(input[pos]=='#') pos--;
	sigma=input[pos];
	
	while(strcmp(currentState,"STOP")!=0)
	{
		s[0]=sigma; s[1]='\0'; 
	    strcat(s,currentState);		    
	    string r=mapState[s];
	    replace = r[0];
	    move = r[1];
	    
	    string news=r.substr(2);
	    strcpy(currentState,news.c_str());
	    
	    input[pos]=replace;
	    if(move == 'R') pos--;
	    else if(move == 'L') pos++;
	    sigma=input[pos];
	    
	    cout << sigma <<',' << replace << ',' << move <<','<< currentState << endl;
	    
	    cout << input << ',' << pos << endl;
	}
}
 
// 测试打印mapState and input 
void print()
{
	map<string,string>::iterator iter;
	iter = mapState.begin();
	while(iter != mapState.end()) 
	{
    	cout << iter->first << "," << iter->second << endl;
    	iter++;
    }
    cout << input << endl;
} 

void init()
{
	int n,i;
	char s1[21], s2[21],sigma1[2],sigma2[2],move[2]; 	 
	scanf("%d",&n); // 指令数 
	for(i=0;i<n;i++) // n条指令 
	{
		scanf("%s%s%s%s%s",s1,sigma1,sigma2,move,s2); // ADD 0 1 L RETURN
    	char ss1[22]="",ss2[22]="";
		strcat(ss1,sigma1); strcat(ss1,s1);
		strcat(ss2,sigma2); strcat(ss2,move); strcat(ss2,s2);
   		mapState.insert(pair<string,string>(ss1,ss2));
	}
	scanf("%s",input);
}

/*
12
INIT * * N START
START * * R ADD
ADD 0 1 L RETURN
ADD 1 0 R CARRY
ADD * * L STOP
CARRY 0 1 L RETURN
CARRY 1 0 R CARRY
CARRY * 1 R OVERFLOW
OVERFLOW # * L RETURN
RETURN 1 1 L RETURN
RETURN 0 0 L RETURN
RETURN * * N STOP
##########*101*##########
 */
int main()  // OK, C,C++混合, 太乱。 
{
	
	init();
	//print();
	run();
	return 0;	
}

/*
12
INIT * * N START
START * * R ADD
ADD 0 1 L RETURN
ADD 1 0 R CARRY
ADD * * L STOP
CARRY 0 1 L RETURN
CARRY 1 0 R CARRY
CARRY * 1 R OVERFLOW
OVERFLOW # * L RETURN
RETURN 1 1 L RETURN
RETURN 0 0 L RETURN
RETURN * * N STOP
##########*101*##########
 */
int main5()
{
	int n,i;
	char s1[21], s2[21],sigma1[2],sigma2[2],move[2]; 
	char input[101];
	 
	scanf("%d",&n);
	for(i=0;i<n;i++) // n条指令 
	{
		scanf("%s%s%s%s%s",s1,sigma1,sigma2,move,s2); // ADD 0 1 L RETURN
    	char ss1[22]="",ss2[22]="";
		strcat(ss1,sigma1); strcat(ss1,s1);
		strcat(ss2,sigma2); strcat(ss2,move); strcat(ss2,s2);
   		mapState.insert(pair<string,string>(ss1,ss2));
	}
	scanf("%s",input);
	
	map<string,string>::iterator iter;
	iter = mapState.begin();
	while(iter != mapState.end()) 
	{
    	cout << iter->first << "," << iter->second << endl;
    	iter++;
    }
    
    cout << input << endl;
	
	return 0;	
}

int main4()  // map
{
	map<string,string> mapState;
	
	char s1[21], s2[21],sigma1[2],sigma2[2],move[2];
	scanf("%s%s%s%s%s",s1,sigma1,sigma2,move,s2); // ADD 0 1 L RETURN
	// printf("%s,%s,%s,%s,%s\n",s1,sigma1,sigma2,move,s2);
    char ss1[22]="",ss2[22]="";
	strcat(ss1,sigma1); strcat(ss1,s1);
	strcat(ss2,sigma2); strcat(ss2,s2);
	cout << ss1 << "," << ss2 << endl;
	
    mapState.insert(pair<string,string>(ss1,ss2));
	
	map<string,string>::iterator iter;
	iter = mapState.begin();
	while(iter != mapState.end()) 
	{
    	cout << iter->first << "," << iter->second << endl;
    	iter++;
    }
	
	return 0;	
}

int main3() // string 2
{
	string s1="s1",s2="s2";
	char c1='#',c2='*';
	string ss1=c1+s1,ss2=c2+s2;
	char cc1=ss1.at(0);
     
	cout << ss1 << ',' << cc1 << '\n';
	return 0;	
}

int main2() // string 1
{
	string s="1234";
	char cs[100]="abcd";
	string s1(cs);
	cout << s << '\n';
	cout << s1 << '\n';
	return 0;	
}

int main1() // stack
{
	std::stack<int> s;
	printf("%d\n",s.empty());
	s.push(10);
	s.push(20);
	printf("%d\n",s.top());
	s.pop();
	printf("%d\n",s.top());
	
	return 0;
}

