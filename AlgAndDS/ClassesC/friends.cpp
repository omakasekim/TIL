//? Friend keyword is used when classes need to share Member variables.
// friend keyword is used before a function or a class. Classes or Functions with friend keyword is not affected by access modifiers

#include <iostream>
using namespace std;

class People{
private:
    string name;
public:
    People(string name) {this->name = name;} //Constructor
    
    friend void sayName(People p); //friend Method
};

void sayName(People p) {
    //can access private members
    cout << p.name << endl;
}

int main() {
    People p("김스시");
    sayName(p);
}



class PeopleA{
private:
    string name;
    int height;
    friend class PeopleB; //friend class
public:
    //constructor
    PeopleA(string name, int height) {
        this->name = name;
        this->height = height;
    }
};

class PeopleB {
public:
    void info_A(PeopleA a) { 
        cout << "이름 : " << a.name << endl;
        cout << "신장 : " << a.height << endl;
    }
};