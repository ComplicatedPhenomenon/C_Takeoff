/**
 * source: https://leetcode.com/problems/maximum-product-subarray/
 **/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
     int maxProduct(vector<int>& nums) {
        int res = INT8_MIN, iMax = 1, iMin = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){ 
              int tmp = iMax;
              iMax = iMin;
              iMin = tmp;
            }
            iMax = max(iMax*nums[i], nums[i]);
            iMin = min(iMin*nums[i], nums[i]);
            
            res = max(res, iMax);
        }
        return res;
    }
};

int main(){
    vector<int> array = {-1, 0, -2};

    vector<int> &nums = array;
    Solution test;
    int res = test.maxProduct(nums);
    cout << res << endl;

    return 0;
}


