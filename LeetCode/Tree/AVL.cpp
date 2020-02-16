#include<iostream> 
using namespace std; 

class Node { 
public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
}; 

int height(Node *N) { 
	if (N == NULL) 
		return 0; 
	return N -> height; 
} 

int max(int a, int b) { 
	return (a > b)? a : b; 
} 


Node* newNode(int key) { 
	Node* node = new Node(); 
	node -> key = key; 
	node -> left = NULL; 
	node -> right = NULL; 
	node -> height = 1; 
	return node; 
} 

Node *rightRotate(Node *root) { 
	Node *newRoot = root -> left; 
	Node *T2 = newRoot -> right; 

	newRoot -> right = root; 
	root -> left = T2; 

	root -> height = max(height(root -> left), height(root -> right)) + 1; 
	newRoot -> height = max(height(newRoot -> left), height(newRoot -> right)) + 1; 

	return newRoot; 
} 

Node *leftRotate(Node *root) { 
	Node *newRoot = root -> right; 
	Node *T2 = newRoot -> left; 

	newRoot -> left = root; 
	root -> right = T2; 

	root -> height = max(height(root -> left), height(root -> right)) + 1; 
	newRoot -> height = max(height(newRoot -> left), height(newRoot -> right)) + 1; 

	return newRoot; 
} 

int getBalance(Node *N) { 
	if (N == NULL) 
		return 0; 
	return height(N -> left) - height(N -> right); 
} 

Node* insert(Node* node, int key) { 
	if (node == NULL) 
		return(newNode(key)); 
	if (key < node -> key) 
		node -> left = insert(node -> left, key); 
	else if (key > node -> key) 
		node -> right = insert(node -> right, key); 
	else 
		return node; 

	node -> height = 1 + max(height(node -> left), height(node -> right)); 
	int balance = getBalance(node); 

	if (balance > 1 && key < node -> left -> key) 
		return rightRotate(node); 

	if (balance < -1 && key > node -> right -> key) 
		return leftRotate(node); 

	if (balance > 1 && key > node -> left -> key) { 
		node -> left = leftRotate(node -> left); 
		return rightRotate(node); 
	} 

	if (balance < -1 && key < node -> right -> key) { 
		node -> right = rightRotate(node -> right); 
		return leftRotate(node); 
	} 
	return node; 
} 

void preOrder(Node *root) { 
	if(root != NULL) { 
		cout << root -> key << " "; 
		preOrder(root -> left); 
		preOrder(root -> right); 
	} 
} 

void freeBinaryTree(Node* root) {
    if(root != NULL) {
        freeBinaryTree(root -> left);
        freeBinaryTree(root -> right);
        delete(root);
    }
}

int main() { 
	Node *root = NULL; 

	root = insert(root, 10); 
	root = insert(root, 20); 
	root = insert(root, 30); 
	root = insert(root, 40); 
	root = insert(root, 50); 
	root = insert(root, 25); 
	
	/* The constructed AVL Tree would be 
				 30 
			    / \ 
			   20 40 
			  / \  \ 
		    10  25 50 
	*/
	cout << "Preorder traversal of the "
			"constructed AVL tree is \n"; 
	preOrder(root); 
	cout << endl;

	freeBinaryTree(root);
	return 0; 
} 
