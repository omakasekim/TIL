//? There are certain functions that the compiler creates for us.
//Constructor, Destructor, copy constructor, = operator.


//? A Copy Constructor is called when creating a copy of an instance
//? A = operator is used when copying an instance using =

#include <iostream>
#include <cstring>
using namespace std;

class A {
public:
    A(){
        cout << "생성자" << endl;
    }
    
    A(const A& rhs) {
        cout << "복사 생성자" << endl;
    }
    
    A& operator=(const A& rhs){
        if (this != &rhs){ //다를때만 복사 수행
             cout << "복사 대입연산자" << endl;
        }
        return *this;
    }
};

void func_Value(A a){}; // Copy Constructor called
void func_Reference(A &a){}; // Copy Constructor is not called
void func_Pointer(A* a){}; // Copy Constructor is not called

int main()
{
    //Instance
    cout << "Instance" << endl;
    A a1; // Constructor is called
    A a2; //Constructor is called
    A a3 = a1; // Copy Constructor is called
    a1 = a2; //= operator is called
    
    //Functions
    cout << endl<< "Functions" << endl;
    func_Value(a1); //Copy Contructor is called
    func_Reference(a1); //Copy Constructor is not called
    func_Pointer(&a1); //Copy Constructor is not called
    
    return 0;
}//Destructor is called when Instance is complete


//Any kind of copy operation that is not overloaded is a shallow copy.
//AKA both instances point at the same memory locations.


class Person{
public:
    int age;
    char* name;

    Person(int _age, const char* _name){
        age = _age;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
    
    Person(const Person& p){ //복사 생성자로 깊은 복사하기
        age = p.age;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }
    
    void infoPerson(){
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
};

int main(){
    Person A(20, "홍길동");
    Person B = A;
    
    B.age = 30;
    strcpy(B.name, "이순신");
    
    A.infoPerson();
    B.infoPerson();
}