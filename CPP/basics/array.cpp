/**
 * g++ -std=c++11 array.cpp
 **/
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

int main()
{
    // construction uses aggregate initialization
    std::array<int, 3> a1 {{1, 2, 3}} ; // double-braces required in C++11 (not in C++14)
    std::array<int, 3> a2 = {1, 2, 3};  // never required after =
    std::array<std::string, 2> a3 = { std::string("a"), "b" };

    // container operations are supported
    std::sort(a1.begin(), a1.end()); // a1={1,2,3}
    std::reverse_copy(a2.begin(), a2.end(),
                      std::ostream_iterator<int>(std::cout, " "));

    std::cout << '\n';

    // ranged for loop is supported
    for(const auto& s: a3)
        std::cout << s << ' ' ;
    std::cout << std::endl;

/**
    std::array<std::string, 4> arr = {{"the", "quick", "brown", "fox"}};
    if(assert(arr[2] == "brown")){
        cout<< "arr[2] == brown is true" << endl;

    }

**/
}

/**
 * std::array::begin  Returns an iterator pointing to the first element in the array container.
 * std::sort Sorts the elements in the range [first, last) in ascending order. The order of equal elements is not guaranteed to be preserved.
 **/
