/**
 * source: https://leetcode.com/problems/two-sum/ 
 **/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
 
        for(int i = 0; i < nums.size(); i++){
        
            if ( hash.find(target - nums[i]) != hash.end()) {
                res.push_back(i);
                res.push_back(hash[target - nums[i]]);
                return res;
            }
            //hash[nums[i]] = i;
            hash.insert({nums[i], i});

        }
        return res;
    }
};


int main() {
    vector<int> arr = {2, 7, 11, 15};
    vector<int> &nums = arr;
    Solution test;
    vector<int> res  = test.twoSum(nums, 9);
    cout << "The index of element fit the situation is: ";
    for(const int i: res) cout << i << " ";
    cout << endl;
    return 0;
}