#include <iostream>
#include <cstdlib>

struct Node {
    char *name;
    int age;
    Node(char *n = "", int a = 0){
        name = new char[strlen(n)+1];
        strcpy(name, n);
        age = a;
    }

    //Copy constructor
    Node(const Node& n){
        name = new char[strlen(n.name)+1];
        strcpy(name, n.name);
        age = n.age;
    }
    
    Node& operator =(const Node& n){
        if(this != &n){ // not an assignment to self
        if(name!= 0){
            delete[] name;
            name = new char[strlen(n.name)+1];
            strcpy(name, n.name);
            age = n.age;
        }
        return *this;
        }
    }

    ~Node(){
        //destructor
        if(name != 0){
            delete name;
        }
    }
    //A special pointer "this" is used. Each object can access its own address through the pointer this so that *this is the object itself.
};

int main(){
    Node node1("Roger", 20), node2(node1); //or node2 = node1
    //each are independent entities  ==  changing value of one should not affect the other
    strcpy(node2.name, "Wendy");
    node2.age = 30;
    //resulting name are both Wendy, because definition of Node does not provide a proper copy constructor
    node1 = node2;
    //even after adding the copy constructor, not overloading the = operator causes issues 
    return 0;
}