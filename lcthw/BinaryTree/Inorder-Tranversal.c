/**
 * C Program to Implement Binary Tree using Linked List
 **/

#include <stdio.h>
//#include <malloc.h> it's been deprecated
#include<stdlib.h>

struct node {
    struct node *left;
    char data;
    struct node *right;
};

struct node *constructBST( int);
void inorderTranversal(struct node *);
void freeTree(struct node *root);

char array[ ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'j', 'i', 'H'};
int leftcount[ ] = { 1, 3, 5, -1, 9, -1, -1, -1, -1, -1};
int rightcount[ ] = { 2, 4, 6, -1, -1, -1, -1, -1, -1, -1};

int main(){
    struct node *root;
    root = constructBST(0);
    printf("In-order Traversal: \n");
    inorderTranversal(root);
    freeTree(root);

    return 0;
}

struct node *constructBST(int index) {
    struct node *temp = NULL;
    if (index != -1) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left = constructBST(leftcount[index]);
        temp->data = array[index];
        temp->right = constructBST(rightcount[index]);
    }
    return temp;
}

void inorderTranversal(struct node *root){
    if (root != NULL) {
        inorderTranversal(root->left);
        printf("%c\t", root->data);
        inorderTranversal(root->right);
    }
    printf("\n");
}


void freeTree(struct node *root){
    if(root != NULL){
        freeTree(root -> left);
        freeTree(root -> right);
        free(root);
    }
}
