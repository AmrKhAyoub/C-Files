#include <iostream>
#include <string>
using namespace std;

char toHEX (int n)
{
    switch (n)
    {
        case 0 : return '0';
        case 1 : return '1';
        case 2 : return '2';
        case 3 : return '3';
        case 4 : return '4';
        case 5 : return '5';
        case 6 : return '6';
        case 7 : return '7';
        case 8 : return '8';
        case 9 : return '9';
        case 10 : return 'A';
        case 11 : return 'B';
        case 12 : return 'C';
        case 13 : return 'D';
        case 14 : return 'E';
        case 15 : return 'F';
    }
}

string decimalToHex (int n)
{
    int reminder;
    int newNumber = n;
    string hexadecimal = "";
    while (newNumber!=0)
    {
        reminder = newNumber % 16;
        hexadecimal += toHEX (reminder);
        newNumber = newNumber / 16;
    }
    reverse(hexadecimal.begin(),hexadecimal.end()); 
    return hexadecimal;
}

int main ()
{
    begin :
    int n;
    cout<<"---------------\n";
    cout<<"Enter Decimal Number : ";
    cin>>n;
    cout<<"Hexadecimal Number = "<< decimalToHex(n)<<endl;
    goto begin;
    
    return 0;
} 