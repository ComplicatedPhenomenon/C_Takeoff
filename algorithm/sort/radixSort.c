#include<stdio.h>

void countsort(int arr[],int n,int place) {
    int i,freq[10]={0};         //range for integers is 10 as digits range from 0-9
    int output[n];
    for(i = 0; i < n; i++) freq[(arr[i] / place) % range]++;
    for(i = 1; i < range; i++) freq[i] += freq[i-1];
    for(i = n-1; i >= 0; i--) {
        output[freq[(arr[i] / place) % range]-1] = arr[i];
        freq[(arr[i] / place) % range]--;
    }
    for(i = 0; i < n; i++) arr[i] = output[i];
}
void radixSort(int arr[],int n, int maxx) {
    int mul=1;
    while(maxx) {
        countsort(arr,n,mul);
        mul*=10;
        maxx/=10;
    }
}

int main() {
    int arr[] = {9, 1 , 3, 12, 8, 0, 6, 2, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int i;
    int maxOfA = arr[0];
    
    for(int i = 1; i < n; i++){
        maxOfA = maxOfA > arr[i]? maxOfA : arr[i];
    }

    printf("Original arr is:");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    radixSort(arr, n, maxOfA);

    printf("Original arr after sorting is: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0; 
}