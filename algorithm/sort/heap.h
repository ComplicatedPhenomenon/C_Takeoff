// node index
#define LEFTCHILD(x) 2 * x + 1
#define RIGHTCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2


// structure of a complete binary tree
typedef struct{
    int data;
    struct maxHeap *leftchild;
    struct maxHeap *rightchild;
}CBTnode;

typedef struct{
    CBTnode * node[x];
}maxHeap;

int *Heapify(int * arr){
    maxHeap * mH;
    for(int i = 0; i < len(sizeof(arr); ++i) mH->node[i] = arr[i];


}
