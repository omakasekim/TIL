//function templates

int add(int x, int y){
    return x+y;
}

double add(double x, double y){
    return x+y;
}
//function overloading = changing return type or parameter type to deal with multiple types of data
//! Problem is we need to create one for EVERY type 


//? How do we deal with this?

template<typename T>
T add(T x, T y){
    return x+y;
}



//Class Templates

template<typename T>
class Calc{
    private:
        T num1;
        T num2;

    public:
        Calc(T num1, T num2) {
            this->num1 = num1;
            this->num2 = num2;
        }
        T getAdd(){
            return num1 + num2;
        }
};

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    Calc<int> calcu1(10, 20);
    cout << calcu1.getAdd() << endl;
    
    Calc<double> calcu2(10.52, 20.24);
    cout << calcu2.getAdd() << endl;
}

//template specialisation 
//used to deal with pre-defined types 

template<>
char* add(char* s1, char* s2) {
    char* str = new char[100];
    strcpy(str, s1);
    strcat(str, s2);
    return str;
}
