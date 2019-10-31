// https://leetcode.com/problems/subsets/

/** 
    Input: nums = [1,2,3]
    Output:
    [
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
    ]
 **/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
    }
};
*/
 
int main(){
    vector<int> nums = {1, 3, 2};
    vector<int> & numbers = nums;
    sort(nums.begin(), nums.end());
    for(const auto i: nums) {
        cout << i << " ";
    }
    cout << endl;

    vector<vector<int>> res;
    Solution test;
    res = test.subsets(nums);

    vector<vector<int>> res;
    vector<vector<int>>::const_iterator row;
    vector<int>::const_iterator col;
    for (row = res.begin(); row != res.end(); ++row) {
         for (col = row->begin(); col != row->end(); ++col) {
            cout << *col;
         }
    }
    cout << endl;
    
    return 0;
}