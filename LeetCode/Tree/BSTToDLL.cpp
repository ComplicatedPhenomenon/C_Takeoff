/**
 * @file
 * \brief
 * source: https://leetcode.com/problems/binary-tree-inorder-traversal/
 * 
 **/

#include<iostream>
#include<array>
#include"tree.h"
using namespace std;

class Solution {
public:
    TreeNode * reconstrucBinaryTree(TreeNode * root) {
        TreeNode* curr = root; 
        TreeNode* minNode = root;
        TreeNode * previousNodeBeforeCurr = NULL;

        while (minNode -> left){
            minNode = minNode -> left;
        }

        while(curr != NULL) {
            if(curr -> left == NULL){
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
        return minNode;    
    }

    void SLLToDLL(TreeNode * head){
        TreeNode *tem = head;

        // tem can reach the second last node in while condition
        while (tem->right){
            tem -> right -> left = tem;
            tem = tem -> right;
        }
    }
};

int main() {
    struct TreeNode *root; 
    root = newNode(12);
    root -> left = newNode(6);
    root -> right = newNode(18);
    root -> left -> left = newNode(4);;
    root -> left -> right = newNode(9);
    root -> left -> left -> left = newNode(0); 
    root -> left -> left -> right = newNode(5); 
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(22);
    root -> left -> right -> left = newNode(7);
    root -> left -> right -> right = newNode(10);
    root -> right -> right -> left = newNode(21);
    root -> right -> right -> right = newNode(23);

    Solution test; 
    TreeNode *head = test.reconstrucBinaryTree(root);
    test.SLLToDLL(head);

    TreeNode * tem = head;
    cout << "Double linked list in ascending order: ";
    while(tem -> right){
        cout << tem -> val << " ";
        tem = tem -> right;
    }
    cout << tem -> val << endl;

    cout << "Double linked list in descending order: ";
    while(tem){
        cout << tem -> val << " ";
        tem = tem -> left;
    }
    cout << endl;

    while(head){
        tem = head;
        head = head -> right;
        free(tem);
    }   
    
    return 0;
}