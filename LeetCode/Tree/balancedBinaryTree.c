/**
 * @file
 * \brief
 *
 * source: https://leetcode.com/problems/balanced-binary-tree 
 * 
 *  A binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * 
 * ```
 *   Input: 
 *         3
 *        / \
 *       9  20
 *      / \
 *    15   7
 *    
 *   Output: True 
 *
 *   Input: 
 *         1
 *        / \
 *       2   2
 *      / \
 *     3   3
 *    / \
 *   4   4
 *   
 *  Output: False 
 * ```
 * 
 * ## sample of debugging
 * ```md
 * (gdb) break main
 * (gdb) ...
 * (gdb) print tem.val
 * $3 = 2
 * (gdb) print tem
 * $4 = (struct TreeNode *) 0x555555757260
 * (gdb) print root
 * $5 = (struct TreeNode *) 0x0
 * (gdb) print root.val
 * Cannot access memory at address 0x0
 * (gdb) next
 * (gdb) print root.val
 * $6 = 2
 * ```
 */

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"tree.h"

/**
 * this recursive approach is too abstract to comprehend
 */ 
int maxDepth1(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    int l = maxDepth1(root->left);
    int r = maxDepth1(root->right);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}
/*
int maxDepth2(struct TreeNode *root){

}
*/


bool isBalanced(struct TreeNode *root) {
    if (root == NULL)
        return true;
    
    int l = maxDepth1(root->left);
    int r = maxDepth1(root->right);
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

