```c
int arr[] = {6, 3, 2, 3, 4, 5};
size_t n = sizeof(arr)/sizeof(arr[0]);
int *ascendingArray;
ascendingArray = bubbleSort(arr, n); //Why is n necessary?
```
Because `arr` as a pointer only store the address of the array.

* https://www.hackerearth.com/practice/algorithms/sorting
