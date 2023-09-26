#include <iostream> 
using namespace std;
template <class type>
//Linked List - Doubly Type
class LinkedList
{
    private :
    struct Node 
    {
        type value;
        Node *next;
        Node *prev;
    };
    Node *first = NULL;
    Node *last = NULL;
    int counter = 0;
    public :
    //to check empty
    bool isEmpty ()
    {
        return counter == 0;
    }
    //to find the number of elements 
    int length()
    {
        return counter;
    }
    //to display first and last
    void getBoth ()
    {
        cout<<"First = "<<first->value<<endl;
        cout<<"Last = "<<last->value<<endl;
    }
    //to display the list
    void display ()
    {
        if (isEmpty())
        {
            cout<<"Can not Display Empty List !\n";
        }
        else
        {
            Node *current = first;
            cout<<"List = [ ";
            while (current!=NULL)
            {
                cout<< current->value <<", ";
                current = current->next;
            }
            cout<<"]\n";
        }
    }
    //to display the reversed list
    void displayReversed ()
    {
        if (isEmpty())
        {
            cout<<"Can not Display Empty List !\n";
        }
        else
        {
            Node *current = last;
            cout<<"Reversed List = [ ";
            while (current!=NULL)
            {
                cout<< current->value <<", ";
                current = current->prev;
            }
            cout<<"]\n";
        }
    }
    //to find index of specific element 
int find (type element)
{
    if (isEmpty())
        return -1;
    if (element == first->value)
        return 0;
    else if (element == last->value)
        return counter - 1;
    else
    {
        int index=1;
        Node *current = first->next;
        for (index=1 ; index < counter-1 ;index++)
        {
            if (current->value == element)
                return index;
            else
                current = current->next;
        }
    }
    return -1; //means not found 
}
    //to insert first
    void insertFirst (type newElement)
    {
        Node *newNode = new Node;
        newNode -> value = newElement;
        if (isEmpty())
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            first = last = newNode;
        }
        else
        {
            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;
            first = newNode;
        }
        counter ++;
    }
    //to insert last
    void insertLast (type newElement)
    {
        Node *newNode = new Node;
        newNode -> value = newElement;
        if (isEmpty())
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            first = last = newNode;
        }
        else
        {
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
        counter ++;
    }
    //to insert at postion
    void insertAt (int index,type newElement)
    {
        if (index<0 || index > counter)
        {
            cout<<"Out of Range... !\n";
        }
        else if (index==0)
        {
            insertFirst(newElement);
        }
        else if (index==counter)
        {
            insertLast(newElement);
        }
        else
        {
            Node *current = first;
            Node *newNode = new Node;
            newNode->value = newElement;
            for (int i=0; i<index-1 ;i++)
            {
                current = current->next;
            } 
            newNode->next = current->next;
            newNode->prev = current;
            current->next = newNode;
            counter ++;
        }
    }
    //to romve the first element 
    void removeFirst ()
    {
        if (isEmpty())
        {
            cout<<"Empty List Can not Delete !\n";
        }
        else if (counter==1)
        {
            delete first;
            first = last = NULL;
            counter = 0;
        }
        else
        {
            Node *tempNode = first;
            Node *current = first->next;
            current->prev = NULL;
            first = current;
            delete tempNode;
            counter --;
        }
    }
    //to romve the last element 
    void removeLast ()
    {
        if (isEmpty())
        {
            cout<<"Empty List Can not Delete !\n";
        }
        else if (counter==1)
        {
            delete last;
            first = last = NULL;
            counter = 0;
        }
        else
        {
            Node *tempNode = last;
            Node *current = last->prev;
            current->next = NULL;
            last = current;
            delete tempNode;
            counter --;
        }
    }
    //to remove at specific postion
    void removeAt (int index)
    {
        if (isEmpty())
            cout<<"Empty List Can not Delete !\n";
        else if (index<0 || index>=counter)
            cout<<"Out of Range... Only between 0 and"<<counter-1<<" !\n";
        else if (index == 0)
            removeFirst();
        else if (index == counter-1)
            removeLast();
        else
        {
           Node *current = first; 
           for (int i=1;i<=index;i++)
            {
                current = current->next;
            }
            (current->next)->prev = current->prev;
            (current->prev)->next = current->next;
            delete current;
            counter --;
        }
    }
    //to remove specific element
    void remove (type element)
    {
        if (isEmpty())
            cout<<"Empty List Can not Delete !\n";
        else if (find(element)==-1)
            cout<<"Your element NOT found\n";
        else
        {
            int elementIndex = find(element);
            removeAt(elementIndex);
        }
    }
}; 

int main ()
{
    LinkedList <int> linkedList;
    int i = 0;
    for (i=50 ; i>0 ; i-=10)
        linkedList.insertFirst(i);
    linkedList.display();
    
    for (i=10 ; i<=60 ; i+=10)
        cout<<i<< " - "<<linkedList.find(i)<<endl;
    
   
    
    return 0;
}