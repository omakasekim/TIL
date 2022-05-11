#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
/*
In C++, the function call oerator () can be treated as any other operator;
in particular, it can later be overloaded.

It can return any type and take any number of arguments, but like the assignment operator, it can be overloaded only as a member function.

Any object that includes a definition of the function call oerator is called a function object.
*/

/*
Consider the example of finding the sum of numbers
resulting from applying a function f to integers in the interval [n, m].

An implementation sum() presented in ((pointers.cpp)) relied on using a function pointer as an argument of function sum().

The same can be accomplished by first defining a class that overloads the function call operator:
*/
class classf
{
public:
    classf()
    {
    }
    double operator()(double x)
    {
        return 2 * x;
    }
};
// and defining
double sum2(classf f, int n, int m)
{
    double result = 0;
    for (int i = n; i <= m; i++)
    {
        result += f(i);
    }
    return result;
}
/*
which differs from sum() only in the first parameter, which is a function object, not a function;
otherwise, it is the same. The new function can now be called, as in

*/

int main()
{
    classf cf;
    cout << sum2(cf, 2, 5) << endl;
    // or simply,
    cout << sum2(classf(), 2, 5) << endl;

    return 0;
    /*
    The latter way of calling requires a definition of constructor classf() (even if it has no body)
    to create an object of type classf() when sume2() is called.
    */
}

/*
The same can be accomplished without overloading the function call operator, as exemplified in these two definitions:
*/

class classf2
{
public:
    classf2()
    {
    }
    double run(double x)
    {
        return 2 * x;
    }
};

double sum3(classf2 f, int n, int m)
{
    double result = 0;
    for (int i = n; i <= m; i++)
    {
        result = f.run(i);
    }
    return result;
}
// and a call
int main()
{
    cout << sum3(classf2(), 2, 5) << endl;
}

/*

The STL relies very heavily on function objects.
The mechanism of function pointers is insufficient for built in operators.

How could we pass a unary minus to sum()?

The syntac sum(-,2,5) is illegal. To circumvent the problem, the STL defines in <function> function objects for the common c++ operators.
For example. unary minus is defined as
*/

template <class T>
struct negate : public unary_function<T, T>
{
    T operator()(const T &x) const
    {
        return -x;
    }
};

// Now after redefining function sum() so that it becomes a generic function:

template <class F>
double sum(F f, int n, int m)
{
    double result = 0;
    for (int i = n; i <= m; i++)
    {
        result += f(i);
    }
    return result;
}

// the function can also be called with the negate function object,
sum(negate<double>(), 2, 5);
