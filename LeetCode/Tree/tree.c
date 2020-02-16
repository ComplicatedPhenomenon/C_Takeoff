#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#define MAX 4096

struct TreeNode * newNode(int val) {  
    struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node -> val = val;  
    node -> left = NULL;  
    node -> right = NULL;  
    return node;  
} 


struct AVLTreeNode* newAVLTreeNode(int val) {
    struct AVLTreeNode *tem = malloc(sizeof(struct AVLTreeNode));
    tem -> value = val;
    tem -> height = 1;
    tem -> left = NULL;
    tem -> right = NULL;
    return tem;
}

void freeBinaryTree(struct TreeNode* root) {
    if(root != NULL){
        freeBinaryTree(root -> left);
        freeBinaryTree(root -> right);
        free(root);
    }
}

void freeAVLTree(struct AVLTreeNode* root) {
    if(root != NULL){
        freeAVLTree(root -> left);
        freeAVLTree(root -> right);
        free(root);
    }
}


struct queueBinaryTreeNode {
    struct TreeNode *ptr;
    struct queueBinaryTreeNode *next;
};

struct binaryTreeQueue{
    struct queueBinaryTreeNode *front;
    struct queueBinaryTreeNode *tail;
};

void pushTreeNode(struct binaryTreeQueue *queue, struct TreeNode *new_val) {
    struct queueBinaryTreeNode *new_node = malloc(sizeof(struct queueBinaryTreeNode));
    new_node -> ptr = new_val;
    new_node -> next = NULL;

    if (!queue -> front) queue -> front = new_node;  
     
    /*update the last node of the queue*/
    if (queue -> tail) queue -> tail -> next = new_node;
    queue -> tail = new_node;
}

// ? struct TreeNode * popTreeNode(struct binaryTreeQueue * queue), type void can be cast to struct TreeNode.
void *popTreeNode(struct binaryTreeQueue * queue) {
    void *ans;
    
    if (!queue -> front) {
        printf("Poping from an empty binaryTreeQueue\n");
        ans = NULL;
    }
    else {
        ans = queue -> front -> ptr;
        struct queueBinaryTreeNode *tmp = queue -> front;
        queue -> front = queue -> front -> next;
        // the front node walk away, the last node remains if the queue is not empty
        if (!queue -> front) queue -> tail = NULL;
        free(tmp);
    }

    return ans;
}

int ** levelOrderBinaryTreeTranversal(struct TreeNode *root, int **numberOfElementsInEachRow, int *numberOfRows) {
    /**
     * ~~~~~~~~~~~~~~~{.c}
     * int ** levelOrderBinaryTreeTranversal(struct TreeNode *root, int **numberOfElementsInEachRow, int *numberOfRows) 
     * ~~~~~~~~~~~~~~~
     * #### Parameters
     * - root
     *    
     *   a pointer pointing to the root node of this tree.
     * - numberOfElementsInEachRow 
     *  
     *   the number of elements in each row
     * - numberOfRows
     *   
     *   the number of rows in this 2D array
     * 
     * #### Returns
     * output as a pointer pointing to a 2D dynamic array, 
     * the number of rows and columns also are specified.
     */

    if (!root) return NULL;

    int **ans = calloc(MAX, sizeof(int *));
    *numberOfElementsInEachRow = calloc(MAX, sizeof(int));

    struct binaryTreeQueue q;
    q.front = q.tail = NULL;
    pushTreeNode(&q, root);

    ans[0] = (int *)calloc(1, sizeof(int)); /* for the root node */

    *numberOfRows = 0;
    
    int numberOfNodesInCurrentLevel = 1; /* number of nodes in current level, except NULL nodes */
    int numberOfNodesInNextLevel = 0; /* number of nodes in next level, except NULL nodes */
    int count = 0; /* count of nodes already traversed in current level */

    while (q.front) {
        struct TreeNode *p = popTreeNode(&q);

        if (p) { /* pushTreeNode children into queue if parent is not NULL */
            ans[*numberOfRows][count] = p -> val;
            count++;

            if (p -> left) {
                pushTreeNode(&q, p -> left);
                numberOfNodesInNextLevel++;
            }
            if (p -> right) {
                pushTreeNode(&q, p -> right);
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


struct AVLQueueNode {
    struct AVLTreeNode *ptr;
    struct AVLQueueNode *next;
};

struct AVLQueue{
    struct AVLQueueNode *front;
    struct AVLQueueNode *tail;
};

void pushAVLTreeNode(struct AVLQueue *queue, struct AVLTreeNode *new_val) {
    struct AVLQueueNode *new_node = malloc(sizeof(struct AVLQueueNode));
    new_node -> ptr = new_val;
    new_node -> next = NULL;

    if (!queue -> front) queue -> front = new_node;  
     
    /*update the last node of the queue*/
    if (queue -> tail) queue -> tail -> next = new_node;
    queue -> tail = new_node;
}

// ? struct TreeNode * popAVLTreeNode(struct AVLQueue * queue), type void can be cast to struct TreeNode.
void *popAVLTreeNode(struct AVLQueue * queue) {
    void *ans;
    
    if (!queue -> front) {
        printf("Poping from an empty AVLQueue\n");
        ans = NULL;
    }
    else {
        ans = queue -> front -> ptr;
        struct AVLQueueNode *tmp = queue -> front;
        queue -> front = queue -> front -> next;
        // the front node walk away, the last node remains if the queue is not empty
        if (!queue -> front) queue -> tail = NULL;
        free(tmp);
    }

    return ans;
}

int ** levelOrderAVLTreeTranversal(struct AVLTreeNode *root, int **numberOfElementsInEachRow, int *numberOfRows) {
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

    struct AVLQueue q;
    q.front = q.tail = NULL;
    pushAVLTreeNode(&q, root);

    ans[0] = (int *)calloc(1, sizeof(int)); /* for the root node */

    *numberOfRows = 0;
    
    int numberOfNodesInCurrentLevel = 1; /* number of nodes in current level, except NULL nodes */
    int numberOfNodesInNextLevel = 0; /* number of nodes in next level, except NULL nodes */
    int count = 0; /* count of nodes already traversed in current level */

    while (q.front) {
        struct AVLTreeNode *p = popAVLTreeNode(&q);

        if (p) { /* pushAVLTreeNode children into queue if parent is not NULL */
            ans[*numberOfRows][count] = p -> value;
            count++;

            if (p -> left) {
                pushAVLTreeNode(&q, p -> left);
                numberOfNodesInNextLevel++;
            }
            if (p -> right) {
                pushAVLTreeNode(&q, p -> right);
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


