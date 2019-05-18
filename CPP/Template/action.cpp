#include<iostream>
#include<string>
#include <cstdlib>
#include"stack.h"

int main() {
    try {
        Stack<int>         intStack;  // stack of ints
        Stack<std::string>   stringStack;    // stack of strings

        intStack.push(7);
        std::cout << intStack.top() << std::endl;

        stringStack.push("hello");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    } catch (std::exception const& ex) {
        std::cerr << "Exception: " << ex.what() <<std::endl;
        return -1;
    }
}
