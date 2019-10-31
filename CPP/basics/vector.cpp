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

    int twoDArray[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int len = sizeof(twoDArray) / sizeof(twoDArray[0]);
    int oneDArray[len];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j){
            oneDArray[i*4+j] = twoDArray[i][j];
        }
    }
    for(int i = 0; i < 12; ++i){
        cout << oneDArray[i] << " ";
    }
    cout << endl;

    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    cout << "matrix has " << matrix.size() * matrix[0].size() << " elements" << endl; 

    return 0;
}
