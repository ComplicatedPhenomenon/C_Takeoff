/**
 * https://www.techiedelight.com/iterate-over-characters-string-cpp/
 **/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string S = "czfzdxx";
    //using  std::for_each, which apply a function to each element of an input range
    for_each(S.begin(), S.end(), [] (const char &c) {cout<< c << ' ';});
    cout << endl;
    for(const char & c: S) cout<< c << ' ';
    cout << endl;
    // using an iterator
    for(auto it = S.cbegin(); it != S.cend(); ++it) cout << *it << ' ';  
    cout << endl;  

    return 0;
}