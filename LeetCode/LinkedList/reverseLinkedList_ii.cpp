// https://leetcode.com/problems/reverse-linked-list-ii/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       head = dummy -> next;
       free (dummy);
       return head;
   }
};

int main(){
    ListNode * head;
    ListNode * tem = new ListNode(1);
    head = tem; 
    ListNode * tail = tem;

    tem = new ListNode(2);
    tail -> next = tem;
    tail = tem;
    tem = new ListNode(3);
    tail -> next = tem;
    tail = tem;
    tem = new ListNode(4);
    tail -> next = tem;
    tail = tem;
    tem = new ListNode(5);
    tail -> next = tem;
    tail = tem;

    Solution test;
    head = test.reverseBetween(head, 2, 4);

    tem = head;
    while (tem != NULL) {
        cout << tem -> val << " ";
        tem = tem -> next;
    }
   
    while(head != NULL){
        tem = head;
        head = head -> next;
        free(tem);
    }
    
    return 0;
}
