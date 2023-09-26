#include<iostream> 
#define Size 6
using namespace std;
//function to sort a linear array
void selection(int arr[],int size)
{
   for (int i=0;i<size;i++)
   {
     for (int s=0;s<size;s++)
     {
       if (arr[i]<arr[s])
       {
         arr[i] ^= arr[s];
         arr[s] ^= arr[i];
         arr[i] ^= arr[s];
       }
     }
   }
}

int main ()
{
    int arr[Size]={30,50,10,60,50,40};
    int first = 0;
    int last = Size-1;
    int middle,target;
    bool found = false;
    
    //here we ask the user to insert the target number
    cout<<"Enter your number : ";
    cin>>target;
    
    //firstly we sort the array
    selection(arr,Size);
    
    //now we search for the key
    do
    {
    //here we calculate the middel key
    middle = (first + last)/2;
    //here we compare 
    if (target < arr[middle])
        last = middle-1;
    else if (target > arr[middle])
        first = middle+1;
    else 
        found = true;
    }
    while (found == false && first != last);
    //here we print the result
    found ? cout<<"Key is : "<<middle<<endl : cout<<"Not Found !\n";
    return 0;
}
