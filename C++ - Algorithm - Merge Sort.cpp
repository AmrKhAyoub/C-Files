#include <iostream> 
using namespace std; 
void print(int arr[],int size)
{
	cout<<"Your Array :\n";
	for (i = 0;i<size;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}
int main ()
{
    int first[] = {1,4,6,8};
    int firstSize = sizeof (first)/sizeof (first[0]);
    
    int second[] = {2,3,7,9};
    int secondSize = sizeof (second)/sizeof (second[0]);
    
    int kSize = firstSize + secondSize ;
    int K [kSize];
    
    //Merge Sort
    int i = 0,j = 0;
    while (i<firstSize && j<secondSize) 
    {
        if (first[i] <= second[j])
        {
            K[k] = first[i];
            i++;
        }
        else
        {
            K[k] = second[j];
            j++;
        }
        k++;
    }
    while (i<firstSize)
    {
        K[k] = first[i];
        i++;
        k++;
    }
    while (j<secondSize)
    {
        K[k] = second[j];
        j++;
        k++;
    }
    print(K,kSize);
    return 0;
} 