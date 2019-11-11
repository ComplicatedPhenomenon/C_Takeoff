/**
    https://leetcode.com/problems/intersection-of-two-arrays/
 **/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> set;
        // hash the first array
        for(auto n : Number s1)
            set.insert(n);
        for(auto n : nums2) {
            if(set.find(n) != set.end()) { //  If the element is found, 
                set.erase(n);       // delete it from hash table
                res.push_back(n);
            }
        } 
        return res;
    }
};


int main() { 
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    Solution test;
    vector<int> res = test.intersection(nums1, nums2);
    for(int i: res) cout << i << " ";
    cout << endl;
    return 0;
}