// https://leetcode.com/problems/search-a-2d-matrix/
// 10/30/2019
/**
    Input:
    matrix = [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
    ]
    target = 3
    Output: true
 **/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};



int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};

    vector<vector<int>> &x = matrix;
    Solution test;
    cout << test.searchMatrix(x, 3) << endl;
    cout << test.searchMatrix(x, 0) << endl;
    return 0;
}