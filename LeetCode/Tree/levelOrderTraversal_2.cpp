/**
 * @brief
 * \file
 * ![](../../figures/levelOrderTraversal.svg)
 */ 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
 };

class Solution {
public:
    vector<vector<int>> levelOrder(struct TreeNode* root) {
        if (!root) { return {}; }
        vector<int> row;
        vector<vector<int> > result;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            if (q.front()->left) {q.push(q.front()->left);}
            if (q.front()->right) {q.push(q.front()->right);}
            row.push_back(q.front()->val), q.pop();
            if (--count == 0) {  // the logic here is a bit implicit. decrease count by one of every pop 
                result.emplace_back(row), row.clear();
                count = q.size(); // count the number of node in current level
            }
        }
        return result; 
    }
};

struct TreeNode * newNode(int val) {  
    struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node->val = val;  
    node->left = NULL;  
    node->right = NULL;  
    return node;  
} 

void freeBinaryTree(struct TreeNode* root) {
    if(root != NULL){
        freeBinaryTree(root -> left);
        freeBinaryTree(root -> right);
        free(root);
    }
}

int main ( ) {
    struct TreeNode *root; 
    root = newNode(2);
    root -> left = newNode(3);
    root -> right = newNode(4);
    root -> left -> left = newNode(5);;
    root -> left -> right = newNode(6);
    root -> right -> right = newNode(7);

    Solution test;
    auto res = test.levelOrder(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0 ; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }  

    freeBinaryTree(root);

    
    // careful, here you are doing arithmetic on pointer
    root = (struct TreeNode *)calloc(7, sizeof(struct TreeNode));
    root -> val = 3;
    root -> left = root + 1;
    root -> right = root + 2;

    (root + 1) -> val = 9;

    (root + 2) -> val = 20;
    (root + 2) -> left = root + 5;
    (root + 2) -> right = root + 6; 

    (root + 5) -> val = 15;
    (root + 6) -> val = 7;

    res = test.levelOrder(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0 ; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }  

    free(root);
    

    return 0;
}