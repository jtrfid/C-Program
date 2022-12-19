#include <iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
    int data;
    Node *next;
}node;

typedef struct Node1{
    int data;
    int a;
}node1;

node* CreatList(int n)
{
    node *p=NULL; 
    //node *temp=(node *)malloc(sizeof(node *)); // 错误 
    node *temp=(node *)malloc(sizeof(node)); // 正确 
    temp->data=0;
    temp->next=NULL;
    p=temp;
    for(int i=1;i<n;i++)
    {
        //node *a = (node *)malloc(sizeof(node *)); // 错误 
        node *a = (node *)malloc(sizeof(node)); // 正确 
        a->data=i;
        a->next=NULL;  
        temp->next=a;
        temp = temp->next;
    }
    return p;
}

void PrintList(node *p)
{
    node *q=p;
    do{
        cout<<q->data<<endl;
        q=q->next;
    }while(q!=NULL);
}


int main()
{
    // 16，8，4，8 
	printf("%d,%d,%d,%d\n",sizeof(node),sizeof(node *),sizeof(int),sizeof(int *));
	printf("%d,%d\n",sizeof(struct Node1),sizeof(node1 *));
	node *p=NULL;
    p=CreatList(23);
    PrintList(p);
}
