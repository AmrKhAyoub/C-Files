#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool arePair(char open,char close)
{
    if (open=='(' && close==')')
        return true;
    else if (open=='{' && close=='}')
        return true;
    else if (open=='[' && close==']')
        return true;
    else
        return false;
}

bool areBalanced  (string sentence)
{
    stack <char> test;
    for (int i=0; i<sentence.size() ;i++)
    {
        if (sentence[i]=='(' || sentence[i]=='{' || sentence[i]=='[')
        {
            test.push(sentence[i]); 
        }
        else if (sentence[i]==')' || sentence[i]=='}' || sentence[i]==']')
        {
            if (test.empty() || !arePair(test.top(),sentence[i]))
            {
                return false;
            }
            else
            {
                test.pop();
            } // else
        } //else if
    } //for loop
    
    return test.empty();
}

int main ()
{
    
    string sen;
    cout<<"Enter Expression : ";
    cin>>sen;
    areBalanced(sen) ? cout<<"Balanced \n" : cout<<"NOT Balanced \n";
    
    main();
    return 0;
} 