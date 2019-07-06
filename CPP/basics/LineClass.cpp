#include <string>
#include <iostream>
using namespace std;

class Line {
    public:
        double length;
        string name;
        void setLength( double len );
        double getLength( void );
        string setName(string eman);
        string getName();
};

void Line::setLength( double len) {
    cout << "Entering function: " << __func__ << endl;
    //every function has a local predefined variable __func__ containing the name of the function.
    length = len;
}

double Line::getLength(void) {
    return length ;
}

string Line::setName(string eman) {
    name = eman;
    return name;
}

string Line::getName(){
    return name;
}


/**
 * When you type using namespace std, you are taking everything inside of the namespace std
 * and moving it to the global scope, so that you can
 * use the shorter cout instead of the more fully-qualified std::cout.
 */
int main()
{
    Line line;

    line.setLength(6.0);

    cout << "Length of line : " << line.getLength() << endl;
    cout << "Name of the line: " << line.setName("Straight Line") << endl;
    cout << "Name of the line: " << line.getName() << endl;

    // set line length without member function
    line.length = 10.0; // OK: because length is public
    line.name = "Curve line";
    cout << "Length of line : " << line.length << endl;
    cout << "Name of line : " << line.name << endl;

    Line *ptr_line;
    ptr_line = & line;
    cout << ptr_line->name << "!" << endl;

    return 0;
}
