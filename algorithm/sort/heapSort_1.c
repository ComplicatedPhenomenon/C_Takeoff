/**
 * The key part is how the data is stored in memory, what's the connection between heap and array
 **/

#include <stdio.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2
/*
int heapify(int *a, int len, int index){
    int tem;
    if (LCHILD(index) > len - 1) return 0; // do nothing when root node has no child

    else if(LCHILD(index) == len-1){      // only compare the root node with its left child.
        if(a[index]<a[LCHILD(index)]){
            tem=a[index];
            a[index]=a[LCHILD(index)];
            a[LCHILD(index)]=tem;
        }
        return 0;
    }

    else{                                 // compare the root node with its left child and right child.
        if (a[index] < a[LCHILD(index)] || a[index] < a[RCHILD(index)]){
            if (a[LCHILD(index)]<a[RCHILD(index)]) {
                tem=a[index];
                a[index]=a[RCHILD(index)];
                a[RCHILD(index)]=tem;
                heapify(a,len,RCHILD(index));
            }
            else{
                tem=a[index];
                a[index]=a[LCHILD(index)];
                a[LCHILD(index)]=tem;
                heapify(a,len,LCHILD(index));
            }
        }
        return 0;
    }
}
*/


// left is existed for sure, right is not sure
void heapify(int *a, int len, int index){
    int largest;
    int tem;
    largest = LCHILD(index) < len && a[LCHILD(index)] > a[index] ? LCHILD(index): index;
    largest = RCHILD(index) < len && a[RCHILD(index)] > a[largest] ? RCHILD(index) : largest;
    if (largest!= index){
        tem = a[index];
        a[index] = a[largest];
        a[largest] = tem;
        heapify(a, len, largest);
    }
}

/*
int build_heap(int *a,int len){
    int i;
    for (i = len - 1; i >= 0; i--) {
        if(LCHILD(i) > len - 1) continue;
        //  i is now the root of element indexed as len-1
        heapify(a,len,i);
    }
    return 0;
}
*/

int build_heap(int *a,int len){
    int i;
    for (i = PARENT(len - 1); i >= 0; i--) {
        heapify(a,len,i);
    }
    return 0;
}

int heapsort(int *a,int len){
    build_heap(a,len);
    int tem;
    int newlen=len;
    while(newlen>1){
        //swap head with last
        tem=a[0];
        a[0]=a[newlen-1];
        a[newlen-1]=tem;
        newlen--;
        heapify(a,newlen,0);
    }
    return 0;
}

int main(){
    int a[10]={2,1,4,7,5,8,9,20,0,3};
    int len=10;
    heapsort(a, len);
    int i;
    for (i = 0; i < len; i++) printf("%d\t",a[i]);
    printf("\n");

    return 0;
}
