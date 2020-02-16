/**
 *  @file
 *  \brief
 * source: https://leetcode.com/problems/path-sum/
 * ```
 *        5
 *       / \
 *      4   8
 *     /   / \
 *    11  13  4
 *   /  \      \
 *  7    2      1
 *
 * Given the below binary tree and sum = 22,
 * ```
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"tree.h"

bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) 
        return false;
    if (root -> val == sum && root -> left ==  NULL && root -> right == NULL) 
        return true;
    return hasPathSum(root -> left, sum-root -> val) || hasPathSum(root -> right, sum-root -> val);
}

int main(){
    struct TreeNode *root; 
    root = newNode(5);
    root -> left = newNode(4);
    root -> right = newNode(8);
    root -> left -> left = newNode(11);;
    root -> right -> left = newNode(13);
    root -> right -> right = newNode(4);
    root -> left -> left -> left = newNode(7);
    root -> left -> left -> right = newNode(2);
    root -> right -> right -> right = newNode(1);
    hasPathSum(root, 22) ? printf("Path existed!\n") : printf("Path does not existed!\n");

    freeBinaryTree(root);

    return 0;
}
