## Which compiler?
` g++ -Wall detectCapital.cpp `

## namespace
* `using namespace std` is considered bad practice

  Because you can have 2 function have same name belongs 2 namespace.
## ` std::string`
parameters of class `string`
* member function (method)
  * operator =
  * assign
  * get_allocator
  * Element access
    * ...
  * Iterators
    * ...
  * capacity
    * ...
  * Operations
    * clear clears the contents (public member function)
    * insert inserts characters (public member function)
    * erase
    * push_back

    * pop_back
    * append
    * operator+=
  * Search
    * ...

After comparing the way of OOP in with C, which has a more explicit style, don't you see that our efficiency for production goes high under one programming paradigm? It wraps up the universal operations and expand the library, so you don't need to do it again.

## `std::basic_string`

  The templated class `std::basic_string` generalizes how sequences of characters are manipulated and stored. String creation, manipulation, and destruction are all handled by a convenient set of class methods and related functions.

  Several specializations of std::basic_string are provided for commonly-used types:
  * `std::string`
  * `std::wstring`
  * `std::U16stsring`
  * ...
