#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
/* structures in C, cannot have functions, they can have pointers to functions*/
struct PERSON{
	char *name;
	int    age;
	int   height;
	int   weight;
	void (*print)(struct PERSON *self);
	void(*destroy)(struct PERSON *self);

} ;


typedef struct PERSON person;

void person_print(person* who)
{
	printf("Name: %s\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);
}

void person_destroy(person *who)
{
	assert(who != NULL);

	free(who->name);
//	free(who->age);
	free(who);
	}

person *person_create(char *name, int age, int height, int weight)
{
        person *who = malloc(sizeof(person));
	assert(who != NULL);
        /* who->name is the short version of (*who).name */
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight=weight;
	who->print=&person_print;
	who->destroy=&person_destroy;

	return who;
	}


int main(int argc, char *argv[])
{
        person *joe = person_create("Joe Alex", 32, 64, 140);
	person_print(joe);                /*calling the print function directly */

	/*Declaration is void (*print)(struct PERSON *self);. Type is void (*)(struct PERSON*). It expects a pointer to struct PERSON*/
        joe->print(joe);

	joe->destroy(joe);
        joe->print(joe);

	return 0;
}
