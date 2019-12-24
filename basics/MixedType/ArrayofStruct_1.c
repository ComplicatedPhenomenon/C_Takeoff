#include<stdio.h>
#include<stdlib.h>
#define m 10
#define n 21

typedef struct{
    float position[m];
    float velocity[m];
    float acceleration[m];
    float mass;
}body;

int main(){
    int i, j;
    body A[n], B[n];

    for(i = 0; i < n; i++){
	    for(j = 0; j < m; j++){
	        A[i].position[j] = i/11;
	        A[i].velocity[j] = i/3;
            A[i].acceleration[j] = i/7;
	    }
        A[i].mass = 12+i;
    }

    FILE *f = fopen("file.txt","w");
    if (f == NULL) {
       	printf("Error opening file!\n");
	    exit(1);
    }

    for(i = 0; i < n; i++){
    	for(j = 0; j < m; j++){
	    fprintf(f,"%f\n%f\n%f\n%f\n\n\n",\
                A[i].position[j], A[i].velocity[j], \
                A[i].acceleration[j], A[i].mass);
        }
    }

    fclose(f);
    return 0;
}

