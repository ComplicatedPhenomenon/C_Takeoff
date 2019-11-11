#include<iostream>
using namespace std;

void passByValue(int n);
void passByConstantValue(const int n);
void passByReferenceWithPointerArg(int * n);
void passByReferenceWithReferenceArg(int & n);

int main() {
    int number = 9;

    cout << "In main(), the address of number is: " << &number << endl;  
    passByValue(number); // 修改调用函数中的数据对象
    cout << "After passByValue, number now is: " << number << endl;

    number = 9;
    passByReferenceWithPointerArg(&number);
    cout << "After passByReferenceWithPointerArg, number now is: "  << number << endl;

    number = 9;
    passByReferenceWithReferenceArg(number);
    cout << "After passByReferenceWithReferenceArg, number now is: " << number << endl;

    return 0;
}

/**
     clone copy of the argument is made and passed into the function. 
     Changes to the clone copy inside the function has no effect to 
     the original argument in the caller.
 **/
void passByValue(int n){
    cout << "In passByValue, the address of number is: " << &n << endl;  
    n *= n;
}

//  modify the original copy directly (especially in passing huge object or array) to avoid the overhead of cloning.
void passByReferenceWithPointerArg(int * n) {
    cout << "In passByReferenceWithPointerArg, the address of number is: " << n << endl;
    *n *= *n; // Enumberplicit de-referencing to get the value pointed-to
}

// pass references into function, here to avoid the clumsy syntax of referencing and dereferencing. 
//在这里使用引用类型，相当于是实参变量的一个别名. 
void passByReferenceWithReferenceArg(int & n) { 
    cout << "In passByReferenceWithReferenceArg, the address of number is: " << &n << endl;
    n *= n;  // convenient than `*n *= *n;`
}

/*
In main(), the address of number is: 0x7ffc891ee59c
In passByValue, the address of number is: 0x7ffc891ee57c
After passByValue, number now is: 9
In passByReferenceWithPointerArg, the address of number is: 0x7ffc891ee59c
After passByReferenceWithPointerArg, number now is: 81
In passByReferenceWithReferenceArg, the address of number is: 0x7ffc891ee59c
After passByReferenceWithReferenceArg, number now is: 81
*/