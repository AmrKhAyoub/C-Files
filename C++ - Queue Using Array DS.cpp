#include<iostream>
#include<string>
#define size 5
using namespace std;
template <class type>

class Queue
{
    private :
    type arr[size];
    int front=0;
    int rear=size-1;
    int count=0;
    public :
    //to check if empty 
    bool isEmpty ()
    {
        return count==0;
    }
    //to check if full
    bool isFull ()
    {
        return count==size;
    }
    //to get front
    void getFront ()
    {
        cout<<"Front element = ["<<arr[front];
        cout<<"] and the Index is ("<<front<<")"<<endl;
    }
    //to get rear
    void getRear ()
    {
        cout<<"Rear element = ["<<arr[rear];
        cout<<"] and the Index is ("<<rear<<")"<<endl;
    }
    //to search for element
    void find (type target)
    {
        bool found = false;
        int i;
        for (i=front; i!=rear;i=(i+1)%size)
            {
                if (target==arr[i])
                {
                found=true;
                break;
                }
            }
       if (found)
       cout<<"Index of the Element is "<<i<<endl;
       else
       cout<<"Element Not Found !\n";
    }
    //to print the Queue
    void display ()
    {
        if (front==rear)
            cout<<"Front and Rear is "<<arr[front]<<endl;
        else
        {
            cout<<"Queue = [ ";
            for (int i=front; i!=rear;i=(i+1)%size)
            {
                cout<<arr[i]<<", ";
            } 
            cout<<arr[rear]<<"]\n";
        }
    }
    //to add element
    void enqueue (type newElement)
    {
        if (isFull())
        cout<<"Sorry Queue Is Full !\n";
        else
        {
            count++;
            rear=(rear+1)%size;
            arr[rear]=newElement;
        }
    }
    //to delete element
    void dequeue ()
    {
        if (isEmpty())
        cout<<"Sorry Queue Is Empty !\n";
        else
        {
            count--;
            front=(front+1)%size;
        }
    }
};

int main ()
{
    Queue <char> queue;
 //   queue.display();
    cout<<"---------\n";
    queue.enqueue('A');
    queue.enqueue('B');
    queue.enqueue('C');
    queue.enqueue('D');
    queue.enqueue('E');
    queue.enqueue('F');
    queue.display();
    cout<<"---------\n";
    queue.dequeue();
    queue.dequeue();
    queue.enqueue ('M');
    queue.display ();
    queue.getFront();
    queue.getRear();
    queue.find('G');
    cout<<"---------\n";

    return 0;
}