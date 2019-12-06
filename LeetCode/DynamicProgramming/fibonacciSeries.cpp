/**
 *  Fibonacci series:
 *  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 *  
 *  Improvements which are looking forward include:
 *  0. what if n is negative integer?
 *  1. Recursive approach requires too enormous memory when n is big
 *  2. When n is big, the corresponding result is too big for data type as integer
 **/


#include<iostream>
#include<vector>
using namespace std;


int fibRecursive(int n){
    if ((n == 0) | (n == 1)) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2); 
}

int helper(vector<int>& memo, int n) {
    if (n == 1 || n == 2) return 1;
    if (memo[n] != 0) return memo[n];
    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
}

int fib(int N) {
    if (N < 1) return 0;
    vector<int> memo(N + 1, 0);
    return helper(memo, N);
}



int nthFibonacciNumber(int n){
    if (n == 0 or n == 1) return n;
    int a = 0;
    int b = 1;
    int tem;
    for (int i = 2; i <= n ; i++){
        tem = a + b;
        a = b;
        b = tem;
    }
    return tem;
}

unsigned long int  optimizedNthFibonacciNumberUpdated(int n){
    unsigned long int a = 0;
    unsigned long int b = 1;
    for (int i = 0; i < n; i++){
        unsigned long int tem = a + b;
        a = b;
        b = tem;
    }
    return a;
}

int main(){
    int n = 20;
    cout << "The " <<  n << "th Fibonacci number is " << fibRecursive(n) << endl; 
    
    cout << "The " <<  n << "th Fibonacci number is " << nthFibonacciNumber(n) << endl;
    cout << "The " <<  n << "th Fibonacci number is " << fib(n) << endl; 

    n = 80;
    unsigned long int res = optimizedNthFibonacciNumberUpdated(n);
    cout << "The " << n << "th Fibonacci number is " << res << endl;
    n = 90; 
    res = optimizedNthFibonacciNumberUpdated(n);
    cout << "The " << n << "th Fibonacci number is " << res << endl;

    return 0;
}