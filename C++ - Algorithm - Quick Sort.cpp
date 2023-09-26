#include<iostream>
using namespace std; 

int partitioning (int arr[],int iBegin,int jEnd)
{
    int i = iBegin;
    int j = jEnd;
    int pivot = i;
    
    while (i < j)
    {
        do 
            i++;
        while (arr[pivot] > arr[i]);
        
        do 
            j--;
        while (arr[pivot] < arr[j]);
        
        if (i < j)
            swap(arr[i],arr[j]);
    }
    swap(arr[pivot],arr[j]);
    return j;
}

void QuickSort(int arr[],int left,int right)
{
    if (left < right)
    {
        int pivot = partitioning (arr,left,right);
        QuickSort(arr,left,pivot);
        QuickSort(arr,pivot+1,right);
    }
} 


void print(int arr[],int size)
{
	cout<<"Your Array = [ ";
	for (int i = 0;i<size;i++)
		cout<<arr[i]<<", ";
	cout<<" ]\n"<<endl;
}


int main ()
{
    system("color 3");
    int Array[] = {40,20,60,50,80,70,10};
    int size = sizeof (Array)/sizeof (Array[0]);
    cout<<"-----------\n";
    cout<<"Final Result :\n";
    QuickSort(Array,0,size);
    print(Array,size);
    cout<<"-----------\n";
    return 0;
} 
