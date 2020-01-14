/**
 *   Modified Date: 01/14/2020
 *   Description: Approach for Level order A BST by pushing node  into a queue level by level
 **/
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#define MAX 4096

/**
    limited by the paradigm, you can do nothing with the fact that
    struct QueueNode, struct Queue, void push, void * pop 
    should formed a class, with struct Queue as private attribute
 **/
struct QueueNode {
    struct TreeNode *ptr;
    struct QueueNode *next;
};

struct Queue{
    struct QueueNode *front;
    struct QueueNode *tail;
};

void push(struct Queue *queue, struct TreeNode *new_val) {
    struct QueueNode *new_node = malloc(sizeof(struct QueueNode));
    new_node -> ptr = new_val;
    new_node -> next = NULL;

    if (!queue -> front) queue -> front = new_node;  
     
    /*update the last node of the queue*/
    if (queue -> tail) queue -> tail -> next = new_node;
    queue -> tail = new_node;
}

// ? struct TreeNode * pop(struct Queue * queue), type void can be cast to struct TreeNode.
void *pop(struct Queue * queue) {
    void *ans;
    
    if (!queue -> front) {
        printf("Poping from an empty Queue\n");
        ans = NULL;
    }
    else {
        ans = queue -> front -> ptr;
        struct QueueNode *tmp = queue -> front;
        queue -> front = queue -> front -> next;
        // the front node walk away, the last node remains if the queue is not empty
        if (!queue -> front) queue -> tail = NULL;
        free(tmp);
    }

    return ans;
}

int ** levelOrder(struct TreeNode *root, int **numberOfElementsInEachRow, int *numberOfRows) {
    /**
     * root: a pointer pointing to the root node of this tree.
     * output as a pointer pointing to a 2D dynamic array, 
     * the number of rows and columns also are specified.
     * numberOfRows: the number of rows in this 2D array
     * numberOfElementsInEachRow: the number of elements in each row
     **/

    if (!root) return NULL;

    int **ans = calloc(MAX, sizeof(int *));
    *numberOfElementsInEachRow = calloc(MAX, sizeof(int));

    struct Queue q;
    q.front = q.tail = NULL;
    push(&q, root);

    ans[0] = (int *)calloc(1, sizeof(int)); /* for the root node */

    *numberOfRows = 0;
    
    int numberOfNodesInCurrentLevel = 1; /* number of nodes in current level, except NULL nodes */
    int numberOfNodesInNextLevel = 0; /* number of nodes in next level, except NULL nodes */
    int count = 0; /* count of nodes already traversed in current level */

    while (q.front) {
        struct TreeNode *p = pop(&q);

        if (p) { /* push children into queue if parent is not NULL */
            ans[*numberOfRows][count] = p -> val;
            count++;

            if (p -> left) {
                push(&q, p -> left);
                numberOfNodesInNextLevel++;
            }
            if (p -> right) {
                push(&q, p -> right);
                numberOfNodesInNextLevel++;
            }
        }

        if (count == numberOfNodesInCurrentLevel) {
            (*numberOfElementsInEachRow)[*numberOfRows] = numberOfNodesInCurrentLevel;
            (*numberOfRows)++;

            ans[*numberOfRows] = calloc(numberOfNodesInNextLevel, sizeof(int)); 
            numberOfNodesInCurrentLevel = numberOfNodesInNextLevel;
            count = numberOfNodesInNextLevel = 0;
        }
    }
    return ans;
}

int main() {
    struct TreeNode *root; 
    root = newNode(2);
    root -> left = newNode(3);
    root -> right = newNode(4);
    root -> left -> left = newNode(5);;
    root -> left -> right = newNode(6);
    root -> right -> right = newNode(7);
    root -> right -> right -> right = newNode(9);
    
    int numberOfRows = 0;
    int *numberOfElementsInEachRow = NULL; // pointing to a 1D array
    int **res = levelOrder(root, &numberOfElementsInEachRow, &numberOfRows);
    printf("number of row: %d\n", numberOfRows );

    int i, j;
    for (i = 0; i < numberOfRows; i++) {
        for (j = 0; j < numberOfElementsInEachRow[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        //free(res[i]);
    }

    for (i = 0; i < MAX; i++) free(res[i]);

    free(res);
    free(numberOfElementsInEachRow);
    freeBinaryTree(root);

    return 0;
}