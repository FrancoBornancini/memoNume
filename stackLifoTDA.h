#include <iostream>
 
using namespace std;
 
class Stack
{
private:
    int *p;
    int top,length;
 
public:
    Stack(int = 0);
    ~Stack();
 
    void push(int);
    int pop();
    int getTop();
    bool isEmpy();
    bool isFull();
};
 
Stack::Stack(int size)
{
    top=-1;
    length=size;
    if(size == 0)
        p = 0;
    else
        p=new int[length];
}
 
Stack::~Stack()
{
    if(p!=0)
        delete [] p;
}
 
void Stack::push(int elem)
{
    if(p == 0)                //If the stack size is zero, allow user to mention it at runtime
    {
        cout<<"ERROR: Stack of zero size"<<endl;
        cout<<"Enter a size for stack : ";
        cin >> length;
        p=new int[length];
    }
    if(top==(length-1))     //If the top reaches to the maximum stack size
    {
        cout<<"\nERROR: Cannot push "<<elem<<", Stack full"<<endl;
        return;
    }
    else
    {
        top++;
        p[top]=elem;
    }
}
int Stack::pop()
{
    if(p==0 || top==-1)
    {
        cout<<"ERROR: Stack empty!";
        return -1;
    }
    int ret=p[top];
    top--;
    return ret;
}
 
int Stack::getTop()
{
    return p[top];
}

bool Stack::isEmpy()
{
    if(p==0 || top==-1)
    {
        return true;
    }
    else
    {
    	return false;
	}
}

bool Stack::isFull()
{
	if(top==(length-1))     //If the top reaches to the maximum stack size
    {
        return true;
    }
    else
    {
    	return false;
	}
}
