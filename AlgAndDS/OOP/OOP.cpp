/*
C++ has an excellent encapsulation facility which
allows for well-controlled information hiding.
There is, howevera, a relaxation to this use in the use
of so-called friend functions.

The problem is that private information of a certain class cannot be accessed anymore,
and the public information is accessible to every user. But
some times we would like to allow only
some users to have access to the private pool if infirmation.
This can be accomplished if the class lists the user functions
as its friends.

For example, if the definition is
*/
class C{
    int n;
    friend int f();
} ob;

//function f() has direct access to variable n belonging to the class C, as in

int f(){
    return 10 * ob.n;
}

/*
This could be considered a violation of the information hiding principle;
however the class C itself grants the right to make public to some users what is private and inaccessible to others.
THis , since the class has control over what to consider a fried=nd function, the 
friend function mechanism can be considered an extension of the imformation hiding principle. 

*/