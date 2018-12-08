#include<stdio.h>
#include<stdlib.h>
#define m 10
#define n 21

typedef struct{
    double position[m];
    double velocity[m];
    double accleration[m];
    double mass;
} body;

typedef enum{
    Lorentz_T, Poincare_T, SO_T
} group;

body A[n];
group transformation_type;

int main(){
    int i, j;
    transformation_type = SO_T;
    printf("trnasformation type is %d\n",transformation_type);
    FILE *f = fopen("file.txt","w");

    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
	          A[i].position[j] = i/11;
	          A[i].velocity[j] = i/3;
	          A[i].position[j] = i/7;
	          A[i].mass = 12+i;
       	}
    }

    for(i = 0; i < n; i++){
       	for(j = 0; j < m; j++){
	    fprintf(f,"%f\n%f\n%f\n%f\n\n\n",A[i].position[j], A[i].velocity[j], A[i].position[j], A[i].mass);
	}
    }

    fclose(f);
  return 0;
}


/**********************************************************
 *  First A is an array consisted of n elements
 *  Every element has a body type described by
 *  four differnt characters
 **********************************************************/
