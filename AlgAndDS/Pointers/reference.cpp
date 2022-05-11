

int main(){
    //Pointers and Reference Variables
    int n = 5, *p = &n, &r = n;

    //&r is a reference variable that must be initialized.
    //reference variables can not be null.


    //!Reference variables are implemented as constant pointers.
    //So instead of 
    int &r = n;
    //we can
    int *const r = &n;
    
    return 0;
}