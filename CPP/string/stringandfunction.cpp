#include <stdexcept>
#include <iostream>
#include <string>

int main()
{
    std::string s("message"); // for capacity

    s = "abc";
    s.at(2) = 'x'; // ok
    std::cout << s << '\n';

    std::cout << "string size = " << s.size() << '\n';
    std::cout << "string capacity = " << s.capacity() << '\n';
    /**
     * s.capacity() returns the number of characters that the string has
     * currently allocated space for.
     */

    try {
        // throw, even if capacity allowed to access element
        s.at(3) = 'x';
    }
    catch (std::out_of_range const& exc) {
        std::cout << exc.what() << '\n';
    }
}
