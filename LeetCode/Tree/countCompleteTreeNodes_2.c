/**
 * source: https://leetcode.com/problems/count-complete-tree-nodes/
 * 
 **/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"tree.h"

int getLeftHeight(struct TreeNode* root) {
    int height = 0;
    while(root) {
        root = root->left;
        height++;
    }
    return height;
}

int countNodes(struct TreeNode* root) {
    if(!root) return 0;

    int left_height = getLeftHeight(root->left);
    int right_height = getLeftHeight(root->right);

    if(left_height == right_height)
        return pow(2, left_height) + countNodes(root->right);

    return pow(2, right_height) + countNodes(root->left);
}

int main() {
    struct TreeNode *root; 
    root = newNode(2);
    root -> left = newNode(3);
    root -> right = newNode(4);
    root -> left -> left = newNode(5);;
    root -> left -> right = newNode(6);
    root -> right -> right = newNode(7);
    
    printf("%d\n", countNodes(root));
    freeBinaryTree(root);
    return 0;
}