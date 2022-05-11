#include <iostream>
#include <cstdlib>

using namespace std;


/* Polymorphism refers to the ability of acquiring many forms. In the context of OOP
this means that the same function name denoted many functions that are members of different objects. Consider the following example:
*/



class Class1
{
public:
    virtual void f()
    {
        cout << "Function f() in Class1\n";
    }
    void g()
    {
        cout << "Function g() in Class1\n";
    }
};

class Class2
{
public:
    virtual void f()
    {
        cout << "Function f() in Class2\n";
    }
    void g()
    {
        cout << "Function g() in Class2\n";
    }
};

class Class3
{
    public:
        virtual void f()
        {
            cout << "Function h() in Class3\n";
        }
};

int main(){
    Class1 object1, *p;
    Class2 object2;
    Class3 object3;
    p=&object1;
    p->f();
    p->g();
    p=(Class1*) &object2;
    p->f();
    p->g();
    p=(Class1*) &object3;
    //p->f() //Abnormal program termination
    p->g();
    //p->h() //h() is not a member of Class1;
    return 0;
}

