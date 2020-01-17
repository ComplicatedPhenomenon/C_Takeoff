/**
 * 
 **/ 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 4096

// Basic type definitions:
enum color_t { BLACK, RED };

struct RBNode {
    struct RBNode* parent;
    struct RBNode* left;
    struct RBNode* right;
    enum color_t color;
    int key;
};

struct RBNode* newRBNode(int k) {
    struct RBNode *tem = malloc(sizeof(struct RBNode));
    tem -> key = k;
    tem -> parent = NULL;
    tem -> left = NULL;
    tem -> right = NULL;
    tem -> color = RED;
    return tem;
}

struct QueueRBNode {
    struct RBNode *ptr;
    struct QueueRBNode *next;
};

struct Queue{
    struct QueueRBNode *front;
    struct QueueRBNode *tail;
};

void push(struct Queue *queue, struct RBNode *new_val) {
    struct QueueRBNode *new_node = malloc(sizeof(struct QueueRBNode));
    new_node -> ptr = new_val;
    new_node -> next = NULL;

    if (!queue -> front) queue -> front = new_node;  
    if (queue -> tail) queue -> tail -> next = new_node;
    queue -> tail = new_node;
}

void *pop(struct Queue * queue) {
    void *ans;
    
    if (!queue -> front) {
        printf("Poping from an empty Queue\n");
        ans = NULL;
    }
    else {
        ans = queue -> front -> ptr;
        struct QueueRBNode *tmp = queue -> front;
        queue -> front = queue -> front -> next;
        // the front node walk away, the last node remains if the queue is not empty
        if (!queue -> front) queue -> tail = NULL;
        free(tmp);
    }

    return ans;
}

/*levelOrder return a 2 dimensional array of pointers, which point to RBNode*/
struct RBNode *** levelOrder(struct RBNode *root, int **numberOfElementsInEachRow, int *numberOfRows) {
    if (!root) return NULL;

    struct RBNode ***ans = calloc(MAX, sizeof(int *));
    *numberOfElementsInEachRow = calloc(MAX, sizeof(int));

    struct Queue q;
    q.front = q.tail = NULL;
    push(&q, root);

    ans[0] = calloc(1, sizeof(struct RBNode *)); /* for the root node */

    *numberOfRows = 0;
    
    int numberOfRBNodesInCurrentLevel = 1; /* number of nodes in current level, except NULL nodes */
    int numberOfRBNodesInNextLevel = 0; /* number of nodes in next level, except NULL nodes */
    int count = 0; /* count of nodes already traversed in current level */

    while (q.front) {
        struct RBNode *p = pop(&q);

        if (p) { /* push children into queue if parent is not NULL */
            ans[*numberOfRows][count] = p ;
            count++;

            if (p -> left) {
                push(&q, p -> left);
                numberOfRBNodesInNextLevel++;
            }
            if (p -> right) {
                push(&q, p -> right);
                numberOfRBNodesInNextLevel++;
            }
        }

        if (count == numberOfRBNodesInCurrentLevel) {
            (*numberOfElementsInEachRow)[*numberOfRows] = numberOfRBNodesInCurrentLevel;
            (*numberOfRows)++;

            ans[*numberOfRows] = calloc(numberOfRBNodesInNextLevel, sizeof(struct RBNode*)); 
            numberOfRBNodesInCurrentLevel = numberOfRBNodesInNextLevel;
            count = numberOfRBNodesInNextLevel = 0;
        }
    }
    return ans;
}

struct RBNode *treeInsert(struct RBNode *root, struct RBNode *newNode){
    if(root == NULL) root = newNode;
    else{
        if (root -> key > newNode -> key) { 
            root -> left = treeInsert(root -> left, newNode); 
        }
        else{ 
            root -> right = treeInsert(root -> right, newNode); 
        }
    }
    return root;
}

void freeBinaryTree(struct RBNode* root) {
    if(root != NULL){
        freeBinaryTree(root -> left);
        freeBinaryTree(root -> right);
        free(root);
    }
}

int main(){
    struct RBNode *root = NULL;
    struct RBNode *tem = NULL;

    int a[] = {11, 5, 4, 15, 17, 19};
    int len = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < len; ++i){
        tem = newRBNode(a[i]);
        root = treeInsert(root, tem);
    }

    int numberOfRows = 0;
    int *numberOfElementsInEachRow = NULL; // pointing to a 1D array
    struct RBNode ***res = levelOrder(root, &numberOfElementsInEachRow, &numberOfRows);
    printf("number of row: %d\n", numberOfRows );

    int i, j;
    for (i = 0; i < numberOfRows; i++) {
        for (j = 0; j < numberOfElementsInEachRow[i]; j++) {
            printf("{key: %.*d, color: %s} ", 2, res[i][j] -> key, res[i][j] -> color == 1 ? "RED" : "BLACK");
        }
        printf("\n");
    }

    for (i = 0; i < MAX; i++) free(res[i]);

    free(res);
    free(numberOfElementsInEachRow);
    freeBinaryTree(root);


    return 0;
}