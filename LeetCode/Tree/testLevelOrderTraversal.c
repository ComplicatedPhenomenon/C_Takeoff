/**
 * @file
 * \brief
 * Modified Date: 01/14/2020
 * Description: Approach for Level order A BST by pushing node  into a queue level by level
 */
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#define MAX 4096

int main() {
    struct TreeNode *root; 
    root = newNode(2);
    root -> left = newNode(3);
    root -> right = newNode(4);
    root -> left -> left = newNode(5);;
    root -> left -> right = newNode(6);
    root -> right -> right = newNode(7);
    root -> right -> right -> right = newNode(9);
    
    int numberOfRows = 0;
    int *numberOfElementsInEachRow = NULL; // pointing to a 1D array
    int **res = levelOrderBinaryTreeTranversal(root, &numberOfElementsInEachRow, &numberOfRows);
    printf("number of row: %d\n", numberOfRows );

    int i, j;
    for (i = 0; i < numberOfRows; i++) {
        for (j = 0; j < numberOfElementsInEachRow[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        //free(res[i]);
    }

    for (i = 0; i < MAX; i++) free(res[i]);

    free(res);
    free(numberOfElementsInEachRow);
    freeBinaryTree(root);

    return 0;
}