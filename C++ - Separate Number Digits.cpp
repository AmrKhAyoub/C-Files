#include <iostream> 
#include <cmath>
using namespace std; 
int main ()
{
    Begin :
    
    int number = 0;
    int reverse = 0;
    int digit = 0;
    int sum = 0;
    cout<<"-------------\n";
    cout<<"Enter Number :  ";
    cin>>number;
    number = abs(number);
    //reverse the number
    while (number!=0)
    {
        reverse = reverse * 10;
        reverse = reverse + (number % 10);
        number = number / 10;
    }
    //to print digita and sum
    cout<<"Digits = ";
    while (reverse!=0)
    {
        digit = reverse % 10;
        sum = sum + digit;
        cout<< digit << "  ";
        reverse = reverse / 10;
    }
    cout<<"\nSummation = "<< sum <<endl;
   
    goto Begin;
   
    return 0;
} 