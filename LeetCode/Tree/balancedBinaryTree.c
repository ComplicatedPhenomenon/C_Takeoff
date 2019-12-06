//https://leetcode.com/problems/balanced-binary-tree/


/** 

    a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

    Input: 
          3
         / \
        9  20
      /  \
    15   7
    
    Output: True 

    Input: 
          1
         / \
        2   2
       / \
      3   3
     / \
    4   4
    
    Output: False 
 **/

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"tree.h"

int maxDepth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}

bool isBalanced(struct TreeNode *root) {
    if (root == NULL)
        return true;
    
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    int d = l - r;
    if (d == 0 || d == 1 || d == -1) {
        if (isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        else return false;
    }
    else return false;
}

int main() {
    int res;
    struct TreeNode* root;
    struct TreeNode* tem = newNode(2);
    root = tem;
 
    tem = newNode(3);
    root -> left = tem;

    tem = newNode(4);
    root -> left -> left = tem;

    tem = newNode(5);
    root -> left -> right = tem;

    res = isBalanced(root);
    printf("%d\n", res);
    freeBinaryTree(root);
    return 0;
}

