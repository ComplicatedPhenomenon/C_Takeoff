// source: https://leetcode.com/problems/letter-case-permutation/
/**
  Given a string S, we can transform every letter individually to be lowercase 
  or uppercase to create another string.  Return a list of all possible strings we could create.
  
  Examples:
    Input: S = "a1b2"
    Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

    Input: S = "3z4"
    Output: ["3z4", "3Z4"]

    Input: S = "12345"
    Output: ["12345"]
 **/
#include<iostream>
#include<array>
#include<vector>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        res.push_back("");
        for(const char & c: S) {
            if(isalpha(c)){
                array<char, 2> tem = {static_cast<char>(toupper(c)), static_cast<char>(tolower(c))};
                vector<string> temres = res;
                res.clear();
                for (string &r: temres ){
                    for (const char  &t: tem){
                        cout << "push: " << r + string(1,t) << endl;
                        res.push_back(r +string(1,t));
                    }
                }
            }
            else{
                vector<string> temres = res;
                res.clear();
                for(string &r: temres) {
                    cout << "push: " << r + string(1,c) << endl;
                    res.push_back(r + string(1,c)); 
                }     
            }
        }
        return res;
        }
};


int main() {
    string S = "a1b2";

    Solution test;
    vector<string> res = test.letterCasePermutation(S);

    for(string &item: res){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}