#include <iostream>
using namespace std;

class Employee 
{
    protected :
    string name;
    string job;
    string address;
    int age;
    int salary;
    public :
    Employee ()
    {
        name = "";
        job = "";
        address = "";
        age = 0;
        salary = 0;
    }
    Employee (string name,string job, string address,int age,int salary)
    {
        this->name = name;
        this->job = job;
        this->address = address;
        this->age = age;
        this->salary = salary;
    }
    
    void printData ()
    {
        cout<<"Employee Data :- "<<endl;
        cout<<"-------------"<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Job : "<<job<<endl;
        cout<<"Address : "<<address<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Salary : "<<salary<<endl;
        cout<<"--------------"<<endl;
    }
    
};

class Programmer : public Employee 
{
    public :
    Programmer ()
    {
        
    }
    Programmer (string name,string job, string address,int age,int salary) : Employee (name,job,address,age,salary)
    {
        
    }
    
};
class Doctor : public Employee 
{
    public:
    Doctor ()
    {
        
    }
    Doctor (string name,string job, string address,int age,int salary) : Employee (name,job,address,age,salary)
    {
        
    }
    
};
class Player : public Employee 
{
    public:
    Player ()
    {
        
    }
    Player (string name,string job, string address,int age,int salary) : Employee (name,job,address,age,salary)
    {
        
    }
    
};

int main() 
{
    system("color 3");
    Programmer amr("Amr KH Ayoub","Flutter Developer","Remotely in London",19,10000);
    Doctor ahmed("Ahmed Ayoub","Doctor","Future Hospital",29,20000);
    Player messi("Leo Messi","GOAT","FC Barcelona",36,500000);
    
   Employee *emp[] = {&amr,&ghaidaa,&messi};
    int n = sizeof(emp)/sizeof(emp[0])
    for (int i=0; i<n; i++)
    {
        emp[i]->printData();
    } 
   
    return 0;
} 