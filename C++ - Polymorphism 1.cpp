#include <iostream> 
using namespace std;
class Poly
{
    protected :
    int length;
    int width;
    public :
    void setData (int l,int w)
    {
        length = l;
        width = w;
    }
    virtual int area() = 0;
    void printArea()
    {
        cout<<"Area = "<< this->area()<<endl;              
    }
};

class Square : public Poly
{
    int area()
    {
        return length*width;
    }
    
};

class Rectangle : public Poly
{
    int area()
    {
        return length*width;
    }
    
};

int main ()
{
    Rectangle rect;
    Square sqr;
    Poly *P[2] = {&sqr,&rect};
    
    P[0]->setData(5,5);
    P[0]->printArea();
    P[1]->setData(2,5);
    P[1]->printArea();
    
    return 0;
} 