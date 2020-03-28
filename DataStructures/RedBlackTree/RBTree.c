/*!
 * @file
 * \file RBTree.c
 * reference https://brilliant.org/wiki/red-black-tree/
 * \note
 * 1. 2 black children, in which case the black parent still has 2 children.
 * 2. 1 black child and 1 red child, in which case the black parent now has 3 children.
 * 3. 2 red children, in which case the black parent now has 4 children.
 */ 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 4096

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


struct RBNode* getParent(struct RBNode* n) {
    return !n ? NULL : n -> parent; 
}

struct RBNode* getGrandParent(struct RBNode* n) {
    // Note that it will return NULL if this is root or child of root
    return getParent(getParent(n));
}

struct RBNode* getSibling(struct RBNode* n) {
    struct RBNode* p = getParent(n);
    // No parent means no sibling.
    if (p == NULL) return NULL;
    return (n == p->left) ?  p->right: p->left;
}

struct RBNode* getUncle(struct RBNode* n) {
    struct RBNode* p = getParent(n);
    // No parent means no uncle
    return getSibling(p);
}

// rotate is likely change the root code of the tree
struct RBNode *  rotateLeft(struct RBNode *root, struct RBNode* node) {
    struct RBNode* sibling = node -> right;
    node -> right = sibling -> left;
    assert(sibling != NULL);  // Since the leaves of a RED-BLACK tree are empty,
                          // they cannot become internal nodes.
  
    if (sibling -> left)
        sibling -> left -> parent = node;
    sibling -> parent = node -> parent;
    if (!node -> parent)
        root  = sibling;
    else {
        if (node == node -> parent -> left)
            node -> parent -> left = sibling;
        else
            node -> parent -> right = sibling;
    }
    sibling -> left = node;
    node -> parent = sibling;
    return root;
}

struct RBNode * rotateRight(struct RBNode *root, struct RBNode* node) {
    struct RBNode* sibling = node -> left;
    node -> left = sibling -> right;
    //struct RBNode* p = getParent(node);
    assert(sibling != NULL);  // Since the leaves of a RED-BLACK tree are empty,
                          // they cannot become internal nodes.
  
    if (sibling -> right)
        sibling -> right -> parent = node;
    sibling -> parent = node -> parent;
    if (!node -> parent)
        root  = sibling;
    else {
        if (node == node -> parent -> right)
            node -> parent -> right = sibling;
        else
            node -> parent -> left = sibling;
    }
    sibling -> right = node;
    node -> parent = sibling;
    return root;
}

/*!
 * \brief insert a node into a red black tree
 * \param root a pointer pointing to the root node of the red black tree
 * \param nodeToBeInserted the new coming node
 * \return the root of the red black tree
 */
struct RBNode * insert(struct RBNode *root, struct RBNode *nodeToBeInserted) {    
    if (!root){
        nodeToBeInserted -> color = BLACK;
        root = nodeToBeInserted;
        return root;
    }
    
    struct RBNode *curr = root;
    // elegant!!! the approach of inserting a node by iterative approach is elegant
    struct RBNode *potentialParent = NULL;
    while (curr) {
        potentialParent = curr;
        curr = (nodeToBeInserted -> key < curr -> key) ? curr -> left : curr -> right;
    }

    nodeToBeInserted -> parent = potentialParent;
    (nodeToBeInserted -> key < potentialParent -> key) ? 
    (potentialParent -> left = nodeToBeInserted) : (potentialParent -> right = nodeToBeInserted);     
    
    /* Now restore the RED-BLACK property */
    while ((nodeToBeInserted != root) && (nodeToBeInserted -> parent -> color == RED)) {
       
        if (getParent(nodeToBeInserted) == getGrandParent(nodeToBeInserted) -> left ) {
            printf(" case like with 5, 3, then insert 2 or 4\n");
            struct RBNode * y = getUncle(nodeToBeInserted);
            //uncle node is NULL
            if(!y) {
                if (nodeToBeInserted == getParent(nodeToBeInserted) -> right) {
                    printf("case like :5, 3, 4\n");
                    /* case 2 - move nodeToBeInserted up and rotate */
                    nodeToBeInserted = nodeToBeInserted -> parent;
                    root = rotateLeft(root, nodeToBeInserted);
                }
                /* case 3 */
                printf("case like :5, 3, 1\n");
                nodeToBeInserted -> parent -> color = BLACK;
                getGrandParent(nodeToBeInserted) -> color = RED;
                root = rotateRight(root, getGrandParent(nodeToBeInserted));
            } 
            else if (y -> color == BLACK ) {
                printf("y -> color == Black\n");
                if (nodeToBeInserted == getParent(nodeToBeInserted) -> right) {
                    printf("case like :5, 3, 4\n");
                    nodeToBeInserted = getParent( nodeToBeInserted);
                    root = rotateLeft(root, nodeToBeInserted);
                    printf("check");
                }
                printf("case like :5, 3, 2\n");
                getParent(nodeToBeInserted) -> color = BLACK;
                getGrandParent(nodeToBeInserted) -> color = RED;
                root = rotateRight(root, getGrandParent(nodeToBeInserted));
            } 
            else {
                printf("y -> color == RED\n");
                /* case 1 - change the colors */
                nodeToBeInserted -> parent -> color = BLACK;
                y -> color = BLACK;
                getGrandParent(nodeToBeInserted) -> color = RED;
                /* Move nodeToBeInserted up the tree, ensure the RB Tree's property iteratively*/
                nodeToBeInserted = getGrandParent(nodeToBeInserted);
                printf("no need to rotate\n");
            }   
  
        }    
        else {
            /* repeat the "if" part with right and left exchanged */
            printf(" case like with 5, 8, then insert 7 or 9\n");
            struct RBNode * y = getGrandParent(nodeToBeInserted) -> left;
            if (!y){
                if (nodeToBeInserted == nodeToBeInserted -> parent -> left) {
                    if (nodeToBeInserted){ 
                    nodeToBeInserted = nodeToBeInserted -> parent;
                    root = rotateRight(root, nodeToBeInserted);
                    }
                }
                nodeToBeInserted -> parent -> color = BLACK;
                getGrandParent(nodeToBeInserted) -> color = RED;
                root = rotateLeft(root, getGrandParent(nodeToBeInserted));
            }
            else if (y -> color == BLACK){
                if (nodeToBeInserted == nodeToBeInserted -> parent -> left) {
                    if (nodeToBeInserted){ 
                    nodeToBeInserted = nodeToBeInserted -> parent;
                    root = rotateRight(root, nodeToBeInserted);
                    }
                }
                nodeToBeInserted -> parent -> color = BLACK;
                getGrandParent(nodeToBeInserted) -> color = RED;
                root = rotateLeft(root, getGrandParent(nodeToBeInserted));
            }
            else {
                nodeToBeInserted -> parent -> color = BLACK;
                y -> color = BLACK;
                getGrandParent(nodeToBeInserted) -> color = RED;
                nodeToBeInserted = getGrandParent(nodeToBeInserted);
             }
        }
    }
    root -> color = BLACK;
    return root;
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
        if (root -> key > newNode -> key) 
            root -> left = treeInsert(root -> left, newNode); 
        else
            root -> right = treeInsert(root -> right, newNode); 
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

    int a[] = {7, 5, 2, 9, 10, 11, 12, 13, 16, 14, 19, 17, 21, 20, 25, 23, 29};
    int len = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < len; ++i){
        tem = newRBNode(a[i]);
        //tem = treeInsert(a[i]);
        root = insert(root, tem);
    }

    int numberOfRows = 0;
    int *numberOfElementsInEachRow = NULL; // pointing to a 1D array
    struct RBNode ***res = levelOrder(root, &numberOfElementsInEachRow, &numberOfRows);
    printf("\033[1;31m!insertion Done.\033[0m Number of row: %d\n", numberOfRows );
   

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