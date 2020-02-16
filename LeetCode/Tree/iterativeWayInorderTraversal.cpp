/**
 * @file
 * \brief
 * source: https://leetcode.com/problems/binary-tree-inorder-traversal/
 * It take me more than two hours to fix the memory leak
 **/

#include<iostream>
#include<vector>
#include"tree.h"
using namespace std;

class Solution {
public:
    TreeNode * inorderTraversal(TreeNode * root) {
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* minNode = root;
        TreeNode * previousNodeBeforeCurr = NULL;

        while (minNode -> left){
            minNode = minNode -> left;
        }

        while(curr != NULL) {
            if(curr -> left == NULL){
                res.push_back(curr -> val);
                previousNodeBeforeCurr = curr;
                curr = curr -> right;
                
            }
            else{
                
                TreeNode* prev = curr -> left;
                while(prev -> right != NULL) prev = prev -> right;
                prev -> right = curr;
                TreeNode* tem = curr;
                curr = curr -> left;
                tem -> left = NULL;
            
                if (previousNodeBeforeCurr){
                    previousNodeBeforeCurr -> right = curr;
                    previousNodeBeforeCurr -> left = NULL;
                }
            }
        }

        for(const int &i: res) cout << i << " ";
        cout << endl;

        return minNode;    
    }
};

int main() {
    struct TreeNode *root; 
    root = newNode(2);
    root -> left = newNode(3);
    root -> right = newNode(4);
    root -> left -> left = newNode(5);;
    root -> left -> right = newNode(6);
    root -> right -> left = newNode(0);
    root -> right -> right = newNode(7);
    Solution test;
    TreeNode *head = test.inorderTraversal(root);
    freeBinaryTree(head);

    root = newNode(12);
    root -> left = newNode(6);
    root -> right = newNode(18);
    root -> left -> left = newNode(4);;
    root -> left -> right = newNode(9);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(22);
    head = test.inorderTraversal(root);
    freeBinaryTree(head);
    return 0;
}