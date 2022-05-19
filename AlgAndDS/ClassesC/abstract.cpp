//A pure virtual function is a function with a declaration and no definition.


//Any class with a pure virtual function is an Abstract class.
//Abstract class cannot create any Instances of itself.

//An abstract class only has the Prototype of its member functions, and it is
//up to the child class to redefine them.

//A Class with ONLY pure virtual functions is called an interface.


#include <iostream>
using namespace std;

class Parent {
public :
    virtual void func() = 0; //순수 가상함수
};

class Child : public Parent {
public:
    void func() { //무조건 재정의를 해야만 함
        cout << "func" << endl;
    }
};

int main(void)
{
    Child c;
    c.func();
    
    return 0;
}