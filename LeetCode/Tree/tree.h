struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode * newNode(int val);
void freeBinaryTree(struct TreeNode* root); 