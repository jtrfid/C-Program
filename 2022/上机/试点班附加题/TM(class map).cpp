#include<iostream>
#include<map>

using namespace std;


class FromState
{
  public:
  string state; // 当前状态, 以INIT状态开始，STOP状态结束 
  char sigma;   // 输入符号 
  // 为了将此类作为map的key使用, 必须重载此函数。 
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

// 全局变量, 记录图灵机指令集，输入字符串，当前状态，读写头位置 
map<FromState,ToState>  mapStates; // 图灵机状态机，描述图灵机指令集: 当前状态 输入符号 输出符号 纸带移动方向 新状态 
string input = ""; // 图灵机输入字符串 
string currentState = "INIT"; // 从INIT状态开始 
string::iterator pos = input.end()-1; // 图灵机读写头位置，开始时指向Input的最右端 

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

// 从标准输入读取图灵机指令集, 生成C++键值对mapStates集合
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
    	// 插入键值对mapStates集合
    	mapStates.insert(pair<FromState,ToState>(k,v));
	}
	cin >> input; 
}

// 运行图灵机, 从INIT状态开始至STOP状态结束
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
		k.state=currentState; // 当前状态 
		k.sigma=*pos; // 输入符号 
		v = mapStates[k]; // 由k获得映射目标v 
		currentState=v.state; // 更新当前状态 
		*pos=v.replace; // 重写读写头指向的纸带方格为输出符号 
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

