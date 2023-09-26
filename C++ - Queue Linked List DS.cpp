#include<iostream> 
using namespace std;
template <class type>
class Queue 
{
    private :
    struct node 
    {
        type value;
        node *next;
    }; 
    node *front = NULL;
    node *rear = NULL;
    int counter = 0;
    
    public :
    //to check if empty
    bool isEmpty ()
    {
        return counter == 0;
    }
    
    //to add to the Queue
    void enqueue (type newElement)
    {
        node *newNode = new node; //creating a new node to hold the new element
        newNode->value=newElement; //pass the element value to the node value
        newNode->next=NULL; //since it's last element, then it's points to NULL
       //now moving the rear
       if (isEmpty())
       {
           front = rear = newNode; //front and rear points to one node
       }
       else
       {
           rear->next = newNode;
           rear = newNode;
       }
        counter++;
    }

    //to delete from the Queue
    void dequeue ()
    {
        if (isEmpty())
        {
            cout<<"Can not delete ! Queue Empty !\n";
        }
        else if (counter==1)
        {
            front = rear = NULL;
            counter = 0;
        }
        else
        {
            node *tempNode = front;
            front = front->next;
            delete tempNode;
            if (front==NULL) //meanig the front is the last element
                rear=NULL;
            counter --;
        }
        
    }
    
    //to displaythe Queue 
    void display ()
    {
        if (isEmpty())
        {
            cout<<"Can not Display Empty Queue !\n";
        }
        else
        {
            node *current = front;           
            cout<<" Queue = [ ";
            while (current!=NULL)
            {
                cout << current->value << ", ";
                current = current->next;
            }
            cout<<"]\n";
        }
    }
    
    //to display the front
    void getFront()
    {
        if (isEmpty ())
        cout<<"Can not display Front ! Queue Empty !\n";
        else
        {
            cout<<"Front Element = "<< front->value <<endl;
        }
    }
    
    //to display the rear
    void getRear()
    {
        if (isEmpty ())
        cout<<"Can not display Rear ! Queue Empty !\n";
        else
        {
            cout<<"Rear Element = "<< rear->value <<endl;
        }
    }
    
    //to return size of the queue
    int getSize ()
    {
      return counter;
    }
    
}; 

int main ()
{
    Queue <int> queue;
    queue.enqueue (20);
    queue.enqueue(50);
    cout<<"size = "<<queue.getSize()<<endl;
    queue.display();
    queue.getRear();
    queue.dequeue();
    cout<<"size = "<<queue.getSize()<<endl;
    queue.getFront();
    
    return 0;
} 

