/**
 *   Modified Date: 9/12/2018
 *   Description:
 **/

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
/* In C, you cannot have functions inside of structs*/
struct PERSON{
	char *name;
    int    age;
    int   height;
    int   weight;
    void (*print)(struct PERSON *self);
    void(*destroy)(struct PERSON *self);
};


typedef struct PERSON person;
/**
 * C programming allows passing a pointer to a function. To do so, simply
 * declare the function parameter as a pointer type.
 **/
void person_print(person* who){
    printf("Name: %s\n", who->name);
    printf("Age: %d\n", who->age);
    printf("Height: %d\n", who->height);
    printf("Weight: %d\n", who->weight);
}

void person_destroy(person *who){
    assert(who != NULL);
    free(who->name);
    free(who);
}

person *person_create(char *name, int age, int height, int weight)
{
	person *who = malloc(sizeof(person));
    assert(who != NULL);
	// who->name is the short version of (*who).name
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight=weight;
    who->print=&person_print;
    who->destroy=&person_destroy;

    return who;
}


int main(int argc, char *argv[]){
    person *joe = person_create("Joe Alex", 32, 64, 140);
    printf("Access the information of the object directly\n");
    printf("joe->name : %s\n", joe->name);
	printf("(*joe).name : %s\n",(*joe).name);
    printf("joe->age : %d\n",joe->age);
    printf("joe->height : %d\n",joe->height);
    printf("joe->weight : %d\n",joe->weight);
    printf("Access the information of the object through joe->print(joe)\n");
	joe->print(joe);  // It is different from OOP in Python

	/**
	 * Declaration of method of object person is
	 * void (*print)(struct PERSON *self);
	 * When you call this method, It expects an argument.
	 **/
	printf("Access the information of the object through person_print(joe)\n");
    person_print(joe);
    joe->destroy(joe);
	joe->print(joe); // To make sure joe has been destroyed

    return 0;
}

/**
 * Sophisticated part
 * printf("%c\n",*(joe->name))
 * joe->method_name(joe)
 **/
