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
                char t1 = static_cast<char>(toupper(c));
                char t2 = static_cast<char>(tolower(c));
                array<char, 2> tem = {t1, t2};
                for (string &r: res ){
                    for (const char  &t: tem){
                        char c1 = t;
                        string c2 = r;
                        auto c3 = std::string(1,c1)+c2;
                        cout << c3 << endl;
                        res.push_back(c3);
                    }
                }
            }
            else{
                for(auto &r: res) {
                    res.push_back(c + r);
                }   
            }
            for(string &item: res) cout << item << " ";
            cout << endl;
        }

        
        return res;
        }
};


int main() {
    string S = "ba";
    Solution test;
    char c1 = '1';
    char c2 = 'b';
    auto c3 = std::string(1,c1)+c2;
    cout << c3 << endl;
    vector<string> res = test.letterCasePermutation(S);
    
    for(string &item: res){
        cout << item << " ";
    }
    cout << endl;


    return 0;
}