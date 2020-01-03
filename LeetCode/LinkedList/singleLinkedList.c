#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"singleLinkedList.h"

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
    if (len == 0) return NULL;
    struct listNode* head = newNode(rand() % 10);
    struct listNode* curr = head;
    for(int i= 1; i < len; i++){
        int tem = rand() % 10;
        curr -> next = newNode(tem + curr -> val);
        curr = curr -> next;
    }
    return head;
}