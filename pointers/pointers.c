#include<stdio.h>

int main(){
	int var1;
	char var2[] = "complicatephenomenon";
	int i;
	char me[31];

	printf("What's your name?\n");
	scanf("%s",me);
	printf("It's good to see you, %s\n",me);
	printf("------------------------------\n");
	printf("%lu\n",sizeof var2);
	printf("%s\n",var2);

	for(i=0; i < 20; i++){
		printf("var[%d]=%c\n",i,var2[i]);
	}
	for(i=0; i < 20; i++){
		printf("Address of var[%d] is: %x\n",i,var2[i]);
	}
	printf("Address of var1 variable: %x\n", &var1);
	printf("Var2 = %s\n", var2);

	return 0;
}


/* what do you want from this code? */
/* I define two variables one integer the other is an Array */
/* I am trying to figure out the pointers in this section , so first I just print out the address of each variable."*/
/* Do you know how to initialize the array?*/
