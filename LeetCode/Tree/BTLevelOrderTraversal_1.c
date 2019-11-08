/**
 *   Modified Date: 11/08/2019
 *   Description:
 *   Todo: Hardly understand and there is memory leak
 **/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
    limited by the paradigm, you can do nothing with the fact that
    struct QueueNode, struct Queue, void push, void * pop 
    should formed a class, with struct Queue as private attribute
 **/
struct QueueNode {
    void *ptr;
    struct QueueNode *next;
};

struct Queue{
    struct QueueNode *front;
    struct QueueNode *tail;
};

void push(struct Queue *queue, void *new_val) {
    struct QueueNode *new_node = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    new_node->ptr = new_val;
    new_node->next = NULL;

    if (queue->tail != NULL) queue->tail->next = new_node;
    queue->tail = new_node;
    if (queue->front == NULL) queue->front = new_node;   
}

void * pop(struct Queue * queue) {
    void *ans;
    
    if (queue->front == NULL) ans = NULL;
    else {
        ans = queue->front->ptr;
        struct QueueNode *tmp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL) queue->tail = NULL;
        free(tmp);
    }

    return ans;
}

int ** levelOrder(struct TreeNode * root, int ** columnSizes, int * returnSize) {
    if (root == NULL) return NULL;

    #define MAX 4096
    int **ans = (int **)calloc(MAX, sizeof(int *));
    *columnSizes = (int *)calloc(MAX, sizeof(int));

    struct Queue q;
    q.front = q.tail = NULL;
    push(&q, root);

    ans[0] = (int *)calloc(1, sizeof(int)); /* for the root node */

    *returnSize = 0;
    int next = 0; /* number of nodes in next level, except NULL nodes */
    int cur = 1; /* number of nodes in current level, except NULL nodes */
    int count = 0; /* count of nodes already traversed in current level */

    while (q.front != NULL) {
        struct TreeNode *p = pop(&q);

        if (p) { /* push children into queue if parent is not NULL */
            ans[*returnSize][count] = p->val;
            count++;

            if (p->left) {
                push(&q, p->left);
                next++;
            }
            if (p->right) {
                push(&q, p->right);
                next++;
            }
        }

        if (count == cur) {
            (*columnSizes)[*returnSize] = cur;
            (*returnSize)++;

            ans[*returnSize] = (int *)calloc(next, sizeof(int)); /* for next level */

            cur = next;
            count = next = 0;
        }
    }
    return ans;
}

void freeBinaryTree(struct TreeNode* root) {
    if(root != NULL){
        freeBinaryTree(root -> left);
        freeBinaryTree(root -> right);
        free(root);
    }
}

int main() {
    struct TreeNode *root = (struct TreeNode *)calloc(7, sizeof(struct TreeNode));
    struct TreeNode *p = root;

    // construct a binary tree
    p->val = 3;
    p->left = root + 1;
    p->right = root + 2;

    p = root + 1;
    p->val = 9;

    p = root + 2;
    p->val = 20;

    p->left = root + 5;
    p->right = root + 6;

    p = root + 5;
    p->val = 15;

    p = root + 6;
    p->val = 7;

    int *columnSizes = NULL;
    int returnSize = 0;
    int **res = levelOrder(root, &columnSizes, &returnSize);

    int i, j;
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < columnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }

    free(res);
    free(columnSizes);
    free(root);
    //freeBinaryTree(root);

    return 0;
}