#include<iostream>
#include<map>

using namespace std;


class FromState
{
  public:
  string state; // 当前状态 
  char sigma;   // 输入符号 
  // 为了用此类最为map的key使用, 必须重载此函数。 
  bool operator < (const FromState & t) const
  {
  	bool ret = true;
  	if (state == t.state) ret = (sigma < t.sigma) ? true : false;
  	else ret = (state < t.state) ? true : false;
  	return ret;
  }	
};

class ToState
{  
  public:
  string state; // 新状态 
  char replace; // 输出符号 
  char move;    // 纸带移动方向 
};

map<FromState,ToState>  mapStates; // 灵机状态机，描述图灵机指令集: 当前状态 输入符号 输出符号 纸带移动方向 新状态 
string input = ""; // 图灵机输入字符串 
string currentState = "INIT"; // 从INIT状态开始 
string::iterator pos = input.end()-1; // 指向Input的最右端 

// 测试打印mapStates and input 
void print()
{
	map<FromState,ToState>::iterator iter;
	iter = mapStates.begin();
	while(iter != mapStates.end()) 
	{
		cout << "FromState: " << iter->first.state << ", Input char: " << iter->first.sigma << endl; 
		cout << "ToState: " << iter->second.state << ", Output char: " << iter->second.replace << ", move: " << iter->second.move << endl; 
    	cout << "-------------" << endl;
		iter++;
    }
    cout << "Input: " << input << endl;
} 

// 生成图灵机状态机, 由键值对描述mapStates
// 图灵机输入: input 
void init()
{
    int n; // 图灵机指令数 
	FromState k; 
    ToState v;
    cin >> n; 
	for(int i=0; i<n; i++)
	{
    	cin >>  k.state >> k.sigma >> v.replace >> v.move >> v.state;
    	mapStates.insert(pair<FromState,ToState>(k,v));
	}
	cin >> input; 
}

void run()
{
	char inputchar;
	FromState k;
	ToState v;
	
	pos = input.end()-1; //指向input的最右端'#'  
	while(*pos == '#') pos--;
	
	//当前pos指向input的最右端'*' 
	
	while(currentState!="STOP")
	{
		k.state=currentState;
		k.sigma=*pos;
		v = mapStates[k];
		currentState=v.state;
		*pos=v.replace; // 指向的纸带方格重写 
		if(v.move == 'R') pos--; // 纸带右移 
		else if(v.move == 'L') pos++; // 纸带左移 
	}
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
int main()
{

	init();
	run(); 
	// print(); // 测试 
	
	// 输出纸带有效部分内容(两个分节符'*'之间的字符) 
	string::size_type leftpos = input.find('*') + 1;
	string::size_type rightpos = input.rfind('*') -1;
	cout << input.substr(leftpos,rightpos-leftpos+1) << endl; 
	
	return 0;	
}

