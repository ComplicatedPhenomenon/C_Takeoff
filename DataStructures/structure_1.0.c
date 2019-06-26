/*Still need to be fixed*/
#include<stdio.h>
#include<string.h>

struct book {
    char name[30];
    char author[31];
    char subject[30];
    int  units;
};

struct bookx {
    char *name;
    char *author;
    char *subject;
    int  units;
};

struct people {
    char name[30];
    char disease[30];
    int  age;
    char description[300];
};

int main(){
    struct book book1;
    /*struct bookx book2;*/
    struct bookx *book3;
    struct people wm;
    strcpy(book1.name, "learn python the hard way");
    strcpy(book1.author, "Zed A. Shaw");
    strcpy(book1.subject,"tutorial for a beginner");
    book1.units = 42;

    //*book3->name = "learn python the hard way";

    /*strcpy(book2.name, "learn python the hard way");
    strcpy(book2.author, "Zed A. Shaw");
    strcpy(book2.subject,"tutorial for a beginner");
    book2.units = 42;*/

    strcpy(wm.name, "Brilliant guy");
    strcpy(wm.disease, "depression");
    strcpy(wm.description, "I have heard that a low or depressed mood can incrase an individual's ability to cope with situations in which the effort to pursue a major goal could result in danger, loss, or wasted effort. and I'm suffering from mood disorder.");
    wm.age = 25;
    printf("The book1 <%s> is written by %s,\n %s, It has %d units,\n", book1.name,book1.author,book1.subject,book1.units);
    //printf("The book2 <%s> is written by %s,\n %s, It has %d units,\n", book2.name,book2.author,book2.subject,book2.units);
    printf("I am %s, %d years old,\n I feel I have got %s,\n %s\n", wm.name, wm.age, wm.disease, wm.description);

    return 0;
}
