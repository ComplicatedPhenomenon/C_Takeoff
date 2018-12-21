
## class string or built-in type
`std::string`  

parameters
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

After comparing the way of OOP in with C, which has a more explicit style.
Don't you see that our efficiency goes high under one programming paradigm?
It wraps up the universal operations and expand the library, so you don't need to do it again.

String library

Header file in CPP

* `std::basic_string`

  The templated class `std::basic_string` generalizes how sequences of characters are manipulated and stored. String creation, manipulation, and destruction are all handled by a convenient set of class methods and related functions.

  Several specializations of std::basic_string are provided for commonly-used types:
  * `std::string`
  * `std::wstring`
  * `std::U16stsring`
  * ...
