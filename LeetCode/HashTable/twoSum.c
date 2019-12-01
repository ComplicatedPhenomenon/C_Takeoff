/**
 * source: https://leetcode.com/problems/two-sum/
 * 
 * Given an array of integers, return indices of the two numbers
 * such that they add up to a specific target.
 * 
 * key idea:
 *  keys store the value-related thing from original array
 *  values store the index of the element leading this thing
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 50000

int hash(int key) {
    int r = key % SIZE;
    return r < 0 ? r + SIZE : r;
}

void insert(int *keys, int *values, int key, int value) {
    int index = hash(key);
    while (values[index] != 0) {
        index = (index + 1) % SIZE;
    }
    keys[index] = key;
    values[index] = value;
}

int search(int *keys, int *values, int key) {
    int index = hash(key);
    while (values[index] != 0) {
        if (keys[index] == key) {
            return values[index];
        }
        index = (index + 1) % SIZE;
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target) {
    int keys[SIZE];
    int values[SIZE] = {0};
    for (int i = 0; i < numsSize; i++) {
        int complements = target - nums[i];
        int value = search(keys, values, complements);
        if (value != 0) { // find the index of this complements 
            int *indices = (int *) malloc(sizeof(int) * 2);
            indices[0] = value - 1;
            indices[1] = i;
            return indices;
        }
        // i+1 is to exclude the index 0 as the array values was initialized as zero
        insert(keys, values, nums[i], i + 1);
    }
    return NULL;
}


int main(){
    int nums[] = {0 , 9, -5, 2, 14, 7, 11, 15};
    int len = sizeof(nums)/sizeof(nums[0]);
    int *res = twoSum(nums, len, 9);
    for(int i = 0; i < 2; i++) printf("%d\n", res[i]);
    free(res);
    
    return 0;
}