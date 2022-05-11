/*

The simplest STL container is the vector, which is the data structure with
contiguous blocks of memory just like an array. Because memory locations are contiguous, they can be randomly
accessed so that the access time of any element of the vector is constant.

Storage is managed autoamtically so that on attempt to insert an element into a full vector,
a larger memory block ia llocated for the vector, the vector elements are copied to the new block,
and the old block is releaed.

A vector is thus a flexible array, that is an array whose size can be dynamically changed.

Figure 1.3 lists alphabetically all the vector member functions. An applicatoon of these functions is illustrated in Figure 1.4/

*/

/*Figure 1.3
void assign(first, last)
//remove all the nodes in the vector and insert in it the elements from the range indicated by iterators first and last

void assign(n, el = T())
//remove all the nodes in the vector and insert in it n copies of el

T& at(n)
//returns the element in position n of the vector

const T& at(n) const
//returns the element in position n of the vector

T& back()
//returns the last element of the vector

const T& back() const
//returns the last element of the vector

iterator begin()
//return an iterator that references the first element of the vector

const_iterator begin() const
//returns a const iterator that references the first element of the vector

size_type capacity() const
//returns the number of elements that can be stored in the vector

void clear()
//remove all the elements in the vector

bool empty() const
//returns true if the vector includes no element and false otherwie

iterator end()
//returns an iterator that is past the last element of the vector


const_iterator end() const
//returns a const ierator that is past the last element of the vector


iterator/void erase(i)
//remove the element referenced by iterator i

iterator/void erase(first, last)
//remove the elements in the range indicated by iterators first and last


T& front()
//returns the first element of the vector

const T& front() const
//returns the first element of the vector

iterator insert(i, el = t())
// insert el before the element referenced by iterator i and return iterator referencing the newly inserted element

void insert(i, n, el)
//insert n copies of el before the element referenced by iterator i

void insert(i, first, last)
//insert elements from the range indicated by iterators first and last before the node referenced by iterator i

size_type max_size() const
//return the maximum number of elements for the vector

T& operator[]
//subscript operator

const T& operator[] const
//subscript operator

void pop_back()
//remove the last element of the vector

void push_back(el)
//inserts el at the end of the vector

reverse_iterator rbegin()
//returns an iterator that references the last element of the vector

const_reverse_iterator rbegin() const
//returns a const iterator that references the last element of the vector

reverse_iterator rend()
//returns an iterator that is before the first element of the vector

const_reverse_iterator rend() const
//returns a const iterator that is before the first element of the vector

void reservee(n)
//reserve enough room for vector to hold n items if its capacity is less than n

void resize(n, el = T())
//make the vector able to hold elements by adding n - size() more positions with element el or by discarding overflowing size() - n positions from the end of the vector


size_type size() const
//returns the number of elements in the vector

void swap(v)
//swap the content of the vector with the content of another vector v


vector()
//construct an empty vector

vector(n, el = T())
//constructs a vector with n copies of el of type T(if el is not provided, a default constructor T() is used)

vector(first, last)
//construct a vector with the elements from the range indicated by iterators first and last


vector(v)
//copy constructor

*/

// Figure 1.4
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional> //greater<T>

using namespace std;

template <class T>
void printVector(char *s, const vector<T> &v)
{
    cout << s << " = (";
    if (v.size() == 0)
    {
        cout << ")\n";
        return;
    }
    vector<T>::const_iterator i = v.begin();
    for (; i < v.begin() + v.size() - 1; i++)
        cout << *i << ' ';
    cout << *i << ")\n";
}

bool f1(int n)
{
    return n < 4;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v1; // v1 is empty, size = 0, capacity = 0
    printVector("v1", v1);

    for (int j = 1; j <= 5; j++)
        v1.push_back(j);  // v1 = (1,2,3,4,5), size = 5, capacity = 8
    vector<int> v2(3, 7); // v2 = (7,7,7)

    vector<int>::iterator i1 = v1.begin() + 1;
    vector<int> v4(v1);         // v4 = (1,2,3,4,5), size = 5, capacity = 5
    vector<int> v5(5);          // v5 = (0,0,0,0,0)

    v5[1] = v5.at(3) = 9; // v5 = (0,9,0,9,0)
    v4.reserve(6);        // v4 = (2,3), size = 2, capacity = 6
    v4.resize(7);         // v4 = (1,2,3,4,5,0,0), size = 7, capacity = 10
    v4.resize(3);         // v3 = (1,2,3), size = 3 , capacity = 10
    v4.clear();           // v4 is empty, size = 10, capacity = //!10

    v4.insert(v4.end(), v4[1]);                        // v4 = (3)
    v4.insert(v4.end(), v4.at(1));                     // v4 = (3, 3)
    v4.insert(v4.end(), 2, 4);                         // v4 = (3, 3, 4 , 4)

    v4.erase(v4.end() - 2);             // v4 = (3,3,4,4,2,4);
    v4.erase(v4.begin(), v4.end() + 4); // v4 = (2,4)
    v4.assign(3, 8);                    // v4 = (8,8,8)

    vector<int>::reverse_iterator i3 = v4.rbegin();
    for (; i3 != v4.rend(); i3++)
        cout << *i3 << ' '; // print: 3 2 1
    cout << endl;

    // algorithms

    v5[0] = 3;                               // v5 = (3,9,0,9,0)
    replace_if(v5.begin(), v5.end(), f1, 7); // v5 = (7,9,7,9,7)
    v5[0] = 3;
    v5[2] = v5[4] = 0;                               // v5 = (3,9,0,9,0)
    replace(v5.begin(), v5.end(), 0, 7);             // v5 = (3,9,7,9,7)
    std::sort(v5.begin(), v5.end());                 // v5 = (3,7,7,9,9)
    std::sort(v5.begin(), v5.end(), greater<int>()); // v5 = (9,9,7,7,3)
    v5.front() = 2;                                  // v5 = (2,9,7,7,3)

    /*
The sorting algorithms allow for the same flexibility. In the eaxmple of sorting vector v4,
v5 is sorted in ascending order. How can we sort it in descending order?

One way is to sort it in ascending order and then reserve with the algorithm reverse().
Another way is to force sort() to apply the operator > in making its decisions.
This is done directly by using a function object as a parameter, as in
*/
    std::sort(v5.begin(), v5.end(), greater<int>());
    // or indirectly, as in
    std::sort(v5.begin(), v5.end(), f2);
    return 0;
}

// where f2 is defined as
bool f2(int m, int n)
{
    return m > n;
}
/*
The first method is preferable, but this is possible only because the function object
greater is already defined in the STL. This function object is defined as a template structure which in essence
generally overloades the operator >.

Therefore, greater<int>() means that the operator should be applied to integers.

This version of the algorithm sort(), which takes a functional argument, is particularly useful
when we need to sort objects more complex than integers and we need to use different criteria.

Consider the following class definition:
*/

class Person
{

public:
    Person(char *n = "", int a = 0)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
    }

    bool operator==(const Person &p) const
    {
        return strcmp(name, p.name) == 0 && age == p.age;
    }

    bool operator<(const Person &p) const
    {
        return strcmp(name, p.name) < 0;
    }

    bool operator>(const Person &p) const
    {
        return !(*this == p) && !(*this < p);
    }

private:
    char *name;
    int age;
    friend bool lesserAge(const Person &, const Person &);
};

// Now with the declaration
vector<Person> v6(1, Person("Gregg", 25));
// adding to v6 two more objects
int main(){
v6.push_back(Person("Ann", 30));
v6.push_back(Person("Bill", 20));

// and executing
std::sort(v6.begin(), v6.end());

// v6 is sorted in ascending order because the version of sort() with only two iterator arguments use the operator < overloaded in class Person.
// The call

std::sort(v6.begin(), v6.end(), greater<Person>());
}
// changes v6 into descended order because this version of sort relies on the operator > overloaded for this class.

// What Do we need to do to sort the objects by age?
// In this case, a function need to be defined as in

bool lesserAge(const Person &p1, const Person &p2)
{
    return p1.age < p2.age;
}

// and then used as an argument in the call to sort().
int main(){
std::sort(v6.begin(), v6.end(), lesserAge);
}