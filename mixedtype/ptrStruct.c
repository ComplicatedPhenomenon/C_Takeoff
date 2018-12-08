#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>



int main(){
    char answer[60];
    char *ptr;

    if (!ptr){
       	printf("CAUTION: The pointer is uninitialized\n");
    }

    if (ptr != NULL){
	      printf("what happened to the pointer?\n");
    }

    printf("--||To live or to die||--\n");
    printf("Type 'live' to start the journey or 'die' to exit\n");
    scanf("%s", answer);

    if(!strcmp(answer, "live")){
       	printf("Well done!\n");
	      printf("The condition is = %s in a fancy way\n",!strcmp(answer,"live")?"true":"false");
	      printf("The condition is = %d\n",!strcmp(answer,"live"));
	      /*There is no specifier for bool*/
	      sleep(3);

	      return 0;
    }

    if(!strcmp(answer, "die")){
	     system("exit");
    }
    else
       	printf("You despite popular belief\n");

    return 0;
}
