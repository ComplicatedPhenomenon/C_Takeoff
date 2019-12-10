/**
 * source: https://leetcode.com/problems/binary-tree-inorder-traversal/
 * ToDo: Changing the structure of the tree makes the way to free the tree space invalid
 **/

#include<iostream>
#include<vector>
#include"tree.h"
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr -> left == NULL){
                res.push_back(curr -> val);
                curr = curr -> right;
            }
            else{
                TreeNode* prev = curr -> left;
                while(prev -> right != NULL) prev = prev -> right;
                prev -> right = curr;
                TreeNode* tem = curr;
                curr = curr -> left;
                tem -> left = NULL;
            }
        }

        return res;    
    }
};

int main() {
    struct TreeNode *root; 
    root = newNode(2);
    root -> left = newNode(3);
    root -> right = newNode(4);
    root -> left -> left = newNode(5);;
    root -> left -> right = newNode(6);
    root -> right -> right = newNode(7);
    Solution test;
    vector<int> res = test.inorderTraversal(root);
    for(const int &i: res) cout << i << "";
    cout << endl;
    freeBinaryTree(root);
    return 0;
}