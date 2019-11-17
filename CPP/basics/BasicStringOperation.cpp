#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string result;
    cout << "result is empty: " << result.empty() << endl;
    string str1 = "Hello";
    string str2 = "world";
    string str3 = "It's a new day!";
    result = str1;
    result += ' '; // + operator is redefined for string to mean "string concatenation"
    result += str2;
    result += "! ";
    result += str3;
    cout << "result is: " << result << endl;
    cout << "result[1] is: " << result[1] << endl;

    string s("message"); 
    s = "abc";
    s.at(2) = 'x'; 
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

    char text[] = "Christmas Tree"; //The C-style character string
    cout << "sizeof(text) = " << sizeof(text) << endl;
    cout << "sizeof(text[0]) = " << sizeof(text[0]) <<endl;
    // Single quotation marks around one character are used for char literals,
    string xs = string(1, 'a') + "bc"; 
    cout << xs << endl;   
    return 0;
}
