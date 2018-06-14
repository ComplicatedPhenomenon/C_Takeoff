/*
 date : 2018.6.3
 version : 1.0
*/
// put a gallon into a pint pot
#include "../std_lib_facilities.h"

int main()
{
    int a{2000};
    char b{a};
    int c{b};

    if(a != c)
    cout << "Oops! " << a << "!=" << c <<"\n";
    else
    cout << "Wow! we have large characters.\n";


    return 0;
}
