#include<stdio.h>

int main(int mw, char *wm[]){
/* mainly is main function, so argc *argv[] can be replaced */

    int ages[] = {28, 43, 12, 89, 2};
    char * names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};

    int count = sizeof (ages) / sizeof(int);
    int i;
    printf("First way-using indexing\n");
    for(i = 0; i < count ; i++){
        printf("%s is %d years old.\n", names[i],ages[i]);
    }

    printf("_________________________\n");

    int *cur_age = ages;
    char ** cur_name = names;
    printf("Second way-using pointers\n");
    for(i = 0; i < count; i++){
        printf("%s is %d years old\n",*(cur_name+i),*(cur_age+i));
    }
    printf("_________________________\n");

    printf("Third way-Pointers are just arrays\n");
    for(i = 0; i < count; i++){
         printf("%s is %d years old\n", cur_name[i], cur_age[i]);
    }
    printf("_________________________\n");


    return 0;
}
