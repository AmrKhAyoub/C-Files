#include <iostream>
using namespace std;
class Author {
    public:
    string name;
    string gender;

    //constructor
    Author () {
        name = "";
        gender = "";
    }
    Author (string name, string gender) {
        this -> name = name;
        this -> gender = gender;
    }

    void showAuthorDetails() {
        cout<<name<<" / "<<gender<<endl;
    }
};
class Book {
    public:
    string name;
    int pages;
    int price;
    Author author;

    //constructor
    Book(string name, int pages, int price, Author author) {
        this -> name = name;
        this -> pages = pages;
        this -> price = price;
        this -> author = author;
    }

    void showBookDetail() {
        cout<<"BOOK DETAILS :"<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Pages : "<<pages<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"Author : ";
        author.showAuthorDetails();
    }
};



int main () {
    Author arthur("Arthur Conan", "male");
    Book scarlet("A Study in Scarlet", 200, 1600, arthur);
    scarlet.showBookDetail();
    return 0;
}