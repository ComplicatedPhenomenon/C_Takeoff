/**
 * 
 **/

// Include library
#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> v = {7, 5, 16, 8};
    // Add 2 more integers to vector
    v.push_back(25);
    v.push_back(13);

    for(int n : v){
        cout << n << endl;
    }
    
}
