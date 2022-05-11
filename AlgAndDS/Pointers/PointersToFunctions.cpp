//Consider a simple function
// f is the pointer to f(), *f is the function itself, and (*f)(7) is a func. call.

double f(double x){
    return 2*x;
}

//Consider writing a function that computes a sum from n to m, of f of i.

double sum (double (*f)(double), int n, int m){
    double result = 0;
    for(int i = n; i <= m; i++){
        result += f(i);
    }   
    return result;
}
/*
In the definition of sum(), the declaration of the first formal atgument
double (*f)(double)
means that f is a pointer to a function with one double argument
and a double return value.

Note the need for parentheses around *f due to operator precedence
*/

/*
Another example is a function that finds a root of a continuous functions in an
interval. The root is found by repetitively bisecting an interval and finding a midpoint of the current interval.

*/
double root(double (*f)(double), double a, double b, double epsilon){
    double middle = (a + b) / 2;
    while(f(middle) != 0 && fabs(b-a) > epsilon) {
        if (f(a) * f(middle) < 0) // if f(a) and f(middle) have
            b = middle; //opposite signs
        else a = middle;
        middle = (a + b) / 2;
    }
    return middle;
}