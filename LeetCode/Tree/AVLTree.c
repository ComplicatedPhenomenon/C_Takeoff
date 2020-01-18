/**
 * gcc -Wall tree.c AVLTree.c 
 * valgrind ./a.out
 **/

#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
#define MAX 4096

int max(int a, int b) { 
	return (a > b) ? a : b; 
} 

int getHeight(struct AVLTreeNode* node) { 
	if (node == NULL) 
		return 0; 
	return node -> height; 
} 

int heightDifference(struct AVLTreeNode* node){
    if (!node) return 0;
    return getHeight(node -> left) - getHeight(node -> right);
}


struct AVLTreeNode * rotateLeft(struct AVLTreeNode* root){
    struct AVLTreeNode *newRoot = root -> right;
    struct AVLTreeNode *T2 = newRoot -> left;

    newRoot -> left = root;
    root -> right = T2;

    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    newRoot -> height = max(getHeight(newRoot ->  left), getHeight(newRoot -> right)) + 1;
    return newRoot;
    

}
struct AVLTreeNode * rotateRight(struct AVLTreeNode* root){
    struct AVLTreeNode *newRoot = root -> left;
    struct AVLTreeNode *T2 = newRoot -> right;

    newRoot -> right = root;
    root -> left = T2;

    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    newRoot -> height = max(getHeight(newRoot ->  left), getHeight(newRoot -> right)) + 1;
    return newRoot;
}


struct AVLTreeNode * insert(struct AVLTreeNode *root, struct AVLTreeNode *newNode){
    if(!root) 
        return newNode;
    if (root -> value > newNode -> value) 
        root -> left = insert(root -> left, newNode); 
    else if (root -> value < newNode -> value)  
        root -> right = insert(root -> right, newNode); 
    else
        return root;

    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    int diff = heightDifference(root);

    if (diff > 1 && root -> left -> value > newNode -> value){
        return rotateRight(root);
    }
    if (diff > 1 && root -> left -> value < newNode -> value ){
        root -> left = rotateLeft(root -> left);
        return rotateRight(root);
    }
    if (diff < -1 && root -> right -> value < newNode -> value) {
        return rotateLeft(root);
    }
    if (diff < -1 && root -> right -> value > newNode -> value) {
        root -> right = rotateRight(root -> right);
        return rotateLeft(root);
    }
    return root;
}

int main(){
    struct AVLTreeNode *root = NULL;
    struct AVLTreeNode *tem = NULL;
    int data[] = {5, 3, 1, 7, 9};
    int len = sizeof(data)/sizeof(data[0]);
    for(int i = 0; i < len; ++i){
        tem = newAVLTreeNode(data[i]);
        root = insert(root, tem);
    }

    int numberOfRows = 0;
    int *numberOfElementsInEachRow = NULL; // pointing to a 1D array
    int **res = levelOrderAVLTreeTranversal(root, &numberOfElementsInEachRow, &numberOfRows);
    printf("number of row: %d\n", numberOfRows );

    int i, j;
    for (i = 0; i < numberOfRows; i++) {
        for (j = 0; j < numberOfElementsInEachRow[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX; i++) free(res[i]);

    free(res);
    free(numberOfElementsInEachRow);
    freeAVLTree(root);

    
    return 0;
}