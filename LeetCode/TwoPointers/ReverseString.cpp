#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    void reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
    }
};

int main() {
    string text = "Being an actor is fantastic";
    Solution test;
    test.reverseString(text);
    cout << text << endl;
    return 0;
}