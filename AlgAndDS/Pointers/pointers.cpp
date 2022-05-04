#include <iostream>
#include <cstring>

int main(){

    int i = 15, j, *p, *q;

    p = &i;
    q = &j;

    *p = 20;


    delete p;
    delete q; // delete is potentially dangerous


    p = 0;
    q = nullptr;
    p = NULL;

    return 0;
}