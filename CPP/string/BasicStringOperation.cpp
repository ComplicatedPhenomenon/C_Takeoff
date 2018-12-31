#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //this part is about string  manipulation
    string result;
    string s1 = "Hello";
     // without the extra space at the end
    string s2 = "world";
    string s3 = "It's a new day!";
    result = s1;
    result += ' '; // + operator is redefined for string to mean "string concatenation"
     // append a space at the end
    result += s2;
    result += "! ";
    result += s3;
    cout <<  result << endl;

    string s("message"); // for capacity
    s = "abc";
    s.at(2) = 'x'; // ok
    cout << s << '\n';

    cout << "string size = " << s.size() << '\n';
    cout << "string capacity = " << s.capacity() << '\n';

    // s.capacity() returns the number of characters that the string has currently allocated space for.


    try {
        // throw, even if capacity allowed to access element
        s.at(3) = 'x';
    }
    catch (out_of_range const& exc) {
        cout << exc.what() << '\n';
    }

    char text[] = "Christmas Tree";
    // Apply shorthand   condition ? if_true : if_false again
    sizeof(text) == strlen(text) ? cout << "sizeof(text) == strlen(text)" << endl : cout << "sizeof(text) != strlen(text)" <<endl;
    cout << "As sizeof return the actual memery used by the string, including the terminated  character." << endl;
    return 0;
}
