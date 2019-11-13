// source: https://leetcode.com/problems/triangle/

/**

    Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

    For example, given the following triangle
        [
            [2],
           [3,4],
          [6,5,7],
         [4,1,8,3]
        ]

    The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

 **/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        unsigned n = triangle.size();
        int i;
        unsigned j;
        vector<int> res = triangle[n-1];

        for(i = n-2; i >= 0; i--) {
            for( j = 0; j < triangle[i].size(); j++){
                res[j] = (res[j] < res[j+1]? res[j] : res[j+1]) + triangle[i][j]; 
            }
        }
        return res[0];
    }
};

void printArray(vector<int>& array){
    for(unsigned i =0 ; i < array.size(); i++) cout << array[i] <<  ' ';
    cout << endl;
}

void printMatrix(vector<vector<int>>& Matrix){
    for(unsigned i= 0; i < Matrix.size(); i++) printArray(Matrix[i]);
    cout << endl;
}


int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    printMatrix(triangle);
    Solution test;
    int res =  test.minimumTotal(triangle);
    cout << "The minimum sum from top to bottom is " << res << endl;
    return 0;
}