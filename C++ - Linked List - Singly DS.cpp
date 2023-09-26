#include <iostream> 
using namespace std;
template <class type>
//Linked List - Singly Type
class LinkedList
{
    private :
    struct node 
    {
        type value;
        node *next;
    };
    node *first = NULL;
    node *last = NULL;
    int counter = 0;
    
    public :
    //to check empty
    bool isEmpty ()
    {
       return counter == 0; 
    }
    //to return size
    int getSize ()
    {
        return counter;
    }
    //to display first and last
    void getBoth()
    {
        cout<<"First = "<<first->value<<endl;
        cout<<"Last = "<<last->value<<endl;
    }
    //to display the elements
    void display ()
    {
        if (isEmpty())
        {
            cout<<"Can not Display Empty List !\n";
        }
        else
        {
            node *current = first;
            cout<<"List is : [ ";
            while (current!=NULL)
            {
                cout<< current->value <<", ";
                current = current->next;
            }
            cout<<"]\n";
        }
        
    }
    //to insert from beginning
    void insertFirst (type newElement)
    {
        node *newNode = new node;
        newNode->value = newElement;
        if (isEmpty())
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = first;
            first = newNode;
        }
        counter ++;
    }
    //to insert from the last
    void insertLast (type newElement)
    {
        node *newNode = new node;
        newNode->value = newElement;
        if (isEmpty())
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else
        {
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
        counter ++;
    }
    //to insert at postion
    void insertAt(int index,type newElement)
    {
        if (index<0 || index>counter)
            cout<<"Out of Range... !\n";
        else if (index==0)
            insertFirst(newElement);
        else if (index==counter)
            insertLast(newElement);
        else
        {
            node *current = first;
            node *newNode = new node;
            newNode->value = newElement;
            for (int i=0;i<index;i++)
                current = current->next;
            newNode->next = current->next;
            current->next = newNode;
            counter ++;
        }
    }
    //to remove specific value
    void remove (type element)
    {
        if (isEmpty())
        {
            cout<<"Empty List Can not Delete !\n";
        }
        else if (element == first->value)
        {
            removeFirst();
        }
        else if (element == last->value)
        {
            removeLast();
        }
        else
        {
            node *current = first->next;
            node *previous = first;
           while (current->next!=NULL)
            {
                if (current->value == element)
                {
                    current = previous->next;
                    previous -> next = current->next;
                    delete current;
                    counter --;
                    return;
                }
                previous = current;
                current = current->next;
            }
            cout<<"Your element NOT found\n";
        }
    }
    //to remove first postion
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
           node *tempNode = first;
           first = first->next;
           delete tempNode;
           counter --;
        }
    }
    //to remove last postion
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
           node *current = first; //will arrive pre last node 
           node *tempNode = first; //will arrive the last node 
           for (int i=1;i<counter-1;i++)
            {
                current = current->next;
            }
            tempNode = current->next;
            current -> next = NULL;
            last = current;
            delete tempNode;
            counter --;
        }
    }
    //to remove at some postion
    void removeAt (int index)
    {
        if (isEmpty())
        {
            cout<<"Empty List Can not Delete !\n";
        }
        else if (index<0 || index>=counter)
        {
            cout<<"Out of Range...!\n";
        }
        else if (index == 0)
        {
            removeFirst();
        }
        else if (index == counter-1)
        {
            removeLast();
        }
        else
        {
           node *current = first; //will arrive pre last node 
           node *tempNode = first; //will arrive the last node 
           for (int i=1;i<index;i++)
           {
                current = current->next;
           }
            tempNode = current->next;
            current -> next = tempNode->next;
            delete tempNode;
            counter --;
        }
    }
    //to search for an element 
    void search (type target)
    {
        if (isEmpty())
        {
            cout<<"Empty List Can not Search !\n";
        }
        else if (target == first->value)
        {
            cout<<"Element found in postion (0) ";
            cout<<"and it's the first\n";
        }
        else if (target == last->value)
        {
            cout<<"Element found in postion (";
            cout<<counter-1<<") and it's the last\n";
        }
        else
        {
            node *current = first->next;
            int i=1;
            while (current->next!=NULL)
            {
                if (current->value == target)
                {
                    cout<<"Element found in postion ("<<i<<")\n";
                    return;
                }
                i++;
                current = current->next;
            }
            cout<<"Your element NOT found\n";
        }
    }
    
    //to reverse the sort 
    void reverse ()
    {
        if (isEmpty())
        {
            cout<<"Can not Reverse Empty List ! \n";
        }
        else
        {
           node *previous = NULL;
           node *current = first;
           node *Next = current->next;
           while (Next!=NULL)
            {
                Next = current->next;      
                current->next = previous;
                previous = current;
                current = Next;
            }
            node *temp = last;
            last = first;
            first = last;
            first = previous;
        }
    }
}; 

int main ()
{
    LinkedList <int> linkedList;
    linkedList.insertAt(0,10);
    linkedList.insertAt(1,20);
    linkedList.insertAt(2,30);
    linkedList.insertAt(3,40);
    linkedList.insertAt(4,50);
    linkedList.insertLast(100);
    linkedList.display();
    linkedList.getBoth();
    linkedList.remove(10);
    linkedList.display();
    linkedList. search(50);
    linkedList.reverse();
    linkedList.display();
    linkedList. search(50);
    linkedList.getBoth();
    
    return 0;
} 
