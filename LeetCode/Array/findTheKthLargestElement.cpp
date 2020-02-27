// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
#include<iostream> 
#include<climits> 
using namespace std; 


void swap(int *x, int *y); 

class MinHeap { 
	int *harr; // pointer to array of elements in heap 
	int capacity; // maximum possible size of min heap 
	int heap_size; // Current number of elements in min heap 
public: 
	MinHeap(int a[], int size); /// constructor. No return type.
	void MinHeapify(int i); //To minheapify subtree rooted with index i 
	int parent(int i) { return (i-1)/2; } 
	int left(int i) { return (2*i + 1); } 
	int right(int i) { return (2*i + 2); } 

	int extractMin(); // extracts root 
	int getMin() { return harr[0]; } // Returns minimum 
}; 

MinHeap::MinHeap(int a[], int size) { 
	heap_size = size; 
	harr = a; // store address of array 
	int i = (heap_size - 1)/2; 
	while (i >= 0) { 
		MinHeapify(i); 
		i--; 
	} 
} 

// Method to remove minimum element from min heap 
int MinHeap::extractMin() { 
	if (heap_size == 0) 
		return INT_MAX;  // ?
	int root = harr[0]; 
	if (heap_size > 1) { 
		harr[0] = harr[heap_size-1]; 
		MinHeapify(0); 
	} 
	heap_size--; 

	return root; 
} 

void MinHeap::MinHeapify(int i) { 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && harr[l] < harr[i]) 
		smallest = l; 
	if (r < heap_size && harr[r] < harr[smallest]) 
		smallest = r; 
	if (smallest != i) { 
		swap(&harr[i], &harr[smallest]); 
		MinHeapify(smallest); 
	} 
} 

void swap(int *x, int *y) { 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 


int kthSmallest(int arr[], int n, int k) { 
	// Build a heap of n elements: O(n) time 
	MinHeap minHeap(arr, n); 
	// Do extract min (k-1) times 
	for (int i = 0; i < k - 1; i++) 
		minHeap.extractMin(); 

	// Return root 
	return minHeap.getMin(); 
} 

int main() { 
	int arr[] = {12, 3, 5, 7, 19}; 
	int n = sizeof(arr)/sizeof(arr[0]), k = 2; 
	cout << "Kth smallest element is " << kthSmallest(arr, n, k); 
	cout << endl;
	return 0; 
} 


/**
 *  why constructors have no return type?
 **/