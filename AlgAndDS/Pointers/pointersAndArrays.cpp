#include <iostream>
#include <cstdlib>

int main()
{

    int a[5], *p;

    int sum = a[0];
    for (int i = 1; i < 5; i++)
    {
        sum += a[i];
    }
    // can be replaced by
    int sum2 = *a;
    for (int j = 1; j < 5; j++)
    {
        sum += *(a + j);
    }
    // or by
    int sum3 = *a;
    for(p = a+1;p<a+5;p++){
        sum3 += *p;
    }
    return 0;
    
}