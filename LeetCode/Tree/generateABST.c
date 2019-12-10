#include<stdio.h>
#include"tree.h"

struct TreeNode *insert(int target,  struct TreeNode *root){
    if(root == NULL){
        struct TreeNode * tem = newNode(target);
        root = tem;
    }
    else{
        if (root -> val > target) { 
            root -> left = insert(target, root -> left); 
        }
        else{ 
            root -> right = insert(target, root -> right); 
        }
    }
    return root;
}

void inorderTraversal( struct TreeNode *root){
    if(root == NULL) return;
    inorderTraversal(root -> left);
    printf("%d\n",  root -> val);
    inorderTraversal(root -> right);
}


int main() {
    int nums[] = {13, 9, 15, 3, 11, 7, 16};
    int len = sizeof(nums) / sizeof(nums[0]);
    int i;
    struct TreeNode * root = NULL;
    for (i = 0; i < len; i++) {
        root = insert(nums[i], root);
    }

    inorderTraversal(root);
    freeBinaryTree(root);
    return 0;
}