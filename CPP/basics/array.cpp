/**
 * g++ -std=c++11 array.cpp
 **/
 #include <iostream>
#include <string>
#include <array>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {

    array<int, 6> array1 {4, 7, 9, 0, 2, 3} ; 
    array<string, 2> array2 = { "a", "b" };

    sort(array1.begin(), array1.end()); 

    // access by const reference
    for (const auto &a : array1) {  
        cout << a << " ";
    }  
    cout << '\n';

    // access by value, the type of a is int
    for (auto a : array1) {  
        cout << a << " ";
    }  
    cout << '\n';

    for (int i : array1) {
        cout << array1[i] << " ";
    }
    cout << '\n';

    for(const auto& s: array2)
        cout << s << ' ' ;
    cout << endl;


    
    return 0;
}

/**
 * array::begin  Returns an iterator pointing to the first element in the array container.
 **/
