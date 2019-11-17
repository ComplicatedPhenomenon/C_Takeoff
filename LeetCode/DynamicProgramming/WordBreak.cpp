// source: https://leetcode.com/problems/word-break/

/**
    Given a non-empty string s and a wordDictionary wordDict containing a list of 
    non-empty words, determine if s can be segmented into a space-separated 
    sequence of one or more wordDictionary words.

    Note:

    The same word in the wordDictionary may be reused multiple times in the segmentation.
    You may assume the wordDictionary does not contain duplicate words.

    Input: s = "applepenapple", wordDict = ["apple", "pen"]
    Output: true
    Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
                Note that you are allowed to reuse a wordDictionary word.
 **/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j = i - 1;j >= 0; j--) {
                if(dp[j] == true) {
                    string word = s.substr(j, i - j);
                    cout << "searching <" << s.substr(j, i - j) << " > in wordDict" << endl;
                    if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                        dp[i]=true;
                        break; 
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};

int main() {
    string  s = "applepenapple";
    vector<string> wordDict = {"app", "apple", "pen"};

    cout << "s = " << s << endl;
    cout << "wordDict = { ";
    for(const string &s: wordDict) cout << s << " ";
    cout <<"}" << endl;

    Solution test;
    bool res = test.wordBreak(s, wordDict);
    res ? cout << "True" << endl :  cout << "False" << endl; 

    return 0;
}

