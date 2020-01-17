#include<stdio.h>
#include<stdlib.h>

// Basic type definitions:
enum color_t {BLACK, RED };

struct RBNode {
    struct RBNode* parent;
    struct RBNode* left;
    struct RBNode* right;
    enum color_t color;
    int key;
};

struct RBNode *root = NULL;

struct RBNode* getParent(struct RBNode* n) {
    return !n ? NULL : n -> parent; 
}

struct RBNode* getGrandParent(struct RBNode* n) {
    // Note that it will return NULL if this is root or child of root
    return getParent(getParent(n));
}

struct RBNode* getSibling(struct RBNode* n) {
    struct RBNode* p = getParent(n);
    // No parent means no sibling.
    if (p == NULL) return NULL;
    return (n == p->left) ?  p->right: p->left;
}

struct RBNode* getUncle(struct RBNode* n) {
    struct RBNode* p = getParent(n);
    // No parent means no uncle
    return getSibling(p);
}

void rotateLeft(struct RBNode* n) {
    struct RBNode* tem = n -> right;
    struct RBNode* p = getParent(n);
    assert(tem != NULL);  // Since the leaves of a RED-BLACK tree are empty,
                          // they cannot become internal nodes.
    n -> right = tem->left;
    tem -> left = n;
    n -> parent = tem;
    // Handle other child/parent pointers.
    if (n -> right != NULL) {
        n -> right -> parent = n;
    }

    // Initially n could be the root.
    if (p != NULL) {
        if (n == p->left) {
            p->left = tem;
    } 
    else if (n == p->right) {
        p->right = tem;
    }
    }
    tem->parent = p;
}

void rotateRight(struct RBNode* n) {
    struct RBNode* tem = n->left;
    struct RBNode* p = getParent(n);
    assert(tem != NULL);  // Since the leaves of a RED-BLACK tree are empty,
                              // they cannot become internal nodes.

    n->left = tem->right;
    tem->right = n;
    n->parent = tem;

    // Handle other child/parent pointers.
    if (n->left != NULL) {
        n->left->parent = n;
    }

    // Initially n could be the root.
    if (p != NULL) {
        if (n == p->left) {
            p->left = tem;
        } 
        else if (n == p->right) {
            p->right = tem;
        }
    }
    tem->parent = p;
}

struct RBNode * insert(struct RBNode *root, struct RBNode *x) {
    /* Insert in the tree in the usual way */
    root = treeInsert(root, x);

    /* Now restore the RED-BLACK property */
    while ( (x != root) && (x -> parent -> color == RED) ) {
       if ( x -> parent == x -> parent -> parent -> left ) {
           /* If x's parent is a left, y is x's right 'uncle' */
           struct RBNode * y = x -> parent -> parent -> right;
           if ( y -> color == RED ) {
               /* case 1 - change the colors */
               x -> parent -> color = BLACK;
               y -> color = BLACK;
               x -> parent -> parent -> color = RED;
               /* Move x up the tree */
               x = x -> parent -> parent;
            }
           else {
               /* y is a BLACK node */
               if ( x == x -> parent -> right ) {
                   /* and x is to the right */ 
                   /* case 2 - move x up and rotate */
                   x = x -> parent;
                   rotateLeft(x);
                }
               /* case 3 */
               x -> parent -> color = BLACK;
               x -> parent -> parent -> color = RED;
               rotateRight(x);
            }
        }
       else {
           /* repeat the "if" part with right and left
              exchanged */
           struct RBNode * y = x -> parent -> parent -> left;
           if ( y -> color == RED ) {
               /* case 1 - change the colors */
               x -> parent -> color = BLACK;
               y -> color = BLACK;
               x -> parent -> parent -> color = RED;
               /* Move x up the tree */
               x = x -> parent -> parent;
            }
           else {
               /* y is a BLACK node */
               if ( x == x -> parent -> left ) {
                   /* and x is to the right */ 
                   /* case 2 - move x up and rotate */
                   x = x -> parent;
                   rotateLeft(x);
                }
               /* case 3 */
               x -> parent -> color = BLACK;
               x -> parent -> parent -> color = RED;
               rotateRight(x);
            }
        }
    }
    root-> color = BLACK;
    return root;
}