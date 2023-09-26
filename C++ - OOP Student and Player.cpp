#include <iostream>
#include<stdlib.h>
using namespace std;
class Person //Abstract Class 
{
    protected :
    int id;
    string name;
    public :
    void setID ()
    {
        cout<<"Enter ID : ";
        cin>>id;
        if (id <= 0)
        {
            cout<<"ID must be > 0 ! Try again !"<<endl;
            setID();
        }
    }
    void setName ()
    {
        cout<<"Enter Name : ";
        cin>>name;
    }
    virtual void printData ()=0;
}; 

class Student : public Person
{
    private:
    int age;
    public :
    void setAge ()
    {
        cout<<"Enter Age : ";
        cin>>age;
        if (age < 7 or age >30)
        {
            cout<<"Invalid Age ! Try again !"<<endl;
            setAge();
        }
    }
    void printData () override 
    {
        cout<<"---------"<<endl;
        cout<<"STUDENT DATA :-"<<endl;
        cout<<"---------"<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"---------"<<endl;
    }
};

class Player : public Person
{
    private:
    int number;
    public:
    void setNumber ()
    {
        cout<<"Enter Number : ";
        cin>>number;
        if (number > 99 or number < 1)
        {
            cout<<"Player number must be 1-99 ! Try again !"<<endl;
            setNumber();  
        }
    }
    void printData () override 
    {
        cout<<"---------"<<endl;
        cout<<"PLAYER DATA :-"<<endl;
        cout<<"---------"<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Number : "<<number<<endl;
        cout<<"---------"<<endl;
    }
};



int main() 
{
    system("color 3");
    Student amr;
    Player messi;
    //Polymorphism 
    Person *poly[2] = { &amr , &messi};
    
    for (int i=0; i<2 ; i++)
    {
        poly[i]->setID();
        poly[i]->setName();
    }
    amr.setAge();
    messi.setNumber();
    
    poly[0]->printData();
    poly[1]->printData();
    
    return 0;
} 

