#include<stdio.h>
#include<string.h>

int main(){
  int i;
  char Pixar[3]={'s', 'o' , 's'};
  char *pta;
  char Disney[10];

  pta = &Pixar[0];
  memcpy(Disney, (char[]) {'D', 'i','s','n','e','y','l','a','n','d'}, sizeof(Disney));

  printf("We have declare an array named Pixar, let's see what's in Pixar.\n");
  for(i = 0; i < sizeof(Pixar); i++){
    printf("Pixar[%d] = %c\n",i, Pixar[i]);
    printf("*(Pixar+%d) = %c\n",i, *(Pixar + i));/* array decay into pointer */
    printf("&(Pixar[%d]) = %p\n",i, &(Pixar[i]));
    printf("*(pta+%d)   = %c\n",i, *(pta+i));
    /* what about *pta+i ?*/
    printf("pta[%d]   = %c\n",i, pta[i]);
  }
    printf("What about Disney?\n");
  for(i = 0; i < 10; i++){
    printf("Disney[%d]=%c\n",i,Disney[i]);
    printf("*(Disney+%d)=%c\n",i,*(Disney+i));
  }
  return 0;
}

