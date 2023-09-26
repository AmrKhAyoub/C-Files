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
    stack <char> testStack;
    for (int i=0; i<sentence.size() ;i++)
    {
        if (sentence[i]=='(' || sentence[i]=='{' || sentence[i]=='[')
            testStack.push(sentence[i]);
        else if (sentence[i]==')' || sentence[i]=='}' || sentence[i]==']')
        {
            if (testStack.empty() || !arePair(testStack.top(),sentence[i]))
                return false;
            else
                testStack.pop();
        } //else if
    } //for loop
    
    return testStack.empty();
}

int main ()
{
    string sen;
    cout<<"---------------------\n";
    cout<<"Enter Expression : ";
    cin>>sen;
    areBalanced(sen) ? cout<<"Balanced \n" : cout<<"NOT Balanced \n";
    
    main();
    return 0;
} 