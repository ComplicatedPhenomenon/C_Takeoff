/**
 * The key part is how the data is stored in memory, what's the connection between heap and array
 **/

#include <stdio.h>

#define LEFTCHILD(x) 2 * x + 1
#define RIGHTCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

int heapify(int *a, int len, int index){
    int tem;
    if (LEFTCHILD(index) > len - 1) return 0;

    else if(LEFTCHILD(index) == len-1){
        if(a[index]<a[LEFTCHILD(index)]){
            tem=a[index];
            a[index]=a[LEFTCHILD(index)];
            a[LEFTCHILD(index)]=tem;
        }
        return 0;
    }

    else{
        if (a[index] < a[LEFTCHILD(index)] || a[index] < a[RIGHTCHILD(index)]){
            if (a[LEFTCHILD(index)]<a[RIGHTCHILD(index)]) {
                tem=a[index];
                a[index]=a[RIGHTCHILD(index)];
                a[RIGHTCHILD(index)]=tem;
                heapify(a,len,RIGHTCHILD(index));
            }
            else{
                tem=a[index];
                a[index]=a[LEFTCHILD(index)];
                a[LEFTCHILD(index)]=tem;
                heapify(a,len,LEFTCHILD(index));
            }
        }
        return 0;
    }
}


int build_heap(int *a,int len){
    int i;
    for (i = len - 1; i >= 0; i--) {
        if(LEFTCHILD(i) > len - 1) continue;
        //  i is now the root of element indexed as len-1
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
