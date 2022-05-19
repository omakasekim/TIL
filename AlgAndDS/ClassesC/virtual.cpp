//? Virtual Functions Are Methods in a parent class that is defined, but meant to be overloaded by child class
//? prefix virtual is used.



//? Why is it used?

//C is a compiled language, and memory location is bound at compile time.
//Sometimes we dont want that, so virtual is bound at runtime.

#include <iostream>
using namespace std;

class Parent{
public:
    /*virtual*/ void print() {
        cout << "이곳은 Parent입니다." << endl;
    }
};

class Child : public Parent{
public:
    void print() {
        cout << "이곳은 Child입니다." << endl;
    }
};

void main() {
    Parent* p = new Parent;
    Child* c = new Child;
    
    p->print();
    p = c;
    p->print();
}