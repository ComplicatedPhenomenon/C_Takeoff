#ifndef TREE_H_
#define TREE_h_
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode * newNode(int val);
void freeBinaryTree(struct TreeNode* root); 
#endif