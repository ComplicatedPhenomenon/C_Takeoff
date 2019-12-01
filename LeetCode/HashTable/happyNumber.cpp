/**
 * source: https://leetcode.com/problems/happy-number/
**/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Solution {
private:
    int sumAllOfTheDigits(int n){
        int ans = 0;
        while(n != 0){
            ans += pow(n%10, 2);
			n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        bool rep[1000];
        memset(rep, 0, sizeof(rep));
		n = sumAllOfTheDigits(n);
        while(rep[n] == false){
			rep[n] = true;
            if(n == 1)
                return true;   
			n = sumAllOfTheDigits(n);
        }
        return false;
    }
};

int main(){
    int n = 18;
    Solution test;
    bool res = test.isHappy(n);
    cout << n; 
    cout << (res ?  " is " : " is not ") << "Happy Number" << endl;
}