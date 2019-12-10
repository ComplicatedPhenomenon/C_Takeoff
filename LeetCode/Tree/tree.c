#include<stdlib.h>
#include"tree.h"

struct TreeNode * newNode(int val) {  
    struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node -> val = val;  
    node -> left = NULL;  
    node -> right = NULL;  
    return node;  
} 

void freeBinaryTree(struct TreeNode* root) {
    if(root != NULL){
        freeBinaryTree(root -> left);
        freeBinaryTree(root -> right);
        free(root);
    }
}