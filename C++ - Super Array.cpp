#include<iostream>
#include<string>
//#define size 5
using namespace std;
template <class type>

//IT'S AN ARRAY CREATED AS A CLASS
//THE IDEA BEHIND CREATING IT USING CLASS CONCEPTS 
//IS TO HAVE READY METHODS TO USE WITH THE ARRAY 

class  Array
{
    private :
    type *arr;
    public :
    //constructor to set size of the array
    Array (int size)
    {
     arr = new type [size];   
    }
    //function to insert the full Array
    void insert()
    {
    cout<<"Enter your Elements :\n";
    for (int i=0;i<size;i++)
        {
          cout<<"Element No."<<i+1<< " of "<<size<<" : ";
          cin>>arr[i];
        }
        
    }
    //function to insert an element knowning its index
    void insert(int index,type New)
    {
        arr[index]=New;
    }
    //function to display the full Array
    void display()
    {
        cout<<"Your Array is : [ ";
         for (int i=0;i<size;i++)
            { cout<<arr[i]<<", "; }
         cout<<"]\n";
    }
    //function to display element of index X
    void display(int index)
    {
        cout<<"Array["<<index<<"] = "<<arr[index]<<endl;
    }
    //function to display range of the array
    void display(int first,int last)
    {
        if (first>last || first<0 || last>=size)
        { cout<<"Error ! Unvalid Range !\n"; }
        else
        {
          cout<<"Your Range of Array is : [ ";
          for (int i=first;i<last;i++)
             { cout<<arr[i]<<", "; }
          cout<<"]\n";
        }
    }

    //function to sort the Array
    void sort()
    {
        for (int i=0;i<size;i++)
        {
          for (int s=i+1;s<size;s++)
           {
             if (arr[i]<arr[s])
                swap(i,s);
            }
        }
    }
    //function to reverse the order
    void reverse()
    {
        int times = round((float)size/2);
        for (int i=0;i<times;i++)
        {
            swap(i,((size-1)-i));
        }
    }
    //function to search for an element
    void find(type target)
    {
        int i;
        bool found = false;
        for ( i=0;i<size;i++)
         {
            if (target == arr[i])
            {
                found = true;
                break;
            }
         }
         if (found)
         {
            cout<<"Your Element is on Index No. "<<i<<endl;
         }
         else 
         {
            cout<<"Your Element Not Found !\n";
         }
    }
    //function to replace an element knowning its value
    void replace(type Old,type New)
    {
        for (int i=0;i<size;i++)
         {
            if (arr[i]==Old)
              arr[i] = New;
         }
    }
    //function to make all elements equal to one value
    void makeAllSame(type const sameVal)
    {
        for (int i=0;i<size;i++)
            arr[i]=sameVal;
    }
}; 


int main ()
{
    Array <int> array(5);
    array.insert();
    array.display();
    array.sort();
    array.display();
    
    return 0;
} 