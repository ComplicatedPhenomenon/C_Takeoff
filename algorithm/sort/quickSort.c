/**
 *  https://www.youtube.com/watch?v=Hoixgm4-P4M
 *  https://www.c-programming-simple-steps.com/return-statement.html
 **/


// Quick sort algorithm is recursive.

// find pivot position.


srand(time(NULL));
size_t n = sizeof(array)/sizeof(array[0]);
int x = rand()%n;
swap( array[0], array[x]);
int left = 0;
int right = n-1;
while(left<right){
    
}


void swap(int *p1, int*p2){
    tmp = p1; // assign the address p1 contains to tmp
    p1 = p2;
    p2 = tmp;
    return; //Returning control from function that does not return value:
}  // what happened between compile time and runtime
