#include <iostream>

//?Classes? a template to create instances of defined objects in OOP.
// functions defined within Classes are called Methods,
// variables defined within Classes are called Members.

// A extension to struct in C

// access modifiers

// public = accessable from anywhere (even from ouside the class)
// private = only class methods have access
// protected = usually same as private, but derived classes have access

class ClassName
{
private:
    int MemberVariable;

public:
    int MemberFunction()
    {
        return this->MemberVariable;
    }
};

int main()
{
    ClassName testClass = ClassName();
    testClass.MemberFunction();
}


class ExtraClass{
    private:
        int data;
    public:
        ExtraClass(){
            this->data = 123;
        }
        //Constructor overloading
        ExtraClass(int n){
            this->data = n;
        }
        //Destructor
        ~ExtraClass(){
            std::cout << "Destructor called" << std::endl;
        }
};


class ExtraExtraClass : public ExtraClass {
//Class Inheritance
};