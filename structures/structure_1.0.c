#include<stdio.h>
#include<string.h>

struct book {
    char name[30];
    char author[31];
    char subject[30];
    int  units;
};
struct people {
    char name[30];
    char disease[30];
    int  age;
    char description[300];
};
/*------------------------------------------------------------*/
/*        sturct is a derived data type, so is array          */
/*------------------------------------------------------------*/
int main(){

    /*  access the element in struct */
    struct book book1;
    struct people wm;
    strcpy(book1.name,"learn python the hard way");
    /* whitespace is a character too */
    strcpy(book1.author, "Zed A. Shaw");
    strcpy(book1.subject,"tutorial for a beginner");
    /* "()" not "{}" is followed by function "*/
    book1.units = 42;
    /*-------------------------------------------------------------*
     *  In an interactive programm, we get the required            *
     *  arguments from keyboard input                              *
     *-------------------------------------------------------------*/
    strcpy(wm.name, "wang maio");
    strcpy(wm.disease, "depression");
    strcpy(wm.description, "I have heard that a low or depressed mood can incrase an individual's ability to cope with situations in which the effort to pursue a major goal could result in danger, loss, or wasted effort. and I'm suffering from mood disorder.");
    wm.age = 25;
    printf("The book <%s> is written by %s,\n %s, It has %d units,\n", book1.name,book1.author,book1.subject,book1.units);
    printf("I am %s, %d years old,\n I feel I have got %s,\n %s\n", wm.name, wm.age, wm.disease, wm.description);
	
    return 0;
}
