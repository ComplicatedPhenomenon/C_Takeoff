#ifndef SINGLE_LINKED_LIST_H
#define SINGEL_LINKED_LIST_H
struct listNode{
    int val;
    struct listNode*next;
};

struct listNode* newNode(int val);
void printSLL(struct listNode *head); 
void freeSLL(struct listNode *head);
struct listNode* generateARandomSLL(int len);
#endif