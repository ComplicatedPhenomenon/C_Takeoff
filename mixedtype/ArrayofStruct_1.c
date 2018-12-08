#include<stdio.h>
#include<stdlib.h>
#define m 10
#define n 21

typedef struct{
    double position[m];
    double velocity[m];
    double accleration[m];
    double mass;
}body;

body A[n];

int main(){
    int i, j;
    body B[n];

    for(i = 0; i < n; i++){
	      for(j = 0; j < m; j++){
	          A[i].position[j] = i/11;
	          A[i].velocity[j] = i/3;
            A[i].position[j] = i/7;
	          A[i].mass = 12+i;
	      }
    }

    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
  	    B[i].position[j] = i/11.1;
  	    B[i].velocity[j] = i/3.1;
  	    B[i].position[j] = i/7.1;
  	    B[i].mass = i;
    	}
    }

    FILE *f = fopen("file.txt","w");
    if (f == NULL){
       	printf("Error opening file!\n");
	      exit(1);
    }

    for(i = 0; i < n; i++){
    	  for(j = 0; j < m; j++){
	      fprintf(f,"%f\n%f\n%f\n%f\n\n\n",A[i].position[j], A[i].velocity[j], A[i].position[j], A[i].mass);
        }
    }

    fclose(f);
}
/**
#include<stdlib.h>
#include<time.h>

int *getRandom()
{
    static int r[10];
    int i;

    srand( (unsigned)time( NULL));
    for (i=0; i < 10; ++i){
      r[i] = rand();
      printf("r[%d] = %d\n", i, r[i]);
    }
    for(i = 0; i < 2; i++){
       	for(j = 0; j < 3; j++){
	    printf("%f\n%f\n%f\n%f\n\n\n",B[i].position[j], B[i].velocity[j], B[i].position[j], B[i].mass);
      	}
    }

    return 0;
}
*/
/********************************************************************
 * 1. Global variable A and Local variable B, What's the diffierence
 * between them?
 * 2. computation among diffirent data type
 ********************************************************************/
