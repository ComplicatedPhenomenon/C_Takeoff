/**
 * source: https://leetcode.com/problems/merge-two-sorted-lists/
 * 
 **/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"singleLinkedList.h"

struct listNode* mergeTwoLists(struct listNode *l1, struct listNode *l2){
    if (!l1 && !l2) return NULL;
    else if(!l1 && l2) return l2;
    else if(l1 && !l2) return l1;
    struct listNode *head = NULL;
    if (l1 -> val > l2 -> val){
        head = l2;
        l2 = l2 -> next;   
    }
    else{
        head = l1;
        l1 = l1 -> next;
    }
    struct listNode *tail = head;
    tail -> next = NULL;
    while(l1 && l2){
        if (l1 -> val > l2 -> val){
            tail -> next = l2;
            l2 = l2 -> next;
            tail = tail -> next;
            tail -> next = NULL;
        }
        else{
            tail -> next = l1;
            l1 = l1 -> next;
            tail = tail -> next;
            tail -> next = NULL;   
        }
    }
    if (l1){
        tail -> next = l1;
    }
    if (l2){
        tail -> next = l2;
    }
    return head;
}

int main(){
    srand(time(NULL));
    // case 1 
    struct listNode *l1 = generateARandomSLL(0);
    struct listNode *l2 = generateARandomSLL(0);
    struct listNode *head = mergeTwoLists(l1, l2);
    printSLL(head);

    // case 2
    l1 = generateARandomSLL(0);
    l2 = generateARandomSLL(3);
    head = mergeTwoLists(l1, l2);
    printSLL(head);
    freeSLL(head); 

    // case 3
    l1 = generateARandomSLL(5);
    l2 = generateARandomSLL(3);
    head = mergeTwoLists(l1, l2);
    printSLL(head);
    freeSLL(head);

    return 0;
}
