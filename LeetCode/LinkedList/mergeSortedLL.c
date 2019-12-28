/**
 * source : https://leetcode.com/problems/merge-k-sorted-lists/
 **/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Definition for singly-linked list.
struct listNode{
    int val;
    struct listNode*next;
};

struct listNode* newNode(int val) {
    struct listNode*tem = malloc(sizeof(struct listNode));
    tem -> val = val;
    tem -> next = NULL;
    return tem;
}

void printSLL(struct listNode *head) {
    if(!head) {
        printf("Empty linked list\n");
        return;
    }
    struct listNode *curr;
    curr = head;
    printf("single linked list: ");
    while (curr -> next) {
        printf ("%d -> ", curr -> val);
        curr = curr -> next;
    }
    printf("%d\n", curr -> val);
}


void freeSLL(struct listNode *head) {
    struct listNode *curr;
    while( (curr=head) != NULL) {
        head = head -> next;
        free(curr);
    }
}

struct listNode* generateARandomSLL(int len){
    struct listNode* head = newNode(0);
    struct listNode* curr = head;
    for(int i= 0; i < len; i++){
        int tem = rand() % 10;
        curr -> next = newNode(tem + curr -> val);
        curr = curr -> next;
    }
    return head;
}
  
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    
}

int main(){
    srand(time(NULL));
    int i;
    int row = 3;
    struct listNode** ptrToTwoDArray = calloc(row, sizeof(struct listNode**));
    for(i = 0; i < row; ++i) ptrToTwoDArray[i] = generateARandomSLL(i + 3);

    for(int i= 0; i < row; i++){
        printSLL(ptrToTwoDArray[i]);
    }
    
    for(int i= 0; i < row; i++){
        freeSLL(ptrToTwoDArray[i]);
    }
    free(ptrToTwoDArray);

    return 0;
}


