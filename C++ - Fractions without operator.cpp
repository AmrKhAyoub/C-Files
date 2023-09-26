#include <iostream>
using namespace std;
class Fraction
{
    private:
    int A; //البسط
    int B; //المقام
    public:
    // constructor to set values
    Fraction (int A, int B): A(A),
    B(B) {}
    // to print the fraction
    void print() {
        cout<<"("<<A<<"/"<<B<<")\n";
    }
    //ADD فانكشن بتجمع الكسرين ولازم تستقبل الكسرين
    void add (Fraction ob1, Fraction ob2) {
        //نجمع كسور عادي لكن نشوف المقامات موحدة ولالا اول
        if (ob1.B == ob2.B) {
            A = ob1.A + ob2.A;
            B = ob1.B;
        }
        else
        {
            A = (ob1.A * ob2.B) + (ob1.B * ob2.A);
            B = ob1.B * ob2.B;
        }
        //نظهر نتيجة الجمع
        print();
    }
    //SUBSTRACTION
    void sub (Fraction ob1, Fraction ob2) {
        //لأنو الطرح هو جمع بس التاني بيكون سالب
        // ف نغير اشارة الكسر التاني لسالب ونجمع عادي
        ob2.A = - ob2.A;
        add(ob1, ob2);
    }
    //MULTIPLICATION
    void mult (Fraction ob1, Fraction ob2) {
        A = ob1.A * ob2.A;
        B = ob1.B * ob2.B;
        print(); //print the result
    }
    //DIVIDING
    void divide (Fraction ob1, Fraction ob2) {
        //القسمة هى الضرب في مقلوب الكسر التاني
        A = ob1.A * ob2.B;
        B = ob1.B * ob2.A;
        print(); //print the result
    }

};

int main () {
    Fraction ob1(3, 2); // first fraction
    Fraction ob2(4, 9); //second fraction
    Fraction result(1, 1); //third fraction to he the calculations

    //test the operations
    result.add(ob1, ob2); //جمع
    result.sub(ob1, ob2); //طرح
    result.mult(ob1, ob2); //ضرب
    result.divide(ob1, ob2); //قسمة

    return 0;
}