#include<stdio.h>
void binary(int array,int size,int target){
    int begin,end,mid;
    begin=0;
    end=size-1;
    mid=(begin+end)/2;

    while(begin<=end){
        if(array[mid]== target){
        printf("%d found at %d", target, mid+1);
        break;
        }
        else if(array[mid]<target){
            begin=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(begin+end)/2;
}
    if(begin>end)
        printf("Item doesn't exist");
}
int main(){
    int i,target,size,array[10];
    printf("Enter size of array:\n");
    scanf("%d",&size);
    printf("Enter elements in ascending order:\n");
    for(i=0;i<size;i++)
        scanf("%d",&array[i]);
    printf("Enter the element to search");
    scanf("%d",&target);
    void binary(array, size, target);
    return 0;
}
