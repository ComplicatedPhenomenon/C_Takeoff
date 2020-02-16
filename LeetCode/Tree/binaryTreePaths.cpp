/*! 
 * @file
 * \brief
 * source: https://leetcode.com/problems/binary-tree-paths
 * 
 * ```
 * Input:
 *
 *         1
 *       /   \
 *      2     3
 *       \
 *        5
 *
 *  Output: ["1->2->5", "1->3"]
 * ```
 */

#include<iostream>
#include<vector>
#include<cstdlib>
#include"tree.h"
using namespace std;

class Solution {
public:
    void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
        if(!root->left && !root->right) {
            result.push_back(t);
            return;
        }
        if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
        if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;

        binaryTreePaths(result, root, to_string(root->val));
        return result;
    }
};

int main(){
    struct TreeNode *root; 
    root = newNode(2);
    root -> left = newNode(3);
    root -> right = newNode(4);
    root -> left -> left = newNode(5);;
    root -> left -> right = newNode(6);
    root -> right -> right = newNode(7);
    Solution test;
    vector<string> res = test.binaryTreePaths(root);
    for(string const & i: res) cout << i << " ";
    cout << endl;
    freeBinaryTree(root);
    
    struct TreeNode *emptyTree = NULL;
    res = test.binaryTreePaths(emptyTree);
    for(string const & i: res) cout << i << " ";
    cout << endl;
    
    return 0;
}