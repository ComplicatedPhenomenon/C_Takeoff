/**
 * source: https://leetcode.com/problems/path-sum/
 * 
 *       5
        / \
       4   8
      /   / \
     11  13 4
    /  \   /  \
   7    2 5    1

   Given the below binary tree and sum = 22,
   return 
   [
   [5,4,11,2],
   [5,8,4,5]
   ]
 **/

#include<iostream>
#include<vector>
#include"tree.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};

int main(){
    struct TreeNode *root; 
    root = newNode(5);
    root -> left = newNode(4);
    root -> right = newNode(8);
    root -> left -> left = newNode(11);;
    root -> right -> left = newNode(13);
    root -> right -> right = newNode(4);
    root -> left -> left -> left = newNode(7);
    root -> left -> left -> right = newNode(2);
    root -> right -> right -> left = newNode(5);
    root -> right -> right -> right = newNode(1);
    Solution test;
    vector<vector<int>> res = test.pathSum(root, 22);
    for (vector<int> const &item: res){
        for(int const &i: item){
            cout << i << " ";
        }
        cout << endl;
    }
    freeBinaryTree(root);
    return 0;
}