#include<stdio.h>

int main(){

	int n[10];
	int i;

	for (i = 0; i < 10; i++){
	    n[i] = i + 100;
	}
	
	for (i = 0; i < 10; i++){
	    printf("Elements[%d] = %d\n", i, n[i]);
	}

	return 0;
}

