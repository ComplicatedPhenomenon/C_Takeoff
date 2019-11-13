//source: https://leetcode.com/problems/container-with-most-water/

#include<stdio.h>
int maxArea(int* height, int heightSize){
    int start = 0;
    int end = heightSize-1;
    int res  = 0, area = 0, minBetween2 = 0;

    while(start < end){
        minBetween2 = (height[end] > height[start]? height[start] : height[end]);
        area = (end - start) * minBetween2;
        res = ( area > res? area  : res);
        //printf("end = %d, start = %d, area = %d, res=%d\n", end, start, area, res);
        if (height[end] > height[start])++start;
        else end--;
        //printf("%d\n", res);
    }
    return res;
}

int main(){
    int height[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(height)/sizeof(height[0]);

    int res = maxArea(height, size);
    printf("%d\n", res);

    return 0;

}
