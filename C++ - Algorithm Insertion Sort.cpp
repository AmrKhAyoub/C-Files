#include <iostream> 
using namespace std;

void insertionSort(int arr[],int size)
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

void print (int arr[],int size)
{
    cout<<"Your Array is = [ ";
    for (int i=0;i<size;i++)
        cout<<arr[i]<<", ";
    cout<<"]\n";
}

int main ()
{
    int array [] = {90,70,30,50,40,80,20,10,60} ;
    int n = sizeof (array) / sizeof (array[0]);
    print(array,n);
    cout<<"---------------\n";
    insertionSort(array,n);
    print(array,n);
    return 0;
} 