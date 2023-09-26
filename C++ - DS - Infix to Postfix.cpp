#include <iostream>
#include <string>
using namespace std;
///*** CODE TO CONVERT FROM INFIX INTO POSTFIX ***///
template <class type>
class Stack;
bool isOperator (char op); //to check if operator 
bool isHigher(char Old,char New); //to check if the new is higher than stack top

//to convert from Infix to Postfix
void postfix(string expression)
{
    int counter = 0;
    string part;
    string result ="";
    Stack <char> postfixStack;
    
    for (int i=0; i<expression.size();i++)
    {
        part = "";
        if (isOperator(expression[i]))
        {
            if (postfixStack.getTop()=='N' || postfixStack.getTop()=='(' || expression[i]=='(')
            {
                postfixStack.push(expression[i]);
                counter ++;
            }
            else if (expression[i]==')')
            {
                while (postfixStack.getTop()!='(' && postfixStack.getTop()!='N')
                {
                    postfixStack.pop(part);
                    result += part;
                    result +=" ";
                    counter--;
                }
                postfixStack.pop(); //to pop the (
                counter--;
                part="";
            }
            else if ( isHigher(postfixStack.getTop(),expression[i]) )
            {
                postfixStack.push(expression[i]);
                counter++;
            }
            else 
            {
                postfixStack.pop(part);
                counter--;
                postfixStack.push(expression[i]);
                counter++;
            }
        }//if that is an operator
        
        else
        {
            part = expression[i];
        }//if that a number
        
        result += part;
        result +=" ";
    }//for loop
    
    // to clear the stack
    while (counter != 0)
    {
        postfixStack.pop(part);
        result += part;
        result +=" ";
        counter--;
    }
    
    //print postfix
    cout<<"Postfix is = "<<result<<"\n";
}
///////////////////////////////////////
int main ()
{
    string expression;
    cout<<"--------------\n";
    cout<<"Infix Operation : ";
    cin>>expression;
    postfix(expression);
    
    main();
    
    return 0;
} 
///////////////////////////////////////
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
            cout<<"Error !!\n";
        else
        {
        newNode -> value = newElement;
        newNode -> next = top; //pointer of the new = old
        top = newNode; //top is the new
        }
    }

    //to delete an element with keeping the value of the element 
    void pop ()
    {
        if (isEmpty())
            cout<<"Can not Pop ! Stack Is Empty !\n";
        else 
        {
            node *tempNode = top;
            top = top -> next;
            delete tempNode;
        }
    }
    //to delete an element with keeping the value of the element 
    void pop (string &getTop)
    {
        if (isEmpty())
            cout<<"Can not Pop ! Stack Is Empty !\n";
        else 
        {
            getTop = top -> value ; //storing the value in a reference 
            node *tempNode = top;
            top = top -> next;
            delete tempNode;
        }
    }
    //to display return the top
    type getTop()
    {
        return this->isEmpty() ? 'N' : top->value; //N : null
    }
}; 

bool isOperator (char op)
{
    if (op=='*' || op=='/')
        return true;
    else if (op=='+' || op=='-')
        return true;
    else if (op=='(' || op==')')
        return true;
    else
        return false;
}

bool isHigher(char Old,char New)
{
    return ((Old=='+' || Old=='-') && (New=='*' || New=='/'));
}
