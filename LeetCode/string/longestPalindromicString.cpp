/**
 *  source: https://leetcode.com/problems/longest-palindromic-substring
 * 
 *  总容易想到的是，选定中心点，向向两边扩展
 *  Notice!!!
 *  Define int expandAroundCenter(string &s, int left, int right)
 *  not int expandAroundCenter(string s, int left, int right)
 *  the later consume much memory space.
 **/
#include<iostream>
#include<string>
#include <array>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() == true) return "";

        int start = 0, end = 0; 
        for (int i = 0; i < s.size(); i++){
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2); 
            if(len > end -start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
private:
    int expandAroundCenter(string &s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right -left - 1;
    }
};

int main() {
    string s = "abddbaccabdd";
    Solution test;
    string res = test.longestPalindrome(s);
    cout << "The longest palindromic string of <"  + s + "> is: " + res << endl;
    return 0;
}