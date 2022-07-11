#include <stdio.h>
#include <math.h>

float Q_rsqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y; // evil floating point bit level hacking
    i = 0x5F375A86 - (i >> 1); // what the fuck?
    y = *(float*)&i;
    y = y*(threehalfs - (x2*y*y));// 1st iteration
    y = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed

    return y;
}

int main(){
    double ANS = Q_rsqrt(1246212343423423342);
    //double ANS = 1/(sqrt(1246212343423423342));
    printf("%.99lf",ANS);

    return 0;
}