#include<iostream>
#include<map>

using namespace std;

typedef struct fromState
{
  string state; // ��ǰ״̬ 
  char sigma;   // ������� 
  string key; // key=sigma+state;  for map<key,value> 
} FromState;

typedef struct toState
{  
  string state;  // ��״̬ 
  char replace;  // ������� 
  char move;     // ֽ���ƶ����� 
} ToState;

map<string,ToState>  mapStates; // ���״̬��������ͼ���ָ�: ��ǰ״̬ ������� ������� ֽ���ƶ����� ��״̬ 
string input = ""; // ͼ��������ַ��� 
string currentState = "INIT"; // ��INIT״̬��ʼ 
string::iterator pos = input.end()-1; // ָ��Input�����Ҷ� 

// ���Դ�ӡmapStates and input 
void print()
{
	map<string,ToState>::iterator iter;
	iter = mapStates.begin();
	while(iter != mapStates.end()) 
	{
		cout << "FromState: " << iter->first.substr(1) << ", Input char: " << iter->first[0] << endl; 
		cout << "ToState: " << iter->second.state << ", Output char: " << iter->second.replace << ", move: " << iter->second.move << endl; 
    	cout << "-------------" << endl;
		iter++;
    }
    cout << "Input: " << input << endl;
} 

// ����ͼ���״̬��, �ɼ�ֵ������mapStates
// ͼ�������: input 
void init()
{
    int n; // ͼ���ָ���� 
	FromState k; 
    ToState v;
    cin >> n; 
	for(int i=0; i<n; i++)
	{
    	cin >>  k.state >> k.sigma >> v.replace >> v.move >> v.state;
    	k.key=k.sigma+k.state;
    	mapStates.insert(pair<string,ToState>(k.key,v));
	}
	cin >> input; 
}

// ����ͼ��� 
void run()
{
	char inputchar;
	FromState k;
	ToState v;
	
	pos = input.end()-1; //ָ��input�����Ҷ�'#'  
	while(*pos == '#') pos--;
	
	//��ǰposָ��input�����Ҷ�'*' 
	
	while(currentState!="STOP")
	{
		k.state=currentState;
		k.sigma=*pos;
		v = mapStates[k.sigma+k.state];
		currentState=v.state;
		*pos=v.replace; // ָ���ֽ��������д 
		if(v.move == 'R') pos--; // ֽ������ 
		else if(v.move == 'L') pos++; // ֽ������ 
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
	// print(); // ���� 
	
	// ���ֽ����Ч��������(�����ֽڷ�'*'֮����ַ�) 
	string::size_type leftpos = input.find('*') + 1;
	string::size_type rightpos = input.rfind('*') -1;
	cout << input.substr(leftpos,rightpos-leftpos+1) << endl; 
	
	return 0;	
}


