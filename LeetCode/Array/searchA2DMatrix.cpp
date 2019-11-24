/**
 *  source : https://leetcode.com/problems/search-a-2d-matrix-ii/
 * 
 *  description:
 * 
 *    1. Integers in each row are sorted from left to right.
 *    2. Integers in each column are sorted in ascending from top to bottom.
 * 
 *  Input:
 *      matrix = [
 *      [1,   4,  7, 11, 15],
 *      [2,   5,  8, 12, 19],
 *      [3,   6,  9, 16, 22],
 *      [10, 13, 14, 17, 24],
 *      [18, 21, 23, 26, 30]
 *      ]
 *  Given target = 5, return true.
 *  Given target = 20, return false.
 * 
 *  start from the left bottom, if greater, move right, if less, move above 
 *  You can prove since the start point is special, the trajectory is unique
 **/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRow = matrix.size();
        if (nRow == 0)
            return false;
        int nCol = matrix[0].size();
        int i = nRow - 1;
        int j = 0;
        while(i >= 0 && j < nCol){
            if (matrix[i][j] == target)
                return true;

            matrix[i][j] > target ? i-- : j++;   
        }
        return false;
    }
};

int main() {
    vector<vector<int>> nums = {{1, 4, 7, 11, 15}, 
                                {2, 5, 8, 12, 19}, 
                                {3,  6, 9, 16, 22}, 
                                {10, 13, 14, 17, 24}, 
                                {18, 21, 23, 26, 30}};
    vector<vector<int>> &matrix = nums;

    Solution test;
    bool res = test.searchMatrix(matrix, 6);
    cout << (res?  "Find it!" : "Not existed!") << endl;

    res = test.searchMatrix(matrix, 25);
    cout << (res?  "Find it!" : "Not existed!") << endl;

    
    return 0;
}