#include<iostream>
#include<set>

using namespace std;
int main () {
    int myInts[] = {75, 23, 65, 42, 13};
    set<int> mySet (myInts,myInts+5);

    if (mySet.find(75)!= mySet.end()) cout << "Find" << endl;
    if (mySet.find(9) == mySet.end()) cout << "Not Find" << endl;

    cout << "mySet contains:";
    for (set<int>::iterator it=mySet.begin(); it!=mySet.end(); ++it)
        cout << ' ' << *it;

    cout << '\n';

    return 0;
} 

/**
    The function returns an iterator which points to the element 
    which is searched in the set container. If the element is not found, 
    then the iterator points to the position just after the last element in the set.
 **/