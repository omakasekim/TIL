//? Operator Overloading is used to redefine operators to the users liking

#include <iostream>
using namespace std;
class myOperation {

public:
    void operator+ (int num) {
        cout << "+를 한다." << endl;
    }
    void operator- (int num) {
        cout << "-를 한다." << endl;
    }
    void operator* (myOperation oper) {
        cout << "*를 한다." << endl;
    }
    void operator/ (myOperation oper) {
        cout << "/를 한다." << endl;
    }
};

int main() {

    myOperation a, b;

    a + 1;
    a - 2;
    a * b;
    a / b;
}