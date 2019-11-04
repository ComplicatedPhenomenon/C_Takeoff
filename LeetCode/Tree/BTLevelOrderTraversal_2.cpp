
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
            if (q.front()->left) { q.push(q.front()->left); }
            if (q.front()->right) { q.push(q.front()->right); }
            row.push_back(q.front()->val), q.pop();
            if (--count == 0) {
                result.emplace_back(row), row.clear();
                count = q.size();
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
    struct TreeNode* tem = newNode(2);
    root = tem;
 
    tem = newNode(3);
    root -> left = tem;

    tem = newNode(4);
    root -> left -> left = tem;

    tem = newNode(5);
    root -> left -> right = tem;

    Solution test;
    auto res = test.levelOrder(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0 ; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }  

    freeBinaryTree(root);
    return 0;
}