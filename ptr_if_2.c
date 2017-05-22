#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char country[20];
  char city[20];
  char school[20];
}place;

void print(place A);
void input(place A);

int main(){
place A[100];

//Avoid assignment to expression with array type when initialize A
strcpy(A[1].country,"UK");
strcpy(A[1].city,"Cambridge");
strcpy(A[1].school,"Cambridge University");

//Initialize B
place B = {"US", "New Jersy", "Princeton University"};
place C;
FILE *f = fopen("file.txt","w");
if (f == NULL){
  printf("Error opening file!\n");
  exit(1);
}
fprintf(f,"%s",print(A));
fclose(f);
print(A[1]);
print(B);
input(C);
printf("%s","You have input :\n");
return 0;
}

void print(place A){
printf("%s\n",A.country);
printf("%s\n",A.city);
printf("%s\n",A.school);
}


void input(place A){
scanf("%s",A.country);
scanf("%s",A.city);
scanf("%s",A.school);
}
