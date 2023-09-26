#include <iostream>
using namespace std;
int i;
void insert(int arr[],int size)
{
    cout<<"Enter Your Array :\n";
	for (i = 0;i<size;i++)
		cin>>arr[i];
}
void print(int arr[],int size)
{
	cout<<"Your Array :\n";
	for (i = 0;i<size;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}
void selection(int arr[],int size)
{
   for (i=0;i<size;i++)
    {
     for (int s=i+1;s<size;s++)
        {
            if (arr[i]<arr[s])
            swap (arr[i],arr[s]);
        }
    }
}

int main() {
  int k[5];
  int n=5;
   insert(k,n);
   cout<<"Before :";
   print(k,n);
   selection(k,n);
   cout<<"After : ";
   print(k,n);
}
