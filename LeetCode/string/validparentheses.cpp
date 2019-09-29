/**
 * Pass -std=c++11 to the compiler;
 * your (ancient) compiler is defaulting to C++03
 * and warning you that it is accepting some newer C++ constructs as extensions.
 **/
#include<iostream>
#include<string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '('|| c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.empty()) return false;
                if(c == ')' && st.top() != '(') return false;
                if(c == '}' && st.top() != '{') return false;
                if(c == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main(){
    string s1 = "{}[]()";
    string s2 = "{[}]";
    Solution xx;
    xx.isValid(s1) ?  cout << "True" << endl : cout << "False" << endl;
    xx.isValid(s2) ?  cout << "True" << endl : cout << "False" << endl;
    return 0;
}
