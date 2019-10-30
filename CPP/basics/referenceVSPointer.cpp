#include<iostream>
using namespace std;

int passByValue(int n);
int passByConstantValue(const int n);
void passByReferenceWithPointerArg(int * n);
void passByReferenceWithReferenceArg(int & n);

int main() {
    int number = 9;
    cout << "In main(), the address of number is: " << &number << endl;  
    cout << "After passByValue, we get : " << passByValue(number) << "\n";
    cout << "number now is: " << number << "\n";

    const int cnumber = 9;
    cout << "In main(), the address of cnumber is: " << &cnumber << endl;  
    cout << "After passByValue, we get : " << passByConstantValue(cnumber) << "\n";
    cout << "number now is: " << cnumber << "\n";



    number = 9;
    cout << "In main(), the address of number is: " << &number << endl;  
    passByReferenceWithPointerArg(&number);
    cout << "After passByReferenceWithPointerArg"  << "\n";
    cout << "number now is: " << number << "\n";

    number = 9;
    int & num = number;
    cout << "In main(), the address of number is: " << &number << endl;  
    passByReferenceWithReferenceArg(num);
    cout << "After passByReferenceWithReferenceArg" << "\n";
    cout << "number now is: " << number << "\n";

    return 0;
}

/**
     clone copy of the argument is made and passed into the function. 
     Changes to the clone copy inside the function has no effect to 
     the original argument in the caller.
 **/
int passByValue(int n){
    cout << "In passByValue, the address of number is: " << &n << endl;  
    n *= n;
    return n;
}

int passByConstantValue(const int n){
    cout << "In passByValue, the address of number is: " << &n << endl;  
    // n *= n;   assignment of read-only parameter 'n'
    return n * n;
}

//  modify the original copy directly (especially in passing huge object or array) to avoid the overhead of cloning.
void passByReferenceWithPointerArg(int * n) {
    cout << "In passByReferenceWithPointerArg, the address of number is: " << n << endl;
    *n *= *n; // Enumberplicit de-referencing to get the value pointed-to
}

// pass references into function, to avoid the clumsy syntax of referencing and dereferencing. 
void passByReferenceWithReferenceArg(int & n) {
    cout << "In passByReferenceWithReferenceArg, the address of number is: " << &n << endl;
    n *= n;
}