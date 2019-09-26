/**
  https://leetcode.com/problems/path-sum/
 **/

#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum){
        if (root == NULL) return false;
        if (root -> val == sum && root -> left ==  NULL && root -> right == NULL) return true;
        return hasPathSum(root -> left, sum-root -> val) || hasPathSum(root -> right, sum-root -> val);
    }

int main(){
    struct TreeNode *root = NULL;



    /**
     * Construct a general binary tree
                      5
                     / \
                    4   8
                   /   / \
                  11  13  4
                 /  \      \
                7    2      1
     *
     **/


    return 0;

}
