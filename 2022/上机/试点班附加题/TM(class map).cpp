#include<iostream>
#include<map>

using namespace std;


class FromState
{
  public:
  string state; // ��ǰ״̬, ��INIT״̬��ʼ��STOP״̬���� 
  char sigma;   // ������� 
  // Ϊ�˽�������Ϊmap��keyʹ��, �������ش˺����� 
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
  string state; // ��״̬ 
  char replace; // ������� 
  char move;    // ֽ���ƶ����� 
};

// ȫ�ֱ���, ��¼ͼ���ָ��������ַ�������ǰ״̬����дͷλ�� 
map<FromState,ToState>  mapStates; // ͼ���״̬��������ͼ���ָ�: ��ǰ״̬ ������� ������� ֽ���ƶ����� ��״̬ 
string input = ""; // ͼ��������ַ��� 
string currentState = "INIT"; // ��INIT״̬��ʼ 
string::iterator pos = input.end()-1; // ͼ�����дͷλ�ã���ʼʱָ��Input�����Ҷ� 

// ���Դ�ӡmapStates and input 
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

// �ӱ�׼�����ȡͼ���ָ�, ����C++��ֵ��mapStates����
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
    	// �����ֵ��mapStates����
    	mapStates.insert(pair<FromState,ToState>(k,v));
	}
	cin >> input; 
}

// ����ͼ���, ��INIT״̬��ʼ��STOP״̬����
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
		k.state=currentState; // ��ǰ״̬ 
		k.sigma=*pos; // ������� 
		v = mapStates[k]; // ��k���ӳ��Ŀ��v 
		currentState=v.state; // ���µ�ǰ״̬ 
		*pos=v.replace; // ��д��дͷָ���ֽ������Ϊ������� 
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

