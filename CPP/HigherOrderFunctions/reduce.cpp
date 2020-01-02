/**
 *   g++ -std=c++11 reduce.cpp #use -std=c++11 or later
 *  python       cpp
 *   map   ->  std::transform
 *  filter ->  std::remove_if
 *  reduce ->  std::accumulate 
 **/

#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

bool fitCriteria(int a){
    return a > 3;
}

int main() {
    vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string> str {"Programming",  "in",  "a",  "functional",  "style."};

    transform(vec.begin(), vec.end(), vec.begin(), [](int i){ return i*i;});
    for(const int &n : vec){
        cout << n << " ";
    }
    cout << endl;

    vector<int> vec2;
    transform(str.begin(), str.end(), back_inserter(vec2), [](std::string s){ return s.length ();});
    for(const int &n : vec2){
        cout << n << " ";
    }
    cout << endl;

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int res = accumulate(vec.begin(), vec.end(), 1, [](int a, int b){ return a*b;});
    cout << res << endl;

    return 0;
}