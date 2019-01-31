/**
 *  c++ variable_function_declaration.cxx
 * I need to increase abstraction level of algorithm of this concrete sample.
 **/


#include<iostream>
using namespace std;
int add(int &number);

int main ()
{
    int number;
    int result;
    int i = 0, j = 9;
    number=5;
    cout << "The value of the variable number before calling the function : " << number << endl;
    result=add(number);
    cout << "The value of the variable number after the function is returned : " << number << endl;
    cout << "The value of result : " << result << endl;
    cout << "Before swap, i = " << i << ", j = " << j << endl;
    swap(i, j);
    cout << "After swap, i = " << i << ", j = " << j << endl;
    return(0);
}

int add(int &p){
    cout << "In scope of function add, p= " << p <<endl;
    p=p+100;
    return p;
}

void swap(int &i, int &j){
    cout << "In scope of function swap, i= "<< i << ", j= " << j <<endl;
    int tem;
    tem = i;
    i = j;
    j = tem;
}
