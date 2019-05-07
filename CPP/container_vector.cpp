/**
 * Tips: Use g++ -std=c++11 <filename> when compiling.
 **/

// Include library
#include<iostream>
#include<vector>

using namespace std;

int main(){
    // Create a vector containing integers
    vector<int> v = {7,5,16, 8};
    // Add 2 more integers to vector
    v.push_back(25);
    v.push_back(13);

    // Integrate and print values of vector
    for(int n : v){
        //cout << n << '\n';
        cout << n << endl;
    }
    // Is v empty? the answer is false.
    if(v.empty() == 0 ){
      cout << "vector is not empty" << endl;
    }
}
