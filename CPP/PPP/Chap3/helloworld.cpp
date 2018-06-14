/*
 date : 2018.6.3
 version : 1.0
*/
// put a gallon into a pint pot
#include "std_lib_facilities.h"

int main()
{
    int a = 2000;
    char b = a;
    int c = b;
    char d = 's';
    int e = d;
    char f = e;

    if(a != c)
    cout << "Oops! " << a << "!=" << c <<"\n";
    else
    cout << "Wow! we have large characters.\n";

    if(d != f)
    cout << "Oops! " << d << "!=" << f <<"\n";
    else
    cout << "Wow!\n";

    return 0;
}
