#include<iostream> 
#define max 5
using namespace std; 
template <class type>
class Stack
{
    private :
    int top=-1;
    type stack[max];
    public :
    void print()
    {
        for (int i=max-1; i >= 0;i--)
        cout<<"| "<<stack[i]<<" |"<<endl;
    }
    bool isEmpty ()
    {
        return top < 0 ;
    }
    void push (type element)
    {
        if (top >= max-1)
        {
            cout<<"STACK IS ALREADY FULL !\n";
        }
        else 
        {
            top++;
            stack[top] = element;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
        cout<<"STACK IS EMPTY !\n";
        }
        else 
        {
        top--;
        }
    }
    void pop(type &element)
    {
        if (isEmpty())
        {
        cout<<"STACK IS EMPTY !\n";
        }
        else 
        {
        element = stack[top];
        top--;
        }
    }
    void getTop()
    {
        cout<<"Last Element : "<<stack[top]<<endl;
    }
};

int main ()
{
    Stack <int> stack; //choose the type by put it between the < >
	//you can test what you want 
    return 0;
}
