/**
 * @file
 * Original author: https://github.com/robin-thomas/max-heap/blob/master/maxHeap.c
 * explanation goes to detail: http://robin-thomas.github.io/max-heap/
 * Description: The api of this program is less confusing to me now.
 * https://www.edureka.co/blog/heap-sort-in-c/
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LCHILD(x) 2 * x + 1 // The index of left child of xth node
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2 // The parent if xth node which is a left node

typedef struct{
    int data;
} node;

typedef struct{
    int size;
    node *elem;
} maxHeap;


// Function to initialize the max heap with size = 0
maxHeap initMaxHeap(int n) {
    maxHeap hp;
    hp.size = 0;
    hp.elem = malloc(n * sizeof(node));
    return hp;
}

void swap(node *n1, node *n2) {
    node temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heapify(maxHeap *hp, int i) {
    int largest = (LCHILD(i) < hp -> size && hp -> elem[LCHILD(i)].data > hp -> elem[i].data) ? LCHILD(i) : i;
    if(RCHILD(i) < hp -> size && hp -> elem[RCHILD(i)].data > hp -> elem[largest].data) largest = RCHILD(i);

    if(largest != i){
        swap(&(hp -> elem[i]), &(hp -> elem[largest]));
        heapify(hp, largest);
    }
}

void buildMaxHeap(maxHeap *hp, int *arr, size_t len) {
    int i;
    printf("Building a MaxHeap\n");
    for(i = 0; i < len; i++){
        hp -> elem = (hp -> size != 0) ? realloc(hp -> elem, (hp -> size + 1) * sizeof(node)) : malloc(sizeof(node));
        /*`*realloc(void *ptr, size_t size)` attempts to resize the memory block pointed to by ptr that
        was previously allocated with a call to malloc or calloc.*/
        node nd;
        nd.data = arr[i];
        hp -> elem[(hp -> size)++] = nd;
    }

    for(i = PARENT(hp -> size); i >= 0; i--) {
        heapify(hp, i);
    }
}


/*
    Function to insert a node into the max heap, by allocating space for that node in the
    heap and also making sure that the heap property and shape propety are never violated.
*/
void insertNode(maxHeap *hp, int data) {
    node nd;
    nd.data = data;

    int i = (hp -> size)++;
    while(i && nd.data > hp -> elem[PARENT(i)].data) {
        hp -> elem[i] = hp -> elem[PARENT(i)];
        i = PARENT(i);
    }
    hp -> elem[i] = nd;
}


/*
    Function to delete a node from the max heap
    It shall remove the root node, and place the last node in its place
    and then call heapify function to make sure that the heap property
    is never violated
*/
void deleteNode(maxHeap *hp) {
    if(hp -> size) {
        printf("Deleting node %d\n\n", hp -> elem[0].data);
        hp -> elem[0] = hp -> elem[--(hp -> size)];
        hp -> elem = realloc(hp -> elem, hp -> size * sizeof(node));
        heapify(hp, 0);
    } else {
        printf("\nMax Heap is empty!\n");
        free(hp -> elem);
    }
}


/*
    Function to get minimum node from a max heap
    The minimum node shall always be one of the leaf nodes. So we shall recursively
    move through both left and right child, until we find their minimum nodes, and
    compare which is smaller. It shall be done recursively until we get the minimum
    node
*/
int getMinNode(maxHeap *hp, int i) {
    if(LCHILD(i) >= hp -> size) {
        return hp -> elem[i].data;
    }

    int l = getMinNode(hp, LCHILD(i));
    int r = getMinNode(hp, RCHILD(i));

    if(l <= r) {
        return l;
    } else {
        return r;
    }
}

void deleteMaxHeap(maxHeap *hp) {
    free(hp -> elem);
}

void inOrderTraversal(maxHeap *hp, int i) {
    if(LCHILD(i) < hp -> size) {
        inOrderTraversal(hp, LCHILD(i));
    }
    printf("%d ", hp -> elem[i].data);
    if(RCHILD(i) < hp -> size) {
        inOrderTraversal(hp, RCHILD(i));
    }
}

void preorderTraversal(maxHeap *hp, int i) {
    if(LCHILD(i) < hp -> size) {
        preorderTraversal(hp, LCHILD(i));
    }
    if(RCHILD(i) < hp -> size) {
        preorderTraversal(hp, RCHILD(i));
    }
    printf("%d ", hp -> elem[i].data);
}

void postOrderTraversal(maxHeap *hp, int i) {
    printf("%d ", hp -> elem[i].data);
    if(LCHILD(i) < hp -> size) {
        postOrderTraversal(hp, LCHILD(i));
    }
    if(RCHILD(i) < hp -> size) {
        postOrderTraversal(hp, RCHILD(i));
    }
}

/*
    Function to display all the nodes in the max heap
*/
void levelOrderTraversal(maxHeap *hp) {
    int i;
    for(i = 0; i < hp -> size; i++) {
        printf("%d ", hp -> elem[i].data);
    }
}


void printArray(int *arr, size_t len){
    int i;
    for (i=0; i < len; i++)
    printf("%d ", arr[i]);
    printf("\n");
}


int main(){
    int array[] = {1,2,3,7,4,0,-1};
    size_t len = sizeof(array)/sizeof(array[0]);

    printf("The origianal array is: ");
    printArray(array, len);

    maxHeap hp = initMaxHeap(len);
    maxHeap *root = &hp;

    buildMaxHeap(root, array, len);
    printf("postorder traversal: ");
    postOrderTraversal(root,0);
    printf("\n");

    printf("minimum of node 0 is %d\n",getMinNode(root, 0));
    printf("minimum of node 1 is %d\n",getMinNode(root, 1));
    printf("minimum of node 2 is %d\n",getMinNode(root, 2));


    getMinNode(root, 0);
    printf("\n");
    deleteNode(root);

    getMinNode(root, 0);
    printf("\n");
    deleteNode(root);
    getMinNode(root, 0);
    printf("\n");
    deleteNode(root);



    deleteMaxHeap(root);

    return 0;
}

/**
 * 一个数组
 * 一个大顶堆，（堆由一组指针组成，每个指针指向数组元素）
 *  A function -buildMaxHeap to arrange the elements in the heap
 * tricky part is: 1 dyanmic array, 2 pointer to maxheap
 **/
