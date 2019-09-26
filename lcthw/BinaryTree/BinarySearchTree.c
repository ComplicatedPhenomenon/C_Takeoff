/* Key point: Recursion of insert */

#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *left;
    char info;
    struct node *right;
} Node;

Node *insert(int target, Node *xnode);
void preorder(Node *root);
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
    preorder(root);
    freeTree(root);
    
    return 0;
}

Node *insert(int target, Node *xnode){
    if(xnode == NULL){
        Node * tem = (Node *)malloc(sizeof(Node));
        tem -> info = target;
        tem -> left = NULL;
        tem -> right = NULL;
        xnode = tem;
    }
    else{
        //(xnode -> info >= target) ? insert(target, xnode -> left) : insert(target, xnode -> right); /*No warning from compiler*/
        if (xnode -> info >= target)
            xnode -> left = insert(target, xnode -> left);
        else
            xnode -> right = insert(target, xnode -> right);

        // think over the above logic
    }
    return xnode;
}

void preorder(Node *root) {
    if(root != NULL){
        printf("%d  ", root -> info);
        preorder(root -> left);
        preorder(root -> right);
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
