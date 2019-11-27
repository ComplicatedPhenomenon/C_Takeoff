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
    array<int, 6> array1 {4, 7, 9, 0, 2, 3}; 
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

    array<string, 2> array2 = { "a", "b" };
    for(const auto& s: array2)
        cout << s << ' ' ;
    cout << endl;


    int twoDArray[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int len = sizeof(twoDArray) / sizeof(twoDArray[0]);
    int oneDArray[len];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j){
            oneDArray[i*4+j] = twoDArray[i][j];
        }
    }
    for(int i = 0; i < 12; ++i){
        cout << oneDArray[i] << " ";
    }
    cout << endl;
    return 0;
}

/**
 * array::begin  Returns an iterator pointing to the first element in the array container.
 **/
