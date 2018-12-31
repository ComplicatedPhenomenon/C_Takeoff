// Showcase class template, besides demo of std::vector member functions  
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
   private:
      vector<T> elems;

   public:
      void push(T const&);
      void pop();
      T top() const;            // return top element

      bool empty() const {      // return true if empty.
         return elems.empty();
      }
};

// Working in the framework of Modern C++ is much easier than in C.
template <typename T>
void Stack<T>::push (T const& elem) {
   // append copy of passed element
   elems.push_back(elem);
}


template <typename T>
void Stack<T>::pop () {
   if (elems.empty()) {
      throw out_of_range("Stack<>::pop(): empty stack");
   }

   // remove last element
   elems.pop_back();
}

template <typename T>
T Stack<T>::top () const {
   if (elems.empty()) {
      throw out_of_range("Stack<>::top(): empty stack");
   }

   // return copy of last element
   return elems.back();
}

int main() {
   try {
      Stack<int>         intStack;  // stack of ints
      Stack<string> stringStack;    // stack of strings

      // manipulate int stack
      intStack.push(7);
      cout << intStack.top() <<endl;

      // manipulate string stack
      stringStack.push("hello");
      cout << stringStack.top() << std::endl;
      stringStack.pop();
      stringStack.pop();
   } catch (exception const& ex) {
      cerr << "Exception: " << ex.what() <<endl;
      return -1;
   }
}
