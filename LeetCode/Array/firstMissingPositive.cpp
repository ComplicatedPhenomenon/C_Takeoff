/**
 * source:https://leetcode.com/problems/first-missing-positive/
 * 
 * Given an unsorted integer array, find the smallest missing positive integer.
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * hints: algorithm/sort/bucketSort.c
 * */

#include<iostream>
#include<vector>
#include<array>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 1;

        int assistant[n];
        fill_n(assistant, n, 0);

        for(int i = 0; i < n; i++){
            if (nums[i] > 0 && nums[i] <= n) 
                assistant[nums[i] - 1]++;
        }
        
        cout << "assistant array is: ";
        for(const int i: assistant)
            cout << i << " ";
        cout << endl;
        

        for(int i = 0; i < n; i++){
            if (assistant[i] == 0) return i+1;
        } 
        return n + 1;
    }
};


int main() { 
    vector<int> array = {1, 2, -1, 6};
    vector<int> &nums = array;
    Solution test;
    int res = test.firstMissingPositive(nums);
    cout << "Output is:" << res << endl;

    array = {};
    res = test.firstMissingPositive(nums);
    cout << "Output is:" << res << endl;

    array = {1,2};
    res = test.firstMissingPositive(nums);
    cout << "Output is:" << res << endl;

    array = {1};
    res = test.firstMissingPositive(nums);
    cout << "Output is:" << res << endl;

    return 0;
}