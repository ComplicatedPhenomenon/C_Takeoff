def heapify(intList, heap_size, root_index):  
    # Assume the index of the largest element is the root index
    largest = root_index
    left_child = (2 * root_index) + 1
    right_child = (2 * root_index) + 2

    # If the left child of the root is a valid index, and the element is greater
    # than the current largest element, then update the largest element
    if left_child < heap_size and intList[left_child] > intList[largest]:
        largest = left_child

    # Do the same for the right child of the root
    if right_child < heap_size and intList[right_child] > intList[largest]:
        largest = right_child

    # If the largest element is no longer the root element, swap them
    if largest != root_index:
        intList[root_index], intList[largest] = intList[largest], intList[root_index]
        # Heapify the new root element to ensure it's the largest
        # After the swap, make sure the node has been replaced by a new value fit the rule of a heap 
        heapify(intList, heap_size, largest)


def heap_sort(intList):  
    n = len(intList)

    # Create a Max Heap from the list, intList.
    for i in range(n, -1, -1):
        heapify(intList, n, i)

    # Move the root of the max heap to the end of the list 
    for i in range(n - 1, 0, -1):
        intList[i], intList[0] = intList[0], intList[i]
        heapify(intList, i, 0)


# Verify it works
random_list_of_nums = [35, 4, 35, 67, 9, 12, 43, 8, 51]  
heap_sort(random_list_of_nums)  
print(random_list_of_nums)