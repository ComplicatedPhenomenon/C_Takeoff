#ifndef TREE_H_
#define TREE_h_
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct AVLTreeNode{
    int value;
    int height;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
};

struct TreeNode * newNode(int val);
struct AVLTreeNode* newAVLTreeNode(int val);

void freeBinaryTree(struct TreeNode* root); 
void freeAVLTree(struct AVLTreeNode* root); 

int ** levelOrderBinaryTreeTranversal(struct TreeNode *root, int **numberOfElementsInEachRow, int *numberOfRows);
int ** levelOrderAVLTreeTranversal(struct AVLTreeNode *root, int **numberOfElementsInEachRow, int *numberOfRows);
#endif