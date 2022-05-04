#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>

class intClass{
    int storage[50];
};

class floatClass{
    float storage[50];
};

template<class genType, int size = 50> class genClass {
    genType storage[50];
    void swap(genType& el1, genType& el2){
        genType temp = el1; el1 = el2; el2 = temp;
    }
};


int main(){

    genClass<int> intObject; //uses the default size
    genClass<int, 100> intObject2; 
    genClass<float, 123> floatObject;
    return 0;
}