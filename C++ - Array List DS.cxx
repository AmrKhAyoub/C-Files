#include <iostream>
using namespace std; 
template <class type>
class ArrayList 
{
    private:
    type *arr;
    int max;
    int length;
    public:
    ArrayList(int max)
    {
        this -> max = max;
        arr = new type [max];
        length = 0;
    }
    bool isEmpty ()
    {
        return length == 0;
    }
    bool isFull ()
    {
        return length == max ;
    }
    int getSize()
    {
        return length;
    }
    void insertAt (int index,type element)
    {
        if (isFull())
        {
            cout<<"Can not Insert, List is Full !\n";
        }
        else if (index>=max || index<0)
        {
            cout<<"Out of Range !\n";
        }
        else //if valid
        {
            for (int i = length ; i > index; i--) 
                arr[i]=arr[i-1];
            arr[index] = element;
            length ++;
        }
    }
    void removeAt (int index)
    {
        if (isEmpty())
        {
            cout<<"Can not Remove, List is Empty !\n";
        }
        else if (index>=max || index<0)
        {
            cout<<"Out of Range !\n";
        }
        else //if valid
        {
            for (int i = index ; i < length; i++) 
                arr[i]=arr[i+1];
            length --;
        }
    }
    void display()
    {
        if (isEmpty())
        cout<<"Can not Display, List is Empty !\n";
        else 
        {
            cout<<"[ ";
            for (int i=0;i<length;i++)
                cout<<arr[i]<<", ";
            cout<<"]\n";
        }
    }
};

int main ()
{
    ArrayList <int> list(10);
    list.removeAt(5);
    list.display();
    list.insertAt(0,10);
    list.insertAt(1,30);
    list.insertAt(2,40);
    list.insertAt(3,50);
    list.insertAt(4,60);
    list.display();
    list.insertAt(1,20);
    list.display();
    list.removeAt(1);
    list.display();
    
    return 0;
} 