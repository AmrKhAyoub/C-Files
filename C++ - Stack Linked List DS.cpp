#include <iostream> 
using namespace std; 
template <class type>
class Stack
{
    private :
    struct node //the node that has the val and the next node pointer 
    {
        type value; //the values
        node *next; //pointer of the next
    };
    node *top=NULL; //top of the Stack, and the last node in
    node *current; //pointer to handle display and delete
    public :
    //to check if stack is empty or not
    bool isEmpty()
    { 
        return top==NULL;
    }
    //to insert an element to the stack
    void push (type newElement)
    {
        node *newNode = new node; //to hold the new element
        if (newNode==NULL)
        {
            cout<<"Error !!\n";
        }
        else
        {
        newNode -> value = newElement;
        newNode -> next = top; //pointer of the new = old
        top = newNode; //top is the new
        }
    }
    //to delet an element 
    void pop ()
    {
        if (isEmpty())
        {
            cout<<"Stack Is Already Empty !\n";
        }
        else 
        {
            node *tempNode = top; //temp node to hold the last in
            top = top -> next; //top pointer points to the next
            delete tempNode;
        }
    }
    //to delete an element with keeping the value of the element 
    void pop (type &getTop)
    {
        if (isEmpty())
        {
            cout<<"Stack Is Already Empty !\n";
        }
        else 
        {
            getTop = top -> value ; //storing the value in a reference 
            node *tempNode = top;
            top = top -> next;
            delete tempNode;
        }
    }
    //to display last element or val on the top
    void getTop()
    {
        if (isEmpty())
        cout<<"Stack Is Empty !\n";
        else
        cout<<"The last in value : "<< top->value <<endl;
    }
    //to print all of the Stack 
    void display ()
    {
        if (isEmpty())
        {
            cout<<"Stack Is Empty !!\n";
        }
        else 
        {
        node *current = top ; //pointer to handle display
        cout<<"STACK Has Now : \n";
        while (current != NULL)
            {
            cout<<"| "<< current->value <<" |"<<endl;
            current = current->next ;
            }
        }
    }
}; 

int main ()
{
    Stack <int> stack; //creat the stack 
    //here we add 1-10 numbers to the stack
    stack.getTop();
    for (int i=1;i<=10;i++)
    {
        stack.push(i);
    }
    cout<<"---------------\n";
    stack.display(); //print the Stack
    cout<<"---------------\n";
    //delete last 3 elements
    for (int i=1;i<=3;i++)
    {
        stack.pop();
    }
    stack.getTop(); //print the top of the Stack
    cout<<"---------------\n";
    stack.pop(); //pop the top
    stack.display(); //now print the stack
    cout<<"---------------\n";
    return 0;
} 
