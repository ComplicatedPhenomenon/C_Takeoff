/**
 * source: https://leetcode.com/problems/find-the-duplicate-number/
 * 
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
 * find the duplicate one.
 * 
 *   Input: [1,3,4,2,2]
 *   Output: 2
 * 
 * 1. You must not modify the array (assume the array is read only).
 * 2. You must use only constant, O(1) extra space.
 * 3. Your runtime complexity should be less than O(n2).
 * 4. There is only one duplicate number in the array, but it could be repeated more than once.
 * 
 * requirement of O(1) space complexity not satisfied
 **/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Haven't apply the condition that each integer is between 1 and n(inclusive) O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> tem;
        for(auto i:nums){
            if(tem.find(i) == tem.end()){
                tem.insert(i);
            }
            else{
                return i;
            }
        }
        return -1;        
    }
};

// O(log(n))
class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int low = 1;
        int high = n;
        int mid;
        while(low < high){
            mid=(low + high) / 2;
            int count = 0;
            for(int num:nums){
                if(num <= mid) count++;
            }
            if(count > mid) high = mid;
            else low = mid + 1; 
        }
        return low;
    }
};

int main(){
    vector<int> array = {3, 1, 3, 4, 2};
    vector<int> &nums = array;
    Solution test;
    int res = test.findDuplicate(nums);
    cout << res << endl; 

    Solution2 test2;
    int res2 = test2.findDuplicate(nums);
    cout << res2 << endl; 
}
