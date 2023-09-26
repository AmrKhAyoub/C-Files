#include <iostream> 
using namespace std; 
//FRACTIONS CODE USING  OPERATOR
class Fraction
{
    private :
    int A; // Numerator 
    int B; // Denominator
    public :
    //Constructor 
    Fraction (int A=1,int B=1) : A(A) , B(B) 
    {
        if(B==0)
            this->B = 1;
    }                                         
    //Print Method
    void print()
    {
        cout<<"("<<A<<"/"<<B<<")";
    }
    //Print with () operator
    void operator () ()
    {
        this->print();
    }
    //Set values
    void operator () (int A,int B)
    {
        this->A = A;
        this->B = B==0 ? 1 : B;
    }
    //Equal
    void operator = (Fraction ob)
    {
        this->A = ob.A;
        this->B = ob.B;
    }
    //Add
    Fraction operator + (Fraction ob)
    {
        Fraction result;
        //body of the Add
        if (this->B==ob.B)
        {
            result.A = this->A + ob.A;
            result.B = this->B;
        }
        else 
        {
            result.A = (this->A * ob.B) + (ob.A * this->B);
            result.B = this->B * ob.B;
        }
        return result;
    }
    //Substrac
    Fraction operator - (Fraction ob)
    {
        Fraction result;
        //body of the Sub
        ob.A= -ob.A;
        if (this->B == ob.B)
        {
            result.A = this->A + ob.A;
            result.B = this->B;
        }
        else 
        {
            result.A = (this->A * ob.B) + (ob.A * this->B);
            result.B = this->B * ob.B;
        }
        return result;
    }
    //Multiplication 
    Fraction operator * (Fraction ob)
    {
        Fraction result;
        //body of Multiplication 
        result.A = this->A * ob.A;
        result.B = this->B * ob.B;
        return result;
    }
    //Dividing
    Fraction operator / (Fraction ob)
    {
        Fraction result;
        //body of Dividing 
        result.A = this->A * ob.B;
        result.B = this->B * ob.A;
        return result;
    }
};
int main ()
{
    Fraction x;
    Fraction first(1,4);
    Fraction second(3,4);
    x = first + second; x();
    x = first - second; x();
    x = first * second; x();
    x = first / second; x();
    
    return 0;
}
