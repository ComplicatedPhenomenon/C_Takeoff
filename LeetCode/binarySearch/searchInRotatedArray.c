#include <stdio.h>
int search(int* nums, int numsSize, int target){
    int l = 0;
    int r = numsSize -1;
    int mid;

    while (l <= r){
        mid = l + (r - l) / 2;
        if (nums[mid]  == target) return mid;

        // left side is in sorting order
        if (nums[l] <= nums[mid]){
            if (nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else{
            if (nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }


    }
    return -1;
}

int main(){
    int nums[] = {5, 1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", search(nums, numsSize, 3));
    return 0;
}
