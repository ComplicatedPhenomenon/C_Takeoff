//source: https://leetcode.com/problems/valid-parentheses/

/**
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:
        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.
    
    Example
        Input: "([)]"
        Output: false
 **/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isValid(char * s){
    int len = strlen(s);
    if(len%2 != 0) return false;

    int limit = len/2;
    if (limit == 0) return true;
    
    char stack[limit];
    int idx = 0;
    
    for(int i=0; i<len; ++i){
        char cur = s[i];
        if(cur=='(' || cur=='{' || cur=='[') {
            if(idx == limit) return false;
            stack[idx++] = cur;
        }
        else {
            if(idx == 0) return false;
            if(cur == '}' && stack[idx-1] == '{' || cur == ']' && stack[idx-1] == '[' || cur == ')' && stack[idx-1] == '('){
                idx--;
            }else{
                return false;
            }
        }
    }
    return idx==0;
}


int main(){
    char strArray[] = "{}[]()";
    //printf("sizeof strArray is %ld\n", sizeof(strArray));
    size_t len = strlen(strArray);
    int i;

    for (i = 0; i < len; i++) printf("%c ", strArray[i]);
    isValid(strArray) ? printf(" is True\n") : printf(" is False\n");

    strcpy(strArray,"{}[(])");
    for (i = 0; i < len; i++) printf("%c ", strArray[i]);
    isValid(strArray) ? printf(" is True\n") : printf(" is False\n");

    return 0;
}
