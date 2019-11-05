#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char country[20];
    char city[20];
    char school[30];
}place;

void print(place A);
void input(place A);
void fprint(FILE *f, place A);

int main(){
    place A;

    //Avoid assignment to expression with array type when initialize A
    strcpy(A.country,"UK");
    strcpy(A.city,"Cambridge");
    strcpy(A.school,"Cambridge University");

    //Initialize B
    place B = {"US", "New Jersy", "Princeton University"};
    place C;
    FILE *f = fopen("file.txt","w");
    if (f == NULL){
	    printf("Error opening file!\n");
	    exit(1);
    }

    fprintf(f,"%s","hello, WM\n");
    //fprint(FILE *f, place A);
    fclose(f);
    print(A);
    print(B);
    input(C);

    return 0;
}

void print(place A){
  printf("%s\n",A.country);
  printf("%s\n",A.city);
  printf("%s\n",A.school);
}

void fprint(FILE *f, place A){
  fprintf(f,"%s\n",A.country);
  fprintf(f,"%s\n",A.city);
  fprintf(f,"%s\n",A.school);
}
/*scanf is still a problem! if you input two or more strings, only one can be saved*/
void input(place A){
  scanf("%s", A.country);
  scanf("%s", A.city);
  scanf("%s", A.school);
  printf("you have input a struct, including: \n");
  printf("%s\n", A.country);
  printf("%s\n", A.city);
  printf("%s\n", A.school);
}

/*-------------------------------------------
 * what you do is undefined behaviour is a
 * very common problem for a beginner, so
 * it's unfair to say programming is diiffcult
 * ----------------------------------------*/
