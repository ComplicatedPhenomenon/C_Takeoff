// Source: https://leetcode.com/problems/subsets/

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

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        unsigned int n = nums.size();
        vector<vector<int>> ans;

        if (n == 0) return ans;
        quicksort(nums, 0, n - 1);
        vector<int> temp;
        
        for (unsigned int i = 0; i < (1 << n); i++) {
            unsigned int t = i;
            unsigned int k = 0;
            while (t) {
                if (t & 1) {
                    temp.push_back(nums[k]);
                }
                t >>= 1;
                k++;
            }

            ans.push_back(temp);
            temp.clear();
        }
        return ans;
        
    }


    void quicksort(vector<int> &nums, int start, int end) {
        if (start >= end) return;
        int i = start;
        int j = end;
        int sentinal = nums[start];
        while (i < j) {
            while (i < j && nums[j] >= sentinal)
                j--;

            nums[i] = nums[j];
            while (i < j && nums[i] <= sentinal)
                i++;

            nums[j] = nums[i];
        }

        nums[i] = sentinal;

        quicksort(nums, start, i - 1);
        quicksort(nums, i + 1, end);
    }
};

 
int main() {
    vector<vector<int>> res;
    Solution test;
    auto ans = test.subsets(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0 ; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}