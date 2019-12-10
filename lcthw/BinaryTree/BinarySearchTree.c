/* Key point: Recursion of insert */

#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *left;
    char info;
    struct node *right;
} Node;

Node *insert(int target, Node *node);
void inorderTraversal(Node *root);
void freeTree(Node *root);


int main() {
    int nums[] = {13, 9, 15, 3, 11, 7, 16};
    size_t len = sizeof(nums)/sizeof(nums[0]);
    int i;
    Node *root = NULL;

    printf("Numbers to be inserted Binary Search Tree: ");
    for (i = 0; i < len; i++) {
        root = insert(nums[i], root);
        printf("%d ", nums[i]);
    }
    printf("\n");

    /* printf("%d, %d\n", root -> info, root -> left -> info);*/
    inorderTraversal(root);
    freeTree(root);
    
    return 0;
}

Node *insert(int target, Node *node){
    if(node == NULL){
        Node * tem = (Node *)malloc(sizeof(Node));
        tem -> info = target;
        tem -> left = NULL;
        tem -> right = NULL;
        node = tem;
    }
    else{
        //(node -> info >= target) ? insert(target, node -> left) : insert(target, node -> right); /*No warning from compiler*/
        if (node -> info >= target)
            node -> left = insert(target, node -> left);
        else
            node -> right = insert(target, node -> right);

        // think over the above logic
    }
    return node;
}

void inorderTraversal(Node *root) {
    if(root != NULL){
        inorderTraversal(root -> left);
        printf("%d  ", root -> info);
        inorderTraversal(root -> right);
        printf("\n");
    }
 }

void freeTree(Node *root) {
    if(root != NULL){
        freeTree(root -> left);
        freeTree(root -> right);
        free(root);
    }
}
