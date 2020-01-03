/**
 * source : https://leetcode.com/problems/merge-k-sorted-lists/
 * 
 * key point: 
 *   How to get the number of rows of an array according to the pointer refers 
 * to this array? https://stackoverflow.com/a/492410/7583919
 * 
 * ToDo: the approach is quiet slow
 **/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include"singleLinkedList.h"

bool any(struct listNode *lists[], int size){
    for (int i = 0; i < size; i++) {
        if (lists[i]){
            return true;
        }
    }
    return false;
}


struct listNode* mergeKLists(struct listNode** lists, int listsSize){
    if (listsSize == 0) return NULL; /* To avoid variable length array bound evaluates to non-positive value 0*/
    int i;
    struct listNode *tem[listsSize];
    for(i = 0; i < listsSize; i++){
        tem[i] = lists[i];
    }

    struct listNode *currMinNode = NULL;
    int minIndex = 999;

    // Initialize currMinNode and minIndex
    for(i = 0; i < listsSize; i++){
        if (!tem[i]){
            continue;
        }
        if (tem[i]){
            currMinNode = tem[i];
            minIndex = i;
            break;
        }
    }
    if (minIndex == 999) return NULL;
    // select the minimum node and index in first round
    for (i = 0; i < listsSize; i++){
        if (!tem[i]){
                continue;
        }
        if (currMinNode -> val > tem[i] -> val){
            currMinNode = tem[i];
            minIndex  = i; //Debug the program if this line of code missed
        }
    }
    tem[minIndex] = tem[minIndex] -> next;  /*runtime error: member access within null pointer of type 'struct ListNode'*/
    struct listNode* head = currMinNode;

    struct listNode* tail = head;
    tail -> next = NULL;
    printSLL(head);

    while(any(tem, listsSize)){
        for (i = 0; i < listsSize; i++){
            if (tem[i]) {
                currMinNode = tem[i];
                minIndex = i;
                break;
            }
        }
        /** 
        printf("new SLL: ");
        printSLL(head);
        **/
        for(i = 0; i < listsSize; i++){
            if (!tem[i]){
                continue;
            }
            if (currMinNode -> val > tem[i] -> val){
                currMinNode = tem[i];
                minIndex  = i;
            }
        }
        //printf("minIndex come from %d\n", minIndex);
        tem[minIndex] = tem[minIndex] -> next;    
        tail -> next = currMinNode;
        tail = tail -> next;
        tail -> next = NULL;
    } 
    return head;
}

int main(){
    srand(time(NULL));
    // test case 1 input as [[], [a->b->c], [d->e->f]]
    int i;
    int row = 3;
    struct listNode** ptrToTwoDArray = (struct listNode**) calloc(row, sizeof(struct listNode*));
    ptrToTwoDArray[0] = generateARandomSLL(0);
    for(i = 1; i < row; ++i) ptrToTwoDArray[i] = generateARandomSLL(i + 3);

    for(int i= 0; i < row; i++){
        printSLL(ptrToTwoDArray[i]);
    }
    
    struct listNode *head = mergeKLists(ptrToTwoDArray, row);
    printSLL(head);
    freeSLL(head);

    /*for(int i= 0; i < row; i++)  freeSLL(ptrToTwoDArray[i]); */
    free(ptrToTwoDArray);

    // test case 2: input as [[]]
    ptrToTwoDArray = (struct listNode**) calloc(1, sizeof(struct listNode*));
    ptrToTwoDArray[0] = generateARandomSLL(0);
    head = mergeKLists(ptrToTwoDArray, 1);
    printSLL(head);
    freeSLL(head);
    free(ptrToTwoDArray);
    return 0;
}

