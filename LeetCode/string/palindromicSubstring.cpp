/**
 * source:https://leetcode.com/problems/palindromic-substrings/
 * 
 * Given a string, your task is to count how many palindromic substrings in this string.
 * 
 * The substrings with different start indexes or end indexes are counted as different
 * substrings even they consist of same characters.
 **/

#include<iostream>
#include<string>
#include <array>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++){
            res += expandAroundCenter(s, i, i, res);
            res += expandAroundCenter(s, i, i+1, res);
        }
        return res;
    }
private:
    int expandAroundCenter(string &s, int left, int right, int &res){
        int n = 0;
        while(left >= 0 && right < s.size() && s[left--] == s[right++]) {
            n++;
        }
        return n;
    }
};

int main() {
    string s = "abcb";
    Solution test;
    int res = test.countSubstrings(s);
    cout << "The number of palindromic sub string of <"  + s + "> is: " << res << endl;
    return 0;
}