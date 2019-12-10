/**
 * source: https://leetcode.com/problems/count-complete-tree-nodes
 **/
#include<iostream>
#include<cmath>
#include"tree.h"
using namespace std;

class Solution {
public:
    int countNodes(TreeNode * root) {
        if(!root) return 0;
        int hl = 0, hr = 0;
        TreeNode *l = root, *r = root;
        while(l) {hl++; l = l -> left;}
        while(r) {hr++; r = r -> right;}
        if(hl == hr) return pow(2, hl) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
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
    int res = test.countNodes(root);
    cout << res << " nodes in total" << endl;
    freeBinaryTree(root);
    return 0;
}
