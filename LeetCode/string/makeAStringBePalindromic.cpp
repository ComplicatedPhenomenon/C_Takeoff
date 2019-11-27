/**
 * source: https://leetcode.com/problems/shortest-palindrome/
 * 
 * Given a string s, you are allowed to convert it to a palindrome by 
 * adding characters in front of it. Find and return the shortest palindrome 
 * you can find by performing this transformation.
 * 
 * Input: "abcd"
 * Output: "dcbabcd"
 * 
 * !I have no clue to come up with this solution
 **/

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }
        if (i == n)
            return s;
        string remain_rev = s.substr(i, n);
        reverse(remain_rev.begin(), remain_rev.end());
        
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};

int main() {
    string s = "abcd";

    Solution test;
    string res = test.shortestPalindrome(s);
    cout << "Original string: " << s << ", now becomes: " << res << endl;

    return 0;
}