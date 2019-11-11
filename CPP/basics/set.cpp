#include<iostream>
#include<set>

using namespace std;
int main () {
    int myints[] = {75,23,65,42,13};
    set<int> myset (myints,myints+5);

    if (myset.find(75)!= myset.end()) cout << "Find" << endl;
    if (myset.find(9) == myset.end()) cout << "Not Find" << endl;
    cout << "myset contains:";
    for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        cout << ' ' << *it;

    cout << '\n';

    return 0;
} 

/**
    The function returns an iterator which points to the element 
    which is searched in the set container. If the element is not found, 
    then the iterator points to the position just after the last element in the set.
 **/