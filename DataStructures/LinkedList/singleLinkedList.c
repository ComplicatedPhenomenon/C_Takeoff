#include"singleLinkedList.h"
#include<stdio.h>
#include <stdlib.h>

listNode *newNode(int val) {  
    listNode *node = (listNode *) malloc(sizeof(listNode));
    node -> data = val;  
    node -> next = NULL;  
    return node;  
} 

int lengthOfSLL(listNode *head) {
    if(!head) return 0;

    listNode *tem = head;
    int i = 0;
    while (tem){
        tem = tem -> next;
        i += 1;
    }
    return i;
}

void printSLL(listNode *head) {
    if(!head) {
        printf("Empty linked list\n");
        return;
    }
    listNode *curr;
    curr = head;
    printf("single linked list: ");
    while (curr -> next) {
        printf ("%d -> ", curr -> data);
        curr = curr -> next;
    }
    printf("%d\n", curr -> data);
}

void freeSLL(listNode *head) {
    listNode *curr;
    while( (curr=head) != NULL) {
        head = head -> next;
        free(curr);
    }
}

listNode * reverseSLL(listNode *head) {
    listNode * tem = head;
    listNode * prev = NULL;
    listNode * nexttem; 
    // what if head is NULL? omitting the below LoC cause Segmentation fault
    if (tem == NULL || tem -> next == NULL) {}
    else{
        while(tem -> next != NULL){
            nexttem = tem -> next; 
            tem -> next = prev;
            prev = tem;
            tem = nexttem;
        }
        tem -> next = prev;
        head = tem;
    }
    return head;
}

listNode *reversePartOfSLL(listNode  *head, int m, int n) {
    listNode *dummy = (listNode *)malloc(sizeof(listNode));
    dummy -> next = 0;
    listNode *pre = dummy;
    listNode *temp, *cur;
    dummy -> next = head;
    for (int i = 1; i < m; i++) {
       pre = pre -> next;
    }
    cur = pre -> next;
    for (int i = m; i < n; i++) {
       temp = pre -> next;
       pre -> next = cur -> next;
       cur -> next = cur -> next -> next;
       pre -> next -> next = temp;
    }
    head = dummy -> next;
    free(dummy);
    return head;
}

listNode *insertToSLL(listNode  *head, int position, int val){
    int len = lengthOfSLL(head);
    // check position belongs to [1, len + 1]
    if(position == 1) {
        listNode *tem = newNode(val);
        tem -> next = head;
        head = tem;
    }
    else if(position > len + 1){
        printf("Illegal postion, as the current length is %d\n", len);
    }
    else{
        listNode *tem = head;
        int i = 1;

        //when position == 2, tem should point to head
        while(i < position - 1){
            tem = tem -> next; 
            i += 1; 
        }
        listNode *nextTem = tem -> next;
        tem -> next = newNode(val);
        tem = tem-> next;
        tem -> next = nextTem;
    }
    return head;
}

listNode *removeElementsOfSLL(listNode* head, int val) {
    listNode *tem = head;

    /* Condition to change the head */
    while (tem && tem -> data == val){
        listNode  *nextTem = tem -> next;
        free(tem);
        tem = nextTem;
    }
    head = tem;

    listNode *prev = tem;
    while(tem) {
        tem = tem -> next;
        if (!tem) { 
            return head;
        }
        else if(!tem->next){
            if (tem -> data == val) {
                free(tem);
                prev -> next = NULL;
                return head;
            } 
        }
        else{
            listNode *nextTem = tem -> next;
            if (tem -> data == val) {
                free(tem);
                prev -> next = nextTem;
                tem = prev;
            }
            else {
                prev = tem;
            }     
        }
    }
    return head;
}