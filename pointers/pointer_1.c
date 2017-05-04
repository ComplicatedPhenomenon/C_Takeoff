#include<stdio.h>
#include<string.h>

int main(){
	int  i, var = 20, *ip;    /*actual variable declaration */
        char Pixar[3]={'s', 'o' , 's'}, *pta , Disney[10];
	ip = &var;       /*store address of var in pointer variable */
	pta = &Pixar[0];
	memcpy(Disney, (char[]) {'D', 'i','s','n','e','y','l','a','n','d'}, sizeof(Disney));

	printf("&var = %p\n", &var);
	printf("ip = %p\n", ip);
	printf("*ip = %d\n", *ip);
	
	printf("We have declare an array named Pixar, let's see what's in Pixar.\n");
	for(i = 0; i < sizeof(Pixar); i++){
		printf("Pixar[%d] = %c\n",i, Pixar[i]);
		printf("*pta+%d = %c\n",i, *pta+i);
		printf("pta[%d] = %c\n",i, pta[i]);
	}
	printf("What about Disney?\n");
	for(i = 0; i < 10; i++){
		printf("Disney[%d]=%c\n",i,Disney[i]);
	}

	return 0;
}

/* this program is an idea model of explaining what pointer really is */
