/**
 * C Program to Implement Binary Tree using Linked List
 **/

#include <stdio.h>
#include <malloc.h>
struct node {
    struct node * left;
    char data;
    struct node * right;
};

struct node *constructBST( int );
void inorder_transversal(struct node *);
void freeTree(struct node *root);

char array[ ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'j', 'i', 'H' };
int leftcount[ ] = {  1,   3,   5,   -1,   9,  -1,  -1,   -1,   -1,  -1 };
int rightcount[ ] = {  2,   4,   6,   -1,  -1,  -1,  -1,   -1,   -1,  -1 };

void main() {
    struct node *root;
    root = constructBST( 0 );
    printf("In-order Traversal: \n");
    inorder_transversal(root);
    freeTree(root);
}

struct node * constructBST( int index ) {
    struct node *temp = NULL;
    if (index != -1) {
        temp = (struct node *)malloc( sizeof ( struct node ) );
        temp->left = constructBST( leftcount[index] );
        temp->data = array[index];
        temp->right = constructBST( rightcount[index] );
    }
    return temp;
}

void inorder_transversal( struct node *root ) {
    if (root != NULL) {
        inorder_transversal(root->left);
        printf("%c\t", root->data);
        inorder_transversal(root->right);
    }
    printf("\n");
}


void freeTree(struct node *root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
