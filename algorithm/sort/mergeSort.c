/**
 * a = a % b + a / b * b
 * Time complexity O(Nlog(N)))
 **/
#include <stdio.h>
#define max 10

int a[11] = {10, 1, 9, 6, 17, 11, 13, 5, 12, 14, 0 };
int b[10]; // Extra space stack

void merging(int low, int mid, int high) {
    int i1, i2, i;
    int tem;

    printf("Low is: ");
    for(tem = 0; tem <= mid; ++tem) printf("%d ", a[tem]);
    printf("\n");
    printf("High is: ");
    for(tem = mid+1; tem <= high; ++tem) printf("%d ", a[tem]);
    printf("\n");

    for(i1 = low, i2 = mid + 1, i = low; i1 <= mid && i2 <= high; i++) {
        b[i] = a[i1] <= a[i2] ?  a[i1++] : a[i2++];
    }
    
    while(i1 <= mid) b[i++] = a[i1++];
    while(i2 <= high)b[i++] = a[i2++];

    for(i = low; i <= high; i++) a[i] = b[i];

    printf("b is : ");
    for(i = 0; i < max; i++)printf("%d ", b[i]);
    printf("\n");

    printf("a is : ");
    for(i = 0; i <= max; i++)printf("%d ", a[i]);
    printf("\n");

}

void sort(int low, int high) {
    int mid;
    int tem;
    if(low < high) {
        mid = (low + high) / 2;

        // For the purpose of debugging.
        /*
        printf("low = %d, mid = %d, high = %d\n", low, mid, high);

        printf("Low is: ");
        for(tem = 0; tem <= mid; ++tem) printf("%d ", a[tem]);
        printf("\n");
        printf("High is: ");
        for(tem = mid+1; tem <= high; ++tem) printf("%d ", a[tem]);
        printf("\n");
        */

        printf("xxxx-----   sort(%d, %d)  -----xxxx\n", low, mid);
        sort(low, mid);
        printf("xxxx-----   sort(%d, %d)  -----xxxx\n", mid+1, high);
        sort(mid+1, high);
        printf("xxxx-----   merging(%d, %d, %d)  ------xxxx\n", low, mid, high);
        merging(low, mid, high);
    } else {
        return;
    }
}

int main() {
    int i;

    printf("List before sorting\n");
    for(i = 0; i <= max; i++)printf("%d ", a[i]);
    printf("\n");

    sort(0, max);

    printf("\nList after sorting\n");
    for(i = 0; i <= max; i++)printf("%d ", a[i]);
    printf("\n");
    return 0;
}
